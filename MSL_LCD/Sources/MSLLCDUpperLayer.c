#include "MSLLCDUpperLayer.h"
#include <stdio.h>
#include <math.h>

eMSLReturnResponse_t eMSLLCDUpperLayerInit( xMSLLCDDevice_t *pxMSLLCDDevice )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  eMSLReturnResponse = eMSLLCDCoreFunctionSet( pxMSLLCDDevice, MSL_LCD_CORE_FUNCTION_SET_FIVE_SEVEN_DOTS, MSL_LCD_CORE_FUNCTION_SET_DISPLAY_LINE_TWO, pxMSLLCDDevice->ucBitMode );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  eMSLReturnResponse = eMSLLCDCoreEntryMode( pxMSLLCDDevice, MSL_LCD_CORE_ENTRY_MODE_SHIFT_CURSOR, MSL_LCD_CORE_ENTRY_MODE_INCREMENT_ADDRESS_COUNTER );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  eMSLReturnResponse = eMSLLCDCoreDisplay( pxMSLLCDDevice, MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_OFF, MSL_LCD_CORE_DISPLAY_CURSOR_OFF, MSL_LCD_CORE_DISPLAY_DISPLAY_ON );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  eMSLReturnResponse = eMSLLCDCoreClearDisplay( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDUpperLayerSendWord( xMSLLCDDevice_t *pxMSLLCDDevice, int ulWord )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

	char pucString[ MSL_LCD_UPPER_LAYER_INT_DECIMAL_DIGIT_QUANTITY ];

	sprintf( pucString, "%d", ulWord );

	eMSLReturnResponse = eMSLLCDUpperLayerSendString( pxMSLLCDDevice, pucString );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDUpperLayerSendDouble( xMSLLCDDevice_t *pxMSLLCDDevice, float slDouble, uint8_t ucPrecision )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

		if(slDouble < 0)
		{
			slDouble *= -1;
			eMSLReturnResponse = eMSLLCDCoreSendData( pxMSLLCDDevice, '-' );
		  if( eMSLReturnResponse != eMSLSuccess )
		  {
		    return eMSLReturnResponse;
		  }
		}

		eMSLReturnResponse = eMSLLCDUpperLayerSendWord( pxMSLLCDDevice, (int)slDouble );
	  if( eMSLReturnResponse != eMSLSuccess )
	  {
	    return eMSLReturnResponse;
	  }

	    int slInteger=0;

		if( ucPrecision >= 1 )
		{

			slInteger = slDouble;
			slDouble -= slInteger;

			//Looking if there is values to be print
			//within the first "precision" decimals
			if( slDouble * pow( 10, ucPrecision ) > 0)
			{
			  eMSLReturnResponse = eMSLLCDCoreSendData( pxMSLLCDDevice, '.' );
			  if( eMSLReturnResponse != eMSLSuccess )
			  {
			    return eMSLReturnResponse;
			  }
				int value=0, y=0;

				for ( uint8_t ucI = 1; ucI <= ucPrecision; ucI++ )
				{
					value = slDouble * pow( 10, ucI );

					if( ucI == ucPrecision )
					{
						y = slDouble * pow( 10, ucI + 1 );
						if( ( y % 10) == 9 )
						{
							y = slDouble * pow( 10, ucI + 2 );
							if( ( y % 10 ) == 9 )
								value++;
						}
					}

					//Print the decimal knowing that 0x30 is 0 in ascii
					eMSLReturnResponse = eMSLLCDCoreSendData( pxMSLLCDDevice, ( 0x30 + ( value % 10 ) ) );
				  if( eMSLReturnResponse != eMSLSuccess )
				  {
				    return eMSLReturnResponse;
				  }
				}
			}
		}

	  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDUpperLayerSendString( xMSLLCDDevice_t *pxMSLLCDDevice, char *pucString )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

	  while(*pucString > 0)
	  {
	    eMSLReturnResponse = eMSLLCDCoreSendData( pxMSLLCDDevice, *pucString++);
      if( eMSLReturnResponse != eMSLSuccess )
      {
        return eMSLReturnResponse;
      }
	  }

	  return eMSLSuccess;
}
