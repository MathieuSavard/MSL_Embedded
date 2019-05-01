#include "unity.h"
#include "MSLLCD.h"
#include "mock_MSLLCDSend.h"

static eMSLReturnResponse_t eClearDisplayReturnResponse;
static eMSLReturnResponse_t eClearDisplayReturnResponse_expected;
static eMSLReturnResponse_t eSendReturnResponse;

static xMSLLCDDevice_t xMSLLCDDevice;
static xMSLLCDPort_t xMSLLCDPort;

void setUp(void)
{
	xMSLLCDPort.ucRS = MSL_LCD_RS_INSTRUCTION;
	xMSLLCDPort.ucRW = MSL_LCD_RW_WRITE;
	xMSLLCDPort.ucE = MSL_LCD_E_DISABLE;
	xMSLLCDPort.ucDB = MSL_LCD_CLEAR_DISPLAY_MASK;

	xMSLLCDDevice.ucDeviceID = 0x0000;
	xMSLLCDDevice.ucBitMode = MSL_LCD_FUNCTION_SET_EIGHT_BIT_DATA_LENGTH;
	xMSLLCDDevice.pxMSLLCDPort = &xMSLLCDPort;

	eClearDisplayReturnResponse = eMSLError;
	eClearDisplayReturnResponse_expected = eMSLSuccess;
	eSendReturnResponse = eMSLSuccess;
}

void tearDown(void)
{
}

void eMSLLCDSend_Caller()
{
	eMSLLCDSend_ExpectWithArrayAndReturn( &xMSLLCDDevice, sizeof(xMSLLCDDevice), eSendReturnResponse );
}

eMSLReturnResponse_t eMSLLCDClearDisplay_Caller()
{
	 return eMSLLCDClearDisplay( &xMSLLCDDevice );
}

void test_Valid(void)
{
	eMSLLCDSend_Caller();

	eClearDisplayReturnResponse = eMSLLCDClearDisplay_Caller();

	TEST_ASSERT_EQUAL( eClearDisplayReturnResponse_expected, eClearDisplayReturnResponse );
}
