#ifndef __MSLLCDUPPERLAYER_H
#define __MSLLCDUPPERLAYER_H

#include "MSLLCDCore.h"

/*uint32_t maximum value is 4,294,967,295 which is 10 digit
 *and since int can be negative, it can need a "-" charactere*/
#define MSL_LCD_UPPER_LAYER_INT_DECIMAL_DIGIT_QUANTITY 11

eMSLReturnResponse_t eMSLLCDUpperLayerInit( xMSLLCDDevice_t *pxMSLLCDDevice );

eMSLReturnResponse_t eMSLLCDUpperLayerSendWord( xMSLLCDDevice_t *pxMSLLCDDevice, int slWord );

eMSLReturnResponse_t eMSLLCDUpperLayerSendDouble( xMSLLCDDevice_t *pxMSLLCDDevice, float slDouble, uint8_t ucLength );

eMSLReturnResponse_t eMSLLCDUpperLayerSendString( xMSLLCDDevice_t *pxMSLLCDDevice, char *pucString );

#endif
