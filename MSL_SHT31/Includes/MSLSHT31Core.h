#ifndef __MSL_SHT31_CORE_H
#define __MSL_SHT31_CORE_H

#include "MSLCore.h"

/*When ADDR pin is connected to VSS*/
#define MSL_SHT31_CORE_ADDRESS_A                                                     ( 0x44 )
/*When ADDR pin is connected to VDD*/
#define MSL_SHT31_CORE_ADDRESS_B                                                     ( 0x45 )

#define MSL_SHT31_CORE_CRC_LENGTH                                                      ( 0x01 )
#define MSL_SHT31_CORE_CRC_WIDTH                                                       ( CHAR_BIT )
#define MSL_SHT31_CORE_CRC_POLYNOMIAL                                                  ( 0x31 )
#define MSL_SHT31_CORE_CRC_INITIALISATION                                              ( 0xFF )
#define MSL_SHT31_CORE_CRC_FINAL_XOR                                                   ( 0x00 )
#define MSL_SHT31_CORE_CRC_MSB                                                         ( 0x80 )
#define MSL_SHT31_CORE_CRC_LSB                                                         ( 0x01 )

#define MSL_SHT31_CORE_ADDRESS_POS                                                   ( 0x00 )
#define MSL_SHT31_CORE_ADDRESS_LENGTH                                                ( 0x01 )

#define MSL_SHT31_CORE_COMMAND_POS                                                   ( 0x01 )
#define MSL_SHT31_CORE_COMMAND_POS_MSB                                               ( 0x00 + MSL_SHT31_CORE_COMMAND_POS )
#define MSL_SHT31_CORE_COMMAND_POS_LSB                                               ( 0x01 + MSL_SHT31_CORE_COMMAND_POS )
#define MSL_SHT31_CORE_COMMAND_LENGTH                                                ( 0x02 )
#define MSL_SHT31_CORE_COMMAND_CRC_POS                                               ( 0x03 )

#define MSL_SHT31_CORE_TEMPERATURE_POS                                               ( 0x01 )
#define MSL_SHT31_CORE_TEMPERATURE_POS_MSB                                           ( 0x00 + MSL_SHT31_CORE_TEMPERATURE_POS )
#define MSL_SHT31_CORE_TEMPERATURE_POS_LSB                                           ( 0x01 + MSL_SHT31_CORE_TEMPERATURE_POS )
#define MSL_SHT31_CORE_TEMPERATURE_LENGTH                                            ( 0x02 )
#define MSL_SHT31_CORE_TEMPERATURE_CRC_POS                                           ( 0x03 )

#define MSL_SHT31_CORE_HUMIDITY_POS                                                  ( 0x04 )
#define MSL_SHT31_CORE_HUMIDITY_POS_MSB                                              ( 0x00 + MSL_SHT31_CORE_HUMIDITY_POS )
#define MSL_SHT31_CORE_HUMIDITY_POS_LSB                                              ( 0x01 + MSL_SHT31_CORE_HUMIDITY_POS )
#define MSL_SHT31_CORE_HUMIDITY_LENGTH                                               ( 0x02 )
#define MSL_SHT31_CORE_HUMIDITY_CRC_POS                                              ( 0x06 )

#define MSL_SHT31_CORE_STATUS_REGISTER_POS                                           ( 0x01 )
#define MSL_SHT31_CORE_STATUS_REGISTER_POS_MSB                                       ( 0x00 + MSL_SHT31_CORE_STATUS_REGISTER_POS )
#define MSL_SHT31_CORE_STATUS_REGISTER_POS_LSB                                       ( 0x01 + MSL_SHT31_CORE_STATUS_REGISTER_POS )
#define MSL_SHT31_CORE_STATUS_REGISTER_LENGTH                                        ( 0x02 )
#define MSL_SHT31_CORE_STATUS_REGISTER_CRC_POS                                       ( 0x03 )
#define MSL_SHT31_CORE_STATUS_REGISTER_WRITE_DATA_CHECKSUM_STATUS_MASK               ( 0x0001 )  /*0 - Correct   1 - Failed*/
#define MSL_SHT31_CORE_STATUS_REGISTER_COMMAND_STATUS_MASK                           ( 0x0002 )  /*0 - Command executed successfully   1 - Command not processed*/
#define MSL_SHT31_CORE_STATUS_REGISTER_SYSTEM_RESET_DETECTED_MASK                    ( 0x0010 )  /*0 - No reset detected   1 - Reset detected*/
#define MSL_SHT31_CORE_STATUS_REGISTER_TEMPERATURE_TRACKING_ALERT_MASK               ( 0x0400 )  /*0 - No alert   1 - Alert*/
#define MSL_SHT31_CORE_STATUS_REGISTER_HUMIDITY_TRACKING_ALERT_MASK                  ( 0x0800 )  /*0 - No alert   1 - Alert*/
#define MSL_SHT31_CORE_STATUS_REGISTER_HEATER_STATUS_MASK                            ( 0x2000 )  /*0 - Heater OFF   1 - Heater On*/
#define MSL_SHT31_CORE_STATUS_REGISTER_ALERT_PENDING_STATUS_MASK                     ( 0x8000 )  /*0 - No pending alert   1 - At least one pending alert*/

/*Measurement duration in milliseconds*/
#define MSL_SHT31_CORE_MEASUREMENT_DURATION_HIGH_REPEATABILITY                       ( 4 )
#define MSL_SHT31_CORE_MEASUREMENT_DURATION_MEDIUM_REPEATABILITY                     ( 6 )
#define MSL_SHT31_CORE_MEASUREMENT_DURATION_LOW_REPEATABILITY                        ( 15 )

#define MSL_SHT31_CORE_ART_COMMAND_MSB                                               ( 0x2B )
#define MSL_SHT31_CORE_ART_COMMAND_LSB                                               ( 0x32 )

#define MSL_SHT31_CORE_HEATER_COMMAND_MSB                                            ( 0x30 )
#define MSL_SHT31_CORE_HEATER_ENABLE_LSB                                             ( 0x6D )
#define MSL_SHT31_CORE_HEATER_DISABLE_LSB                                            ( 0x66 )

#define MSL_SHT31_CORE_RESET_COMMAND_MSB                                             ( 0x30 )
#define MSL_SHT31_CORE_RESET_COMMAND_LSB                                             ( 0xA2 )

#define MSL_SHT31_CORE_RESET_THROUGH_GENERAL_CALL_COMMAND_ADDRESS_BYTE               ( 0x00 )
#define MSL_SHT31_CORE_RESET_THROUGH_GENERAL_CALL_COMMAND_SECOND_BYTE                ( 0x06 )
#define MSL_SHT31_CORE_RESET_THROUGH_GENERAL_CALL_COMMAND_SECOND_BYTE_LENGTH         ( 0x01 )

#define MSL_SHT31_CORE_STATUS_REGISTER_COMMAND_MSB                                   ( 0xF3 )
#define MSL_SHT31_CORE_STATUS_REGISTER_COMMAND_LSB                                   ( 0x2D )

#define MSL_SHT31_CORE_CLEAR_STATUS_REGISTER_COMMAND_MSB                             ( 0x30 )
#define MSL_SHT31_CORE_CLEAR_STATUS_REGISTER_COMMAND_LSB                             ( 0x41 )

#define MSL_SHT31_CORE_CLOCK_STRETCHING_ENABLE_MSB                                   ( 0x2C )
#define MSL_SHT31_CORE_COCK_STRETCHING_ENABLE_HIGH_REPEATABILITY_LSB                 ( 0x06 )
#define MSL_SHT31_CORE_COCK_STRETCHING_ENABLE_MEDIUM_REPEATABILITY_LSB               ( 0x0D )
#define MSL_SHT31_CORE_COCK_STRETCHING_ENABLE_LOW_REPEATABILITY_LSB                  ( 0x10 )
#define MSL_SHT31_CORE_CLOCK_STRETCHING_DISABLE_MSB                                  ( 0x24 )
#define MSL_SHT31_CORE_COCK_STRETCHING_DISABLE_HIGH_REPEATABILITY_LSB                ( 0x00 )
#define MSL_SHT31_CORE_COCK_STRETCHING_DISABLE_MEDIUM_REPEATABILITY_LSB              ( 0x0B )
#define MSL_SHT31_CORE_COCK_STRETCHING_DISABLE_LOW_REPEATABILITY_LSB                 ( 0x16 )

#define MSL_SHT31_CORE_HALF_MEASUREMENT_PER_SECOND_MSB                               ( 0x20 )
#define MSL_SHT31_CORE_HALF_MEASUREMENT_PER_SECOND_HIGH_REPEATABILITY_LSB            ( 0x32 )
#define MSL_SHT31_CORE_HALF_MEASUREMENT_PER_SECOND_MEDIUM_REPEATABILITY_LSB          ( 0x24 )
#define MSL_SHT31_CORE_HALF_MEASUREMENT_PER_SECOND_LOW_REPEATABILITY_LSB             ( 0x2F )
#define MSL_SHT31_CORE_ONE_MEASUREMENT_PER_SECOND_MSB                                ( 0x21 )
#define MSL_SHT31_CORE_ONE_MEASUREMENT_PER_SECOND_HIGH_REPEATABILITY_LSB             ( 0x30 )
#define MSL_SHT31_CORE_ONE_MEASUREMENT_PER_SECOND_MEDIUM_REPEATABILITY_LSB           ( 0x26 )
#define MSL_SHT31_CORE_ONE_MEASUREMENT_PER_SECOND_LOW_REPEATABILITY_LSB              ( 0x2D )
#define MSL_SHT31_CORE_TWO_MEASUREMENT_PER_SECOND_MSB                                ( 0x22 )
#define MSL_SHT31_CORE_TWO_MEASUREMENT_PER_SECOND_HIGH_REPEATABILITY_LSB             ( 0x36 )
#define MSL_SHT31_CORE_TWO_MEASUREMENT_PER_SECOND_MEDIUM_REPEATABILITY_LSB           ( 0x20 )
#define MSL_SHT31_CORE_TWO_MEASUREMENT_PER_SECOND_LOW_REPEATABILITY_LSB              ( 0x2B )
#define MSL_SHT31_CORE_FOUR_MEASUREMENT_PER_SECOND_MSB                               ( 0x23 )
#define MSL_SHT31_CORE_FOUR_MEASUREMENT_PER_SECOND_HIGH_REPEATABILITY_LSB            ( 0x34 )
#define MSL_SHT31_CORE_FOUR_MEASUREMENT_PER_SECOND_MEDIUM_REPEATABILITY_LSB          ( 0x22 )
#define MSL_SHT31_CORE_FOUR_MEASUREMENT_PER_SECOND_LOW_REPEATABILITY_LSB             ( 0x29 )
#define MSL_SHT31_CORE_TEN_MEASUREMENT_PER_SECOND_MSB                                ( 0x27 )
#define MSL_SHT31_CORE_TEN_MEASUREMENT_PER_SECOND_HIGH_REPEATABILITY_LSB             ( 0x37 )
#define MSL_SHT31_CORE_TEN_MEASUREMENT_PER_SECOND_MEDIUM_REPEATABILITY_LSB           ( 0x21 )
#define MSL_SHT31_CORE_TEN_MEASUREMENT_PER_SECOND_LOW_REPEATABILITY_LSB              ( 0x2A )

#define MSL_SHT31_CORE_PERIODIC_DATA_ACQUISION_DISABLE_COMMAND_MSB                   ( 0x30 )
#define MSL_SHT31_CORE_PERIODIC_DATA_ACQUISION_DISABLE_COMMAND_LSB                   ( 0x93 )

#define MSL_SHT31_CORE_PERIODIC_DATA_ACQUISION_COMMAND_MSB                           ( 0xE0 )
#define MSL_SHT31_CORE_PERIODIC_DATA_ACQUISION_COMMAND_LSB                           ( 0x00 )

typedef struct
{
  uint8_t ucDeviceID;
  uint8_t ucDeviceAddress;

} xMSLSHT31Device_t;

typedef enum 
{
  eHeaterEnable = MSL_SHT31_CORE_HEATER_ENABLE_LSB,
  eHeaterDisable = MSL_SHT31_CORE_HEATER_DISABLE_LSB,
}eHeaterState_t;

typedef enum 
{
  eRepeatabilityHigh = 0,
  eRepeatabilityMedium = 1,
  eRepeatabilityLow = 2,
}eRepeatability_t;

typedef enum 
{
  eClockStretchingEnable = MSL_SHT31_CORE_CLOCK_STRETCHING_ENABLE_MSB,
  eClockStretchingDisable = MSL_SHT31_CORE_CLOCK_STRETCHING_DISABLE_MSB,
}eClockStretching_t;

typedef enum 
{
  eHalfMeasurementPerSecond = MSL_SHT31_CORE_HALF_MEASUREMENT_PER_SECOND_MSB,
  eOneMeasurementPerSecond = MSL_SHT31_CORE_ONE_MEASUREMENT_PER_SECOND_MSB,
  eTwoMeasurementPerSecond = MSL_SHT31_CORE_TWO_MEASUREMENT_PER_SECOND_MSB,
  eFourMeasurementPerSecond = MSL_SHT31_CORE_FOUR_MEASUREMENT_PER_SECOND_MSB,
  eTenMeasurementPerSecond = MSL_SHT31_CORE_TEN_MEASUREMENT_PER_SECOND_MSB,
}eMeasurementPerSecond_t;

eMSLReturnResponse_t eMSLSHT31CoreART( xMSLSHT31Device_t *pxMSLSHT31Device );

eMSLReturnResponse_t eMSLSHT31CoreHeater( xMSLSHT31Device_t *pxMSLSHT31Device, eHeaterState_t eHeaterState );

eMSLReturnResponse_t eMSLSHT31CoreReset( xMSLSHT31Device_t *pxMSLSHT31Device );

eMSLReturnResponse_t eMSLSHT31CoreResetThroughGeneralCall( xMSLSHT31Device_t *pxMSLSHT31Device );

/*Clear flags usAlertPendingStatus, usHumidityTrackingAlert, usTemperatureTrackingAlert and usSystemResetDetected*/
eMSLReturnResponse_t eMSLSHT31CoreClearStatusRegister( xMSLSHT31Device_t *pxMSLSHT31Device );

eMSLReturnResponse_t eMSLSHT31CorePeriodicDataAcquisitionDisable( xMSLSHT31Device_t *pxMSLSHT31Device );

eMSLReturnResponse_t eMSLSHT31CorePeriodicDataAcquisition( xMSLSHT31Device_t *pxMSLSHT31Device, float *pfTemperatureValue, float *pfHumidityValue );

eMSLReturnResponse_t eMSLSHT31CorePeriodicDataAcquisitionEnable( xMSLSHT31Device_t *pxMSLSHT31Device, eMeasurementPerSecond_t eMeasurementPerSecond, eRepeatability_t eRepeatability );

eMSLReturnResponse_t eMSLSHT31CoreSingleShotDataAcquisition( xMSLSHT31Device_t *pxMSLSHT31Device, eClockStretching_t eClockStretching, eRepeatability_t eRepeatability, float *pfTemperatureValue, float *pfHumidityValue );

eMSLReturnResponse_t eMSLSHT31CoreStatusRegister( xMSLSHT31Device_t *pxMSLSHT31Device, uint16_t *pucStatusRegisterValue );

eMSLReturnResponse_t eMSLSHT31CoreSendCommand( xMSLSHT31Device_t *pxMSLSHT31Device, uint8_t ucCommandMSB, uint8_t ucCommandLSB );

eMSLReturnResponse_t eMSLSHT31CoreDataAcquisition( xMSLSHT31Device_t *pxMSLSHT31Device, float *pfTemperatureValue, float *pfHumidityValue );

eMSLReturnResponse_t eMSLSHT31CoreCRCValidation( uint8_t *pucDataBuffer, uint8_t ucDataBufferLength, uint8_t ucReceivedCRCValue );

eMSLReturnResponse_t eMSLSHT31CoreCRCCalculation( uint8_t *pucDataBuffer, uint8_t ucDataBufferLength, uint8_t *pucCalculatedCRCValue );

#endif
