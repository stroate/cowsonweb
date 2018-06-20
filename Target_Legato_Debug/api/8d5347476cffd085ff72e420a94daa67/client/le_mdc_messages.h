/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef LE_MDC_MESSAGES_H_INCLUDE_GUARD
#define LE_MDC_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "f51d46d0916e8217f8268ebd7f42baa0"

#ifdef MK_TOOLS_BUILD
    extern const char** le_mdc_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*le_mdc_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "le_mdc"
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

#define _MSGID_le_mdc_AddSessionStateHandler 0
#define _MSGID_le_mdc_RemoveSessionStateHandler 1
#define _MSGID_le_mdc_AddMtPdpSessionStateHandler 2
#define _MSGID_le_mdc_RemoveMtPdpSessionStateHandler 3
#define _MSGID_le_mdc_GetProfile 4
#define _MSGID_le_mdc_GetProfileIndex 5
#define _MSGID_le_mdc_StartSession 6
#define _MSGID_le_mdc_StartSessionAsync 7
#define _MSGID_le_mdc_StopSession 8
#define _MSGID_le_mdc_StopSessionAsync 9
#define _MSGID_le_mdc_RejectMtPdpSession 10
#define _MSGID_le_mdc_GetSessionState 11
#define _MSGID_le_mdc_GetInterfaceName 12
#define _MSGID_le_mdc_GetIPv4Address 13
#define _MSGID_le_mdc_GetIPv4GatewayAddress 14
#define _MSGID_le_mdc_GetIPv4DNSAddresses 15
#define _MSGID_le_mdc_GetIPv6Address 16
#define _MSGID_le_mdc_GetIPv6GatewayAddress 17
#define _MSGID_le_mdc_GetIPv6DNSAddresses 18
#define _MSGID_le_mdc_IsIPv4 19
#define _MSGID_le_mdc_IsIPv6 20
#define _MSGID_le_mdc_GetDataBearerTechnology 21
#define _MSGID_le_mdc_GetBytesCounters 22
#define _MSGID_le_mdc_ResetBytesCounter 23
#define _MSGID_le_mdc_SetPDP 24
#define _MSGID_le_mdc_GetPDP 25
#define _MSGID_le_mdc_SetAPN 26
#define _MSGID_le_mdc_SetDefaultAPN 27
#define _MSGID_le_mdc_GetAPN 28
#define _MSGID_le_mdc_SetAuthentication 29
#define _MSGID_le_mdc_GetAuthentication 30
#define _MSGID_le_mdc_NumProfiles 31
#define _MSGID_le_mdc_GetProfileFromApn 32
#define _MSGID_le_mdc_GetDisconnectionReason 33
#define _MSGID_le_mdc_GetPlatformSpecificDisconnectionCode 34
#define _MSGID_le_mdc_GetPlatformSpecificFailureConnectionReason 35


#endif // LE_MDC_MESSAGES_H_INCLUDE_GUARD

