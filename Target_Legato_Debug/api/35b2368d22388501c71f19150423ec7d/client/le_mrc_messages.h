/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef LE_MRC_MESSAGES_H_INCLUDE_GUARD
#define LE_MRC_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "74bd62afd4fc83a23e68a6e7230749f7"

#ifdef MK_TOOLS_BUILD
    extern const char** le_mrc_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*le_mrc_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "le_mrc"
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

#define _MSGID_le_mrc_AddNetRegStateEventHandler 0
#define _MSGID_le_mrc_RemoveNetRegStateEventHandler 1
#define _MSGID_le_mrc_AddRatChangeHandler 2
#define _MSGID_le_mrc_RemoveRatChangeHandler 3
#define _MSGID_le_mrc_AddSignalStrengthChangeHandler 4
#define _MSGID_le_mrc_RemoveSignalStrengthChangeHandler 5
#define _MSGID_le_mrc_SetAutomaticRegisterMode 6
#define _MSGID_le_mrc_SetManualRegisterMode 7
#define _MSGID_le_mrc_SetManualRegisterModeAsync 8
#define _MSGID_le_mrc_GetRegisterMode 9
#define _MSGID_le_mrc_GetPlatformSpecificRegistrationErrorCode 10
#define _MSGID_le_mrc_SetRatPreferences 11
#define _MSGID_le_mrc_GetRatPreferences 12
#define _MSGID_le_mrc_SetBandPreferences 13
#define _MSGID_le_mrc_GetBandPreferences 14
#define _MSGID_le_mrc_SetLteBandPreferences 15
#define _MSGID_le_mrc_GetLteBandPreferences 16
#define _MSGID_le_mrc_SetTdScdmaBandPreferences 17
#define _MSGID_le_mrc_GetTdScdmaBandPreferences 18
#define _MSGID_le_mrc_AddPreferredOperator 19
#define _MSGID_le_mrc_RemovePreferredOperator 20
#define _MSGID_le_mrc_GetPreferredOperatorsList 21
#define _MSGID_le_mrc_GetFirstPreferredOperator 22
#define _MSGID_le_mrc_GetNextPreferredOperator 23
#define _MSGID_le_mrc_DeletePreferredOperatorsList 24
#define _MSGID_le_mrc_GetPreferredOperatorDetails 25
#define _MSGID_le_mrc_GetNetRegState 26
#define _MSGID_le_mrc_GetSignalQual 27
#define _MSGID_le_mrc_SetRadioPower 28
#define _MSGID_le_mrc_GetRadioPower 29
#define _MSGID_le_mrc_PerformCellularNetworkScan 30
#define _MSGID_le_mrc_PerformCellularNetworkScanAsync 31
#define _MSGID_le_mrc_GetFirstCellularNetworkScan 32
#define _MSGID_le_mrc_GetNextCellularNetworkScan 33
#define _MSGID_le_mrc_DeleteCellularNetworkScan 34
#define _MSGID_le_mrc_GetCellularNetworkMccMnc 35
#define _MSGID_le_mrc_GetCellularNetworkName 36
#define _MSGID_le_mrc_GetCellularNetworkRat 37
#define _MSGID_le_mrc_IsCellularNetworkInUse 38
#define _MSGID_le_mrc_IsCellularNetworkAvailable 39
#define _MSGID_le_mrc_IsCellularNetworkHome 40
#define _MSGID_le_mrc_IsCellularNetworkForbidden 41
#define _MSGID_le_mrc_GetCurrentNetworkName 42
#define _MSGID_le_mrc_GetCurrentNetworkMccMnc 43
#define _MSGID_le_mrc_GetRadioAccessTechInUse 44
#define _MSGID_le_mrc_GetNeighborCellsInfo 45
#define _MSGID_le_mrc_DeleteNeighborCellsInfo 46
#define _MSGID_le_mrc_GetFirstNeighborCellInfo 47
#define _MSGID_le_mrc_GetNextNeighborCellInfo 48
#define _MSGID_le_mrc_GetNeighborCellId 49
#define _MSGID_le_mrc_GetNeighborCellLocAreaCode 50
#define _MSGID_le_mrc_GetNeighborCellRxLevel 51
#define _MSGID_le_mrc_GetNeighborCellRat 52
#define _MSGID_le_mrc_GetNeighborCellUmtsEcIo 53
#define _MSGID_le_mrc_GetNeighborCellLteIntraFreq 54
#define _MSGID_le_mrc_GetNeighborCellLteInterFreq 55
#define _MSGID_le_mrc_MeasureSignalMetrics 56
#define _MSGID_le_mrc_DeleteSignalMetrics 57
#define _MSGID_le_mrc_GetRatOfSignalMetrics 58
#define _MSGID_le_mrc_GetGsmSignalMetrics 59
#define _MSGID_le_mrc_GetUmtsSignalMetrics 60
#define _MSGID_le_mrc_GetLteSignalMetrics 61
#define _MSGID_le_mrc_GetCdmaSignalMetrics 62
#define _MSGID_le_mrc_GetServingCellId 63
#define _MSGID_le_mrc_GetServingCellLocAreaCode 64
#define _MSGID_le_mrc_GetServingCellLteTracAreaCode 65
#define _MSGID_le_mrc_GetBandCapabilities 66
#define _MSGID_le_mrc_GetLteBandCapabilities 67
#define _MSGID_le_mrc_GetTdScdmaBandCapabilities 68


#endif // LE_MRC_MESSAGES_H_INCLUDE_GUARD

