#include "MSLLCDTest.h"
#include "MSLLCDUserDefine.h"

void vMSLLCDTest( xMSLLCDDevice_t *pxMSLLCDDevice )
{
    /**************************************************************************/
    /*                             Initialisation                             */
    /**************************************************************************/
    eMSLLCDCoreFunctionSet( pxMSLLCDDevice, MSL_LCD_CORE_FUNCTION_SET_FIVE_SEVEN_DOTS, MSL_LCD_CORE_FUNCTION_SET_DISPLAY_LINE_TWO, pxMSLLCDDevice->ucBitMode );

    eMSLLCDCoreEntryMode( pxMSLLCDDevice, MSL_LCD_CORE_ENTRY_MODE_SHIFT_CURSOR, MSL_LCD_CORE_ENTRY_MODE_INCREMENT_ADDRESS_COUNTER );

    eMSLLCDCoreDisplay( pxMSLLCDDevice, MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_OFF, MSL_LCD_CORE_DISPLAY_CURSOR_OFF, MSL_LCD_CORE_DISPLAY_DISPLAY_ON );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );

    /**************************************************************************/
    /*                             Clear Display                              */
    /**************************************************************************/
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'C' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'l' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'a' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'r' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, ' ' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'D' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'i' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 's' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'l' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'p' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'l' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'a' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'y' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );

    /**************************************************************************/
    /*                              Return Home                               */
    /**************************************************************************/
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'R' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 't' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'u' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'r' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'n' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, ' ' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'H' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'o' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'm' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreCursorHome( pxMSLLCDDevice );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreSendData( pxMSLLCDDevice, 'D' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'o' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'n' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, '!' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );

    /**************************************************************************/
    /*                                 Display                                */
    /**************************************************************************/
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'D' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'i' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 's' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'p' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'l' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'a' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'y' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreSendData( pxMSLLCDDevice, ' ' );

    eMSLLCDCoreSendData( pxMSLLCDDevice, 'O' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'F' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'F' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreDisplay( pxMSLLCDDevice, MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_OFF, MSL_LCD_CORE_DISPLAY_CURSOR_OFF, MSL_LCD_CORE_DISPLAY_DISPLAY_OFF );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );

    eMSLLCDCoreSendData( pxMSLLCDDevice, 'D' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'i' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 's' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'p' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'l' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'a' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'y' );

    eMSLLCDCoreSendData( pxMSLLCDDevice, ' ' );

    eMSLLCDCoreSendData( pxMSLLCDDevice, 'O' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'N' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreDisplay( pxMSLLCDDevice, MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_OFF, MSL_LCD_CORE_DISPLAY_CURSOR_OFF, MSL_LCD_CORE_DISPLAY_DISPLAY_ON );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreDisplay( pxMSLLCDDevice, MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_OFF, MSL_LCD_CORE_DISPLAY_CURSOR_ON, MSL_LCD_CORE_DISPLAY_DISPLAY_ON );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreDisplay( pxMSLLCDDevice, MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_ON, MSL_LCD_CORE_DISPLAY_CURSOR_ON, MSL_LCD_CORE_DISPLAY_DISPLAY_ON );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreDisplay( pxMSLLCDDevice, MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_OFF, MSL_LCD_CORE_DISPLAY_CURSOR_OFF, MSL_LCD_CORE_DISPLAY_DISPLAY_ON );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );

    /**************************************************************************/
    /*                          Cursor Display Shift                          */
    /**************************************************************************/
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'C' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'u' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'r' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 's' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'o' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'r' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, ' ' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'D' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'i' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 's' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'p' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'l' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'a' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'y' );

    eMSLLCDCoreSetDDRamAddress( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_HOME_SECOND_LINE_SPECIAL_ADDRESS );

    eMSLLCDCoreSendData( pxMSLLCDDevice, 'S' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'h' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'i' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'f' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 't' );

    eMSLLCDCoreDisplay( pxMSLLCDDevice, MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_OFF, MSL_LCD_CORE_DISPLAY_CURSOR_ON, MSL_LCD_CORE_DISPLAY_DISPLAY_ON );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_LEFT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_CURSOR );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_LEFT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_CURSOR );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_LEFT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_CURSOR );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_RIGHT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_CURSOR );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_RIGHT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_CURSOR );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_RIGHT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_CURSOR );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_RIGHT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_DISPLAY );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_RIGHT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_DISPLAY );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_RIGHT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_DISPLAY );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_LEFT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_DISPLAY );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_LEFT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_DISPLAY );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreCursorDisplayShift( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_LEFT, MSL_LCD_CORE_CURSOR_DISPLAY_SHIFT_SHIFT_DISPLAY );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreDisplay( pxMSLLCDDevice, MSL_LCD_CORE_DISPLAY_CURSOR_BLINK_OFF, MSL_LCD_CORE_DISPLAY_CURSOR_OFF, MSL_LCD_CORE_DISPLAY_DISPLAY_ON );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );

    /**************************************************************************/
    /*                        Set/Write DDRAM Address                         */
    /**************************************************************************/
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'S' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 't' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, '/' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'W' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'r' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'i' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 't' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );

    eMSLLCDCoreSetDDRamAddress( pxMSLLCDDevice, MSL_LCD_CORE_CURSOR_HOME_SECOND_LINE_SPECIAL_ADDRESS );

    eMSLLCDCoreSendData( pxMSLLCDDevice, 'D' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'D' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'R' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'A' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'M' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, ' ' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'A' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'd' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'd' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'r' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 's' );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 's' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );

    uint8_t PositionArray[ 2 * 16 ] = { 0x00, 0x0F, 0x01, 0x0E, 0x02, 0x0D, 0x03, 0x0C, 0x04, 0x0B, 0x05, 0x0A, 0x06, 0x09, 0x07, 0x08,
                                        0x28, 0x4F, 0x41, 0x4E, 0x42, 0x4D, 0x43, 0x4C, 0x44, 0x4B, 0x45, 0x4A, 0x46, 0x49, 0x47, 0x48 };

    for( uint8_t i=0; i< 2 * 16; i++)
    {
      eMSLLCDCoreSetDDRamAddress( pxMSLLCDDevice, PositionArray[ i ] );
      eMSLLCDCoreWriteCGDDRamAddress( pxMSLLCDDevice, 'X' );
      eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    }

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );

    /**************************************************************************/
    /*                              Entry Mode                                */
    /**************************************************************************/
    eMSLLCDCoreEntryMode( pxMSLLCDDevice, MSL_LCD_CORE_ENTRY_MODE_SHIFT_CURSOR, MSL_LCD_CORE_ENTRY_MODE_INCREMENT_ADDRESS_COUNTER);
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'E' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'n' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 't' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'r' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'y' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, ' ' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'M' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'o' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'd' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );
    eMSLLCDCoreSetDDRamAddress( pxMSLLCDDevice, 0x0F );

    eMSLLCDCoreEntryMode( pxMSLLCDDevice, MSL_LCD_CORE_ENTRY_MODE_SHIFT_CURSOR, MSL_LCD_CORE_ENTRY_MODE_DECREMENT_ADDRESS_COUNTER);
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'E' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'n' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 't' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'r' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'y' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, ' ' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'M' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'o' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'd' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );

    eMSLLCDCoreEntryMode( pxMSLLCDDevice, MSL_LCD_CORE_ENTRY_MODE_SHIFT_DISPLAY, MSL_LCD_CORE_ENTRY_MODE_DISPLAY_SHIFT_RIGHT);
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'E' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'n' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 't' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'r' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'y' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, ' ' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'M' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'o' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'd' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );
    eMSLLCDCoreSetDDRamAddress( pxMSLLCDDevice, 0x0F );

    /*As said, there is a problem with the */
    /*This tend to not print as intended*/
    eMSLLCDCoreEntryMode( pxMSLLCDDevice, MSL_LCD_CORE_ENTRY_MODE_SHIFT_DISPLAY, MSL_LCD_CORE_ENTRY_MODE_DISPLAY_SHIFT_LEFT);
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'E' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'n' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 't' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'r' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'y' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, ' ' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'M' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'o' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'd' );
    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY_QUICK );
    eMSLLCDCoreSendData( pxMSLLCDDevice, 'e' );

    eMSLLCDUserDefineDelay( MSL_LCD_TEST_DISPLAY_DELAY );

    eMSLLCDCoreEntryMode( pxMSLLCDDevice, MSL_LCD_CORE_ENTRY_MODE_SHIFT_CURSOR, MSL_LCD_CORE_ENTRY_MODE_INCREMENT_ADDRESS_COUNTER);

    eMSLLCDCoreClearDisplay( pxMSLLCDDevice );
}
