#include "MSLLCDCore.h"
#include "MSLLCDSend.h"
#include "MSLLCDUserDefine.h"

eMSLReturnResponse_t eMSLLCDCoreClearDisplay( xMSLLCDDevice_t *pxMSLLCDDevice )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = MSL_LCD_CORE_CLEAR_DISPLAY_MASK;

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDCoreCursorHome( xMSLLCDDevice_t *pxMSLLCDDevice )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = MSL_LCD_CORE_CURSOR_HOME_MASK;

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDCoreCursorHomeSecondLine( xMSLLCDDevice_t *pxMSLLCDDevice )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = MSL_LCD_CORE_CURSOR_HOME_SECOND_LINE_SPECIAL_ADDRESS;

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDCoreEntryMode( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t S, uint8_t ID )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = MSL_LCD_CORE_ENTRY_MODE_MASK | ID << MSL_LCD_CORE_ENTRY_MODE_INCREMENT_DECREMENT_ADDRESS_COUNTER_POS | S << MSL_LCD_CORE_ENTRY_MODE_SHIFT_CURSOR_DISPLAY_POS;

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDCoreDisplay( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t CursorBliking, uint8_t CursorOnOff, uint8_t DisplayOnOff )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = MSL_LCD_CORE_DISPLAY_MASK | DisplayOnOff << MSL_LCD_CORE_DISPLAY_DISPLAY_ON_OFF_POS | CursorOnOff << MSL_LCD_CORE_DISPLAY_CURSOR_ON_OFF_POS | CursorBliking << MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_ON_OFF_POS;

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDCoreCursorDisplayShift( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t ShiftLeftRight, uint8_t ShiftCursorDisplay )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_MASK | ShiftCursorDisplay << MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_CURSOR_DISPLAY_POS | ShiftLeftRight << MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_LEFT_RIGHT_POS;

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDCoreFunctionSet( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t DotFormat, uint8_t DisplayLine, uint8_t DataLength )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = MSL_LCD_CORE_FUNCTION_SET_MASK | DataLength << MSL_LCD_CORE_FUNCTION_SET_DATA_LENGTH_POS | DisplayLine << MSL_LCD_CORE_FUNCTION_SET_DISPLAY_LINE_POS | DotFormat << MSL_LCD_CORE_FUNCTION_SET_FONT_POS ;

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDCoreSetCGRamAddress( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t address )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = MSL_LCD_CORE_SET_CG_RAM_ADDRESS_MASK | ( MSL_LCD_CORE_SET_CG_RAM_ADDRESS_ADDRESS_MASK & address );

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDCoreSetDDRamAddress( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t address )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = MSL_LCD_CORE_SET_DD_RAM_ADDRESS_MASK | ( MSL_LCD_CORE_SET_DD_RAM_ADDRESS_ADDRESS_MASK & address );

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDCoreWriteCGDDRamAddress( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t value )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_DATA;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = value;

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}


eMSLReturnResponse_t eMSLLCDCoreSendInstruction( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t DataBus )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = DataBus;

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}

eMSLReturnResponse_t eMSLLCDCoreSendData( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t data )
{
  eMSLReturnResponse_t eMSLReturnResponse = eMSLError;

  pxMSLLCDDevice->pxMSLLCDPort->ucRS = MSL_LCD_CORE_RS_DATA;
  pxMSLLCDDevice->pxMSLLCDPort->ucRW = MSL_LCD_CORE_RW_WRITE;
  pxMSLLCDDevice->pxMSLLCDPort->ucDB = data;

  eMSLReturnResponse = eMSLLCDSend( pxMSLLCDDevice );
  if( eMSLReturnResponse != eMSLSuccess )
  {
    return eMSLReturnResponse;
  }

  return eMSLSuccess;
}
