#include "legato.h"
#include "interfaces.h"
#include "curl/curl.h"
#include "COW.h"

#define SERIAL_PORTNAME	"/dev/ttyHS0"
#define DOWN_BUFFER_SIZE 3

struct temperature {
	char node_id[5];
	time_t utc;
	double degrees;
	double bat_v;
};

struct temperature buffer[DOWN_BUFFER_SIZE];
int fildes;

int make(struct temperature *, char *);
static int json_encode(struct temperature *, char *);

/*
 * Initializes serial port. Sets baud rate to 19200 bps,
 * no parity framing of 8 data bits and 1 stop bit,
 * sets flow control to hardware and port into raw (non-canonical mode).
 *
 * @return
 * 	- LE_OK if successful
 * 	- LE_FAULT if one or more options could not be set
 */
static int serial_port_init() {
	if (le_tty_SetBaudRate(fildes, LE_TTY_SPEED_19200) != LE_OK
			|| le_tty_SetFraming(fildes, 'N', 8, 1) != LE_OK
			|| le_tty_SetFlowControl(fildes, LE_TTY_FLOW_CONTROL_HARDWARE)
					!= LE_OK || le_tty_SetRaw(fildes, 0, 0) != LE_OK) {
		LE_WARN("Failed to correctly initialize serial port. "
				"Communication may not occur");
		return LE_FAULT;
	}
	return LE_OK;
}

COMPONENT_INIT {
	printf("CowsOnWeb²");

	fildes = le_tty_Open(SERIAL_PORTNAME, O_RDWR | O_NOCTTY | O_NDELAY);

	if (fildes != -1) {
		serial_port_init();
		curl_global_init(CURL_GLOBAL_ALL);

		monitor_sensors();
	}
}

static void monitor_sensors() {
	do {
		char data[1024];
		int size;

		size = read(fildes, data, sizeof(data));
		switch (size) {
		case -1:
			LE_CRIT("Oh dear, something went wrong with read()! %s\n",
					strerror(errno));
			le_tty_Close(fildes);
			exit(0);
		case 0:
			continue;
		default:
			LE_DEBUG("%d: %s", size, data);
			handle(data);
			break;
		}
	} while (1);
}

static void sensor_data_request(char *target) {
	char cmd[512];
	time_t unix_epoch = time(NULL);
	long int seconds = (long int) unix_epoch;

	sprintf(cmd, "%s=*TIM,%ld;\r", target, seconds);
	if (respond(cmd) == 0) {
		sprintf(cmd, "%s=*GPRS,0;\r", target);
		if (respond(cmd) == 0) {
			LE_INFO("Request accepted. Waiting for sensor data...");
		}
	}
}

/*
 * Writes a command to the serial port and waits
 * for response.
 *
 * @return
 *  - 0 if OK received
 *  - 1 if ERROR received
 */
static int respond(char *cmd) {
	char response[512];
	char *token;
	int size = 0;

	LE_DEBUG("Sending %s...", cmd);
	write(fildes, cmd, strlen(cmd));

	while (size == 0)
		size = read(fildes, response, sizeof(response));

	token = strtok(response, "\r");
	LE_DEBUG("Received %s", token);

	return strcmp(token, "OK");
}

static void handle(char *data) {
	char *token;
	char src[5];
	char *payload = NULL;

	struct temperature t;
	char *json = malloc(200);

	token = strtok(data, "=");
	strcpy(src, token);

	payload = strtok(NULL, ";");
	if (payload) {
		if (strcmp(payload, "*HB") == 0) {
			LE_INFO("Received greeting from %s", src);
			sensor_data_request(src);
		} else {
			struct temperature *temp;

			temp = (struct temperature *) malloc(sizeof(t));
			make(temp, payload);

			le_result_t status = gsm_connect(
					le_mdc_GetProfile(LE_MDC_DEFAULT_PROFILE));
			if (status == LE_OK || status == LE_DUPLICATE) {
				const char post_url[] = "cowsonweb.azurewebsites.net/api/AddTemperature?code=879AM4vr4eFS/LoCHVEmAnQvWI8fXKxVJe7/IkC1nJJqiakHQQnamw==";

				json_encode(temp, json);
				data_post(post_url, json, "cowsonweb.azurewebsites.net", "52.178.43.209");
				free(json);
			}
		}
	}
}

/*
 * Uses libcurl to post temperature data over HTTP.
 */
int data_post(const char *url, char *json, const char *hostname, const char *ip) {
	CURL *curl;
	CURLcode res;
	struct curl_slist *host = NULL;

	//TODO wait for timeout

	curl = curl_easy_init();
	if (curl) {
		if(hostname && ip) {
			char resolve[128];

			snprintf(resolve, 128, "%s:80:%s", hostname, ip);
			host = curl_slist_append(NULL, resolve);
			curl_easy_setopt(curl, CURLOPT_RESOLVE, host);
		}
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
		curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
		res = curl_easy_perform(curl);
		if (res == CURLE_OK) {
			LE_INFO("Yay! Temperature reached database");
		} else if (res == CURLE_HTTP_RETURNED_ERROR) {
			LE_ERROR("Server returned an HTTP status code <= 400. "
					"You might want to check post data!");
		} else {
			LE_ERROR("curl_easy_perform() did not so easily perform! %s",
					curl_easy_strerror(res));
		}

		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();

	return 0;
}

/*
 * Starts an active session when registered on the network.
 *
 * @return
 *  - LE_OK on success
 *  - LE_BAD_PARAMETER if input parameter is incorrect
 *  - LE_DUPLICATE if the data session is already connected for the given profile
 *  - LE_FAULT for other failures
 */
le_result_t gsm_connect(le_mdc_ProfileRef_t profile) {
	//le_mdc_ConState_t *con_state = NULL;
	le_cellnet_State_t *reg_state;
	le_cellnet_State_t unknown = LE_CELLNET_REG_UNKNOWN;
	reg_state = &unknown;

	//le_mdc_SetAuthentication(profile, LE_MDC_AUTH_NONE, NULL, NULL);

	le_cellnet_GetNetworkState(reg_state);
	if (*reg_state == LE_CELLNET_REG_HOME
			|| *reg_state == LE_CELLNET_REG_ROAMING) {
		/*le_mdc_GetSessionState(profile, con_state);
		 if (*con_state == LE_MDC_CONNECTED)
		 return LE_DUPLICATE;*/

		return le_mdc_StartSession(profile);
	}

	return LE_FAULT;
}

int make(struct temperature *to, char *from) {
	char *token;
	const char s[2] = ",";
	int count = 0;

	char *id = malloc(6);
	char params[10][24];

	token = strtok(from, s);
	strncpy(id, &token[4], 5);
	id[5] = '\0';
	while (token != NULL) {
		strcpy(params[count], token);
		token = strtok(NULL, s);
		count++;
	}

	strcpy(to->node_id, id);
	free(id);
	to->utc = (time_t) atol(params[2]);
	to->degrees = atof(params[3]);
	to->bat_v = atof(params[4]);

	return 0;
}

static int json_encode(struct temperature *temp, char *json) {
	static const double SENSOR_BAT_CAP = 3.6;
	char time[20];
	double percent;

	strcpy(json, "{");

	snprintf(json + strlen(json), 18, " \"cowid\":\"%s\",", temp->node_id);

	snprintf(json + strlen(json), 21, " \"temperature\":%f", temp->degrees);
	strcpy(json + strlen(json), ",");

	strftime(time, 20, "%Y-%m-%d %H:%M:%S", gmtime(&temp->utc));
	snprintf(json + strlen(json), 12 + strlen(time), " \"time\":\"%s\",", time);

	percent = temp->bat_v / SENSOR_BAT_CAP * 100;
	snprintf(json + strlen(json), 26, " \"batterypercentage\":%f", percent);

	strcpy(json + strlen(json), " }\0");

	LE_DEBUG("Encoded temperature to %s", json);

	return 0;
}
