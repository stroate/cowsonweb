static void monitor_sensors();
static int respond(char *);
static void sensor_data_request(char *target);
int data_post(const char *url, char *json, const char *hostname, const char *ip);
le_result_t go_online(le_mdc_ProfileRef_t);
static void handle(char *, int *count);