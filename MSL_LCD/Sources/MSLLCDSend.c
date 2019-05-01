#include "MSLLCDSend.h"
#include "MSLLCDUserDefine.h"

eMSLReturnResponse_t eMSLLCDSend( xMSLLCDDevice_t *pxMSLLCDDevice )
{
	if( pxMSLLCDDevice->ucBitMode == MSL_LCD_CORE_FUNCTION_SET_EIGHT_BIT_DATA_LENGTH )
	{
		pxMSLLCDDevice->pxMSLLCDPort->ucE = MSL_LCD_CORE_E_DISABLE;
		eMSLLCDUserDefineSend( pxMSLLCDDevice );
		eMSLLCDUserDefineDelay( MSL_LCD_CORE_DELAY_MS );
		pxMSLLCDDevice->pxMSLLCDPort->ucE = MSL_LCD_CORE_E_ENABLE;
		eMSLLCDUserDefineSend( pxMSLLCDDevice );
		eMSLLCDUserDefineDelay( MSL_LCD_CORE_DELAY_MS );
	}
	else if( pxMSLLCDDevice->ucBitMode == MSL_LCD_CORE_FUNCTION_SET_FOUR_BIT_DATA_LENGTH )
	{
		uint8_t ucDBTemp = pxMSLLCDDevice->pxMSLLCDPort->ucDB;
		pxMSLLCDDevice->pxMSLLCDPort->ucE = MSL_LCD_CORE_E_DISABLE;
		eMSLLCDUserDefineSend( pxMSLLCDDevice );
		eMSLLCDUserDefineDelay( MSL_LCD_CORE_DELAY_MS );
		pxMSLLCDDevice->pxMSLLCDPort->ucE = MSL_LCD_CORE_E_ENABLE;
		eMSLLCDUserDefineSend( pxMSLLCDDevice );
		eMSLLCDUserDefineDelay( MSL_LCD_CORE_DELAY_MS );

		pxMSLLCDDevice->pxMSLLCDPort->ucDB = ( pxMSLLCDDevice->pxMSLLCDPort->ucDB << ( CHAR_BIT / 2 ) );

		pxMSLLCDDevice->pxMSLLCDPort->ucE = MSL_LCD_CORE_E_DISABLE;
		eMSLLCDUserDefineSend( pxMSLLCDDevice );
		eMSLLCDUserDefineDelay( MSL_LCD_CORE_DELAY_MS );
		pxMSLLCDDevice->pxMSLLCDPort->ucE = MSL_LCD_CORE_E_ENABLE;
		eMSLLCDUserDefineSend( pxMSLLCDDevice );
		eMSLLCDUserDefineDelay( MSL_LCD_CORE_DELAY_MS );

		pxMSLLCDDevice->pxMSLLCDPort->ucDB = ucDBTemp;
	}
	else
	{
		return eMSLError;
	}

	return eMSLSuccess;
}
