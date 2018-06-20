/*
 * AUTO-GENERATED _componentMain.c for the COWComponent component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _COWComponent_le_cellnet_ServiceInstanceName;
const char** le_cellnet_ServiceInstanceNamePtr = &_COWComponent_le_cellnet_ServiceInstanceName;
void le_cellnet_ConnectService(void);
extern const char* _COWComponent_le_mrc_ServiceInstanceName;
const char** le_mrc_ServiceInstanceNamePtr = &_COWComponent_le_mrc_ServiceInstanceName;
void le_mrc_ConnectService(void);
extern const char* _COWComponent_le_mdc_ServiceInstanceName;
const char** le_mdc_ServiceInstanceNamePtr = &_COWComponent_le_mdc_ServiceInstanceName;
void le_mdc_ConnectService(void);
// Component log session variables.
le_log_SessionRef_t COWComponent_LogSession;
le_log_Level_t* COWComponent_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _COWComponent_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _COWComponent_Init(void)
{
    LE_DEBUG("Initializing COWComponent component library.");

    // Connect client-side IPC interfaces.
    le_cellnet_ConnectService();
    le_mrc_ConnectService();
    le_mdc_ConnectService();

    // Register the component with the Log Daemon.
    COWComponent_LogSession = log_RegComponent("COWComponent", &COWComponent_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_COWComponent_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
