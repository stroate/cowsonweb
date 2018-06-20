/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef LE_CELLNET_MESSAGES_H_INCLUDE_GUARD
#define LE_CELLNET_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "28ee3793c7145741ad3669e7839c7f8d"

#ifdef MK_TOOLS_BUILD
    extern const char** le_cellnet_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*le_cellnet_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "le_cellnet"
#endif


// todo: This will need to depend on the particular protocol, but the exact size is not easy to
//       calculate right now, so in the meantime, pick a reasonably large size.  Once interface
//       type support has been added, this will be replaced by a more appropriate size.
#define _MAX_MSG_SIZE 1100

// Define the message type for communicating between client and server
typedef struct
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;

#define _MSGID_le_cellnet_AddStateEventHandler 0
#define _MSGID_le_cellnet_RemoveStateEventHandler 1
#define _MSGID_le_cellnet_Request 2
#define _MSGID_le_cellnet_Release 3
#define _MSGID_le_cellnet_SetSimPinCode 4
#define _MSGID_le_cellnet_GetSimPinCode 5
#define _MSGID_le_cellnet_GetNetworkState 6


#endif // LE_CELLNET_MESSAGES_H_INCLUDE_GUARD

