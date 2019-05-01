#ifndef __MSL_SHT31_USER_DEFINE_H
#define __MSL_SHT31_USER_DEFINE_H

#include "MSLSHT31Core.h"

extern eMSLReturnResponse_t eMSLSHT31UserDefineSend( xMSLSHT31Device_t *pxMSLSHT31Device, uint8_t *pucCommunicationBuffer, uint8_t ucCommunicationBufferLength );

extern eMSLReturnResponse_t eMSLSHT31UserDefineReceive( xMSLSHT31Device_t *pxMSLSHT31Device, uint8_t *pucCommunicationBuffer, uint8_t ucCommunicationBufferLength );

extern eMSLReturnResponse_t eMSLSHT31UserDefineDelay( uint32_t ulDelay );

#endif
