#include "unity.h"
#include "MSLLCDCore.h"
#include "mock_MSLLCDSend.h"

static eMSLReturnResponse_t eClearDisplayReturnResponse;
static eMSLReturnResponse_t eClearDisplayReturnResponse_expected;
static eMSLReturnResponse_t eSendReturnResponse;

static xMSLLCDDevice_t xMSLLCDDevice;
static xMSLLCDPort_t xMSLLCDPort;
static xMSLLCDDevice_t xMSLLCDDevice_expected;
static xMSLLCDPort_t xMSLLCDPort_expected;

void setUp(void)
{
	eClearDisplayReturnResponse = eMSLError;
	eClearDisplayReturnResponse_expected = eMSLSuccess;
	eSendReturnResponse = eMSLSuccess;

	xMSLLCDPort.ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
	xMSLLCDPort.ucRW = MSL_LCD_CORE_RW_WRITE;
	xMSLLCDPort.ucE = MSL_LCD_CORE_E_DISABLE;
	xMSLLCDPort.ucDB = MSL_LCD_CORE_CLEAR_DISPLAY_MASK;

	xMSLLCDDevice.ucDeviceID = 0x0000;
	xMSLLCDDevice.ucBitMode = MSL_LCD_CORE_FUNCTION_SET_EIGHT_BIT_DATA_LENGTH;
	xMSLLCDDevice.pxMSLLCDPort = &xMSLLCDPort;

	xMSLLCDPort_expected.ucRS = MSL_LCD_CORE_RS_INSTRUCTION;
	xMSLLCDPort_expected.ucRW = MSL_LCD_CORE_RW_WRITE;
	xMSLLCDPort_expected.ucE = MSL_LCD_CORE_E_DISABLE;
	xMSLLCDPort_expected.ucDB = MSL_LCD_CORE_CLEAR_DISPLAY_MASK;

	xMSLLCDDevice_expected.ucDeviceID = 0x0000;
	xMSLLCDDevice_expected.ucBitMode = MSL_LCD_CORE_FUNCTION_SET_EIGHT_BIT_DATA_LENGTH;
	xMSLLCDDevice_expected.pxMSLLCDPort = &xMSLLCDPort_expected;

}

void tearDown(void)
{
}

void vMSLLCDSend_Caller()
{
	//eMSLLCDSend_ExpectWithArrayAndReturn( &xMSLLCDDevice, sizeof(xMSLLCDDevice), eSendReturnResponse );
	eMSLLCDSend_IgnoreAndReturn( eSendReturnResponse );
}

eMSLReturnResponse_t eMSLLCDCoreClearDisplay_Caller()
{
	 return eMSLLCDCoreClearDisplay( &xMSLLCDDevice );
}

void test_Valid(void)
{
	vMSLLCDSend_Caller();

	eClearDisplayReturnResponse = eMSLLCDCoreClearDisplay_Caller();

	TEST_ASSERT_EQUAL( eClearDisplayReturnResponse_expected, eClearDisplayReturnResponse );
}
