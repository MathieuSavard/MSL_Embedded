#ifndef __MSLLCDCORE_H
#define __MSLLCDCORE_H

#include "MSLCore.h"

#define MSL_LCD_CORE_CLEAR_DISPLAY_MASK                                                 ( 0x01 )

#define MSL_LCD_CORE_CURSOR_HOME_MASK                                                   ( 0x02 )

/*When 2 display lines is selected*/
/*The 16 viewable DDRAM address of the first line are 0x00, 0x01, 0x02, ..., 0x0D, 0x0E, 0x0F*/
/*The 16 viewable DDRAM address of the second line are 0x40, 0x41, 0x42, ..., 0x4D, 0x4E, 0x4F*/
/*Except that for the MTC-S16205 LCD the first viewable DDRAM address is 40 ( 0x28 ) and not 0x40*/
/*This mean that the 16 real viewable DDRAM address of the second line for the MTC-S16205 LCD are*/
/*0x28, 0x41, 0x42, ..., 0x4D, 0x4E, 0x4F*/
#define MSL_LCD_CORE_CURSOR_HOME_SECOND_LINE_SPECIAL_ADDRESS                            ( 0x28 )

#define MSL_LCD_CORE_ENTRY_MODE_MASK                                                    ( 0x04 )
#define MSL_LCD_CORE_ENTRY_MODE_SHIFT_CURSOR_DISPLAY_POS                                ( 0x00 )
#define MSL_LCD_CORE_ENTRY_MODE_INCREMENT_DECREMENT_ADDRESS_COUNTER_POS                 ( 0x01 )
#define MSL_LCD_CORE_ENTRY_MODE_SHIFT_CURSOR                                            ( 0x00 )
#define MSL_LCD_CORE_ENTRY_MODE_SHIFT_DISPLAY                                           ( 0x01 )
#define MSL_LCD_CORE_ENTRY_MODE_DECREMENT_ADDRESS_COUNTER                               ( 0x00 )
#define MSL_LCD_CORE_ENTRY_MODE_INCREMENT_ADDRESS_COUNTER                               ( 0x01 )
#define MSL_LCD_CORE_ENTRY_MODE_DISPLAY_SHIFT_RIGHT                                     ( 0x00 )
#define MSL_LCD_CORE_ENTRY_MODE_DISPLAY_SHIFT_LEFT                                      ( 0x01 )

#define MSL_LCD_CORE_DISPLAY_MASK                                                       ( 0x08 )
#define MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_ON_OFF_POS                                    ( 0x00 )
#define MSL_LCD_CORE_DISPLAY_CURSOR_ON_OFF_POS                                          ( 0x01 )
#define MSL_LCD_CORE_DISPLAY_DISPLAY_ON_OFF_POS                                         ( 0x02 )
#define MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_OFF                                           ( 0x00 )
#define MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_ON                                            ( 0x01 )
#define MSL_LCD_CORE_DISPLAY_CURSOR_OFF                                                 ( 0x00 )
#define MSL_LCD_CORE_DISPLAY_CURSOR_ON                                                  ( 0x01 )
#define MSL_LCD_CORE_DISPLAY_DISPLAY_OFF                                                ( 0x00 )
#define MSL_LCD_CORE_DISPLAY_DISPLAY_ON                                                 ( 0x01 )

#define MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_MASK                                          ( 0x10 )
#define MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_LEFT_RIGHT_POS                          ( 0x02 )
#define MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_CURSOR_DISPLAY_POS                      ( 0x03 )
#define MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_LEFT                                    ( 0x00 )
#define MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_RIGHT                                   ( 0x01 )
#define MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_CURSOR                                  ( 0x00 )
#define MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_DISPLAY                                 ( 0x01 )

#define MSL_LCD_CORE_FUNCTION_SET_MASK                                                  ( 0x20 )
#define MSL_LCD_CORE_FUNCTION_SET_FONT_POS                                              ( 0x02 )
#define MSL_LCD_CORE_FUNCTION_SET_DISPLAY_LINE_POS                                      ( 0x03 )
#define MSL_LCD_CORE_FUNCTION_SET_DATA_LENGTH_POS                                       ( 0x04 )
#define MSL_LCD_CORE_FUNCTION_SET_FIVE_SEVEN_DOTS                                       ( 0x00 )
#define MSL_LCD_CORE_FUNCTION_SET_FIVE_TEN_DOTS                                         ( 0x01 )
#define MSL_LCD_CORE_FUNCTION_SET_DISPLAY_LINE_ONE                                      ( 0x00 )
#define MSL_LCD_CORE_FUNCTION_SET_DISPLAY_LINE_TWO                                      ( 0x01 )
#define MSL_LCD_CORE_FUNCTION_SET_FOUR_BIT_DATA_LENGTH                                  ( 0x00 )
#define MSL_LCD_CORE_FUNCTION_SET_EIGHT_BIT_DATA_LENGTH                                 ( 0x01 )

#define MSL_LCD_CORE_SET_CG_RAM_ADDRESS_MASK                                            ( 0x40 )
#define MSL_LCD_CORE_SET_CG_RAM_ADDRESS_ADDRESS_MASK                                    ( 0x3F )

#define MSL_LCD_CORE_SET_DD_RAM_ADDRESS_MASK                                            ( 0x80 )
#define MSL_LCD_CORE_SET_DD_RAM_ADDRESS_ADDRESS_MASK                                    ( 0x7F )

#define MSL_LCD_CORE_RS_POS                                                             ( 0x00 )
#define MSL_LCD_CORE_RS_INSTRUCTION                                                     ( 0x00 )
#define MSL_LCD_CORE_RS_DATA                                                            ( 0x01 )

#define MSL_LCD_CORE_RW_POS                                                             ( 0x01 )
#define MSL_LCD_CORE_RW_WRITE                                                           ( 0x00 )
#define MSL_LCD_CORE_RW_READ                                                            ( 0x01 )

#define MSL_LCD_CORE_E_POS                                                              ( 0x02 )
#define MSL_LCD_CORE_E_ENABLE                                                           ( 0x00 )
#define MSL_LCD_CORE_E_DISABLE                                                          ( 0x01 )

#define MSL_LCD_CORE_DB_POS                                                             ( 0x03 )

#define MSL_LCD_CORE_DELAY_MS                                                           ( 0x02 )

typedef struct
{
  uint8_t ucRS: 1;
  uint8_t ucRW: 1;
  uint8_t ucE: 1;
  uint8_t ucDB;
} xMSLLCDPort_t;

typedef struct
{
  uint8_t ucDeviceID;
  uint8_t ucBitMode : 1;
  xMSLLCDPort_t *pxMSLLCDPort;
} xMSLLCDDevice_t;

eMSLReturnResponse_t eMSLLCDCoreClearDisplay( xMSLLCDDevice_t *pxMSLLCDDevice );

eMSLReturnResponse_t eMSLLCDCoreCursorHome( xMSLLCDDevice_t *pxMSLLCDDevice );

eMSLReturnResponse_t eMSLLCDCoreCursorHomeSecondLine( xMSLLCDDevice_t *pxMSLLCDDevice );

eMSLReturnResponse_t eMSLLCDCoreEntryMode( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t S, uint8_t ID );

eMSLReturnResponse_t eMSLLCDCoreDisplay( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t CursorBliking, uint8_t CursorOnOff, uint8_t DisplayOnOff );

eMSLReturnResponse_t eMSLLCDCoreCursorDisplayShift( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t ShiftLeftRight, uint8_t ShiftCursorDisplay );

eMSLReturnResponse_t eMSLLCDCoreFunctionSet( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t DotFormat, uint8_t DisplayLine, uint8_t DataLength );

eMSLReturnResponse_t eMSLLCDCoreSetCGRamAddress( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t address );

eMSLReturnResponse_t eMSLLCDCoreSetDDRamAddress( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t address );

eMSLReturnResponse_t eMSLLCDCoreWriteCGDDRamAddress( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t value );


eMSLReturnResponse_t eMSLLCDCoreSendInstruction( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t DataBus );

eMSLReturnResponse_t eMSLLCDCoreSendData( xMSLLCDDevice_t *pxMSLLCDDevice, uint8_t data );

#endif
