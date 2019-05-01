#include "MSLSHT31Core.h"
#include "MSLSHT31UserDefine.h"

eMSLReturnResponse_t eMSLSHT31CoreART( xMSLSHT31Device_t *pxMSLSHT31Device )
{
	if( pxMSLSHT31Device == NULL )
	{
		return eMSLError;
	}
	
    return eMSLSHT31CoreSendCommand( pxMSLSHT31Device, MSL_SHT31_CORE_ART_COMMAND_MSB, MSL_SHT31_CORE_ART_COMMAND_LSB );
}

eMSLReturnResponse_t eMSLSHT31CoreHeater( xMSLSHT31Device_t *pxMSLSHT31Device, eHeaterState_t eHeaterState )
{
	if( pxMSLSHT31Device == NULL )
	{
		return eMSLError;
	}
	
    return eMSLSHT31CoreSendCommand( pxMSLSHT31Device, MSL_SHT31_CORE_HEATER_COMMAND_MSB, eHeaterState );
}

eMSLReturnResponse_t eMSLSHT31CoreReset( xMSLSHT31Device_t *pxMSLSHT31Device )
{
	if( pxMSLSHT31Device == NULL )
	{
		return eMSLError;
	}
	
    return eMSLSHT31CoreSendCommand( pxMSLSHT31Device, MSL_SHT31_CORE_RESET_COMMAND_MSB, MSL_SHT31_CORE_RESET_COMMAND_LSB );
}

eMSLReturnResponse_t eMSLSHT31CoreClearStatusRegister( xMSLSHT31Device_t *pxMSLSHT31Device )
{
	if( pxMSLSHT31Device == NULL )
	{
		return eMSLError;
	}
	
    return eMSLSHT31CoreSendCommand( pxMSLSHT31Device, MSL_SHT31_CORE_CLEAR_STATUS_REGISTER_COMMAND_MSB, MSL_SHT31_CORE_CLEAR_STATUS_REGISTER_COMMAND_LSB );
}

eMSLReturnResponse_t eMSLSHT31CorePeriodicDataAcquisitionDisable( xMSLSHT31Device_t *pxMSLSHT31Device )
{
	if( pxMSLSHT31Device == NULL )
	{
		return eMSLError;
	}
	
    return eMSLSHT31CoreSendCommand( pxMSLSHT31Device, MSL_SHT31_CORE_PERIODIC_DATA_ACQUISION_DISABLE_COMMAND_MSB, MSL_SHT31_CORE_PERIODIC_DATA_ACQUISION_DISABLE_COMMAND_LSB );
}

eMSLReturnResponse_t eMSLSHT31CoreResetThroughGeneralCall( xMSLSHT31Device_t *pxMSLSHT31Device )
{
    eMSLReturnResponse_t eMSLReturnResponse = eMSLError;
    uint8_t ucCommunicationBuffer[ MSL_SHT31_CORE_ADDRESS_LENGTH + MSL_SHT31_CORE_COMMAND_LENGTH ] = { 0 };
    uint8_t ucCommunicationBufferLength = MSL_SHT31_CORE_ADDRESS_LENGTH + MSL_SHT31_CORE_RESET_THROUGH_GENERAL_CALL_COMMAND_SECOND_BYTE_LENGTH;
    
    if( pxMSLSHT31Device == NULL)
    {
        return eMSLError;
    }
    
    ucCommunicationBuffer[ MSL_SHT31_CORE_ADDRESS_POS ] = MSL_SHT31_CORE_RESET_THROUGH_GENERAL_CALL_COMMAND_ADDRESS_BYTE;
    ucCommunicationBuffer[ MSL_SHT31_CORE_COMMAND_POS_MSB ] = MSL_SHT31_CORE_RESET_THROUGH_GENERAL_CALL_COMMAND_SECOND_BYTE;
    
    eMSLReturnResponse = eMSLSHT31UserDefineSend( pxMSLSHT31Device, ucCommunicationBuffer, ucCommunicationBufferLength );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    return eMSLSuccess;
}

eMSLReturnResponse_t eMSLSHT31CorePeriodicDataAcquisition( xMSLSHT31Device_t *pxMSLSHT31Device, float *pfTemperatureValue, float *pfHumidityValue )
{
    eMSLReturnResponse_t eMSLReturnResponse = eMSLError;
    
	if( pxMSLSHT31Device == NULL )
	{
		return eMSLError;
	}
    
    eMSLReturnResponse = eMSLSHT31CoreSendCommand( pxMSLSHT31Device, MSL_SHT31_CORE_PERIODIC_DATA_ACQUISION_COMMAND_MSB, MSL_SHT31_CORE_PERIODIC_DATA_ACQUISION_COMMAND_LSB );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    eMSLReturnResponse = eMSLSHT31CoreDataAcquisition( pxMSLSHT31Device, pfTemperatureValue, pfHumidityValue );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    return eMSLSuccess;
}

eMSLReturnResponse_t eMSLSHT31CorePeriodicDataAcquisitionEnable( xMSLSHT31Device_t *pxMSLSHT31Device, eMeasurementPerSecond_t eMeasurementPerSecond, eRepeatability_t eRepeatability )
{
    eMSLReturnResponse_t eMSLReturnResponse = eMSLError;
    uint8_t ucCommandLSB = 0x00;
    
	if( pxMSLSHT31Device == NULL )
	{
		return eMSLError;
	}
	
    if( eMeasurementPerSecond == eHalfMeasurementPerSecond )
    {
        switch( eRepeatability )
        {
        case eRepeatabilityHigh:
            ucCommandLSB = MSL_SHT31_CORE_HALF_MEASUREMENT_PER_SECOND_HIGH_REPEATABILITY_LSB;
            break;
        case eRepeatabilityMedium:
            ucCommandLSB = MSL_SHT31_CORE_HALF_MEASUREMENT_PER_SECOND_MEDIUM_REPEATABILITY_LSB;
            break;
        case eRepeatabilityLow:
            ucCommandLSB = MSL_SHT31_CORE_HALF_MEASUREMENT_PER_SECOND_LOW_REPEATABILITY_LSB;
            break;
        };
    }
    else if( eMeasurementPerSecond == eOneMeasurementPerSecond )
    {
        switch( eRepeatability )
        {
        case eRepeatabilityHigh:
            ucCommandLSB = MSL_SHT31_CORE_ONE_MEASUREMENT_PER_SECOND_HIGH_REPEATABILITY_LSB;
            break;
        case eRepeatabilityMedium:
            ucCommandLSB = MSL_SHT31_CORE_ONE_MEASUREMENT_PER_SECOND_MEDIUM_REPEATABILITY_LSB;
            break;
        case eRepeatabilityLow:
            ucCommandLSB = MSL_SHT31_CORE_ONE_MEASUREMENT_PER_SECOND_LOW_REPEATABILITY_LSB;
            break;
        };
    }
    else if( eMeasurementPerSecond == eTwoMeasurementPerSecond )
    {
        switch( eRepeatability )
        {
        case eRepeatabilityHigh:
            ucCommandLSB = MSL_SHT31_CORE_TWO_MEASUREMENT_PER_SECOND_HIGH_REPEATABILITY_LSB;
            break;
        case eRepeatabilityMedium:
            ucCommandLSB = MSL_SHT31_CORE_TWO_MEASUREMENT_PER_SECOND_MEDIUM_REPEATABILITY_LSB;
            break;
        case eRepeatabilityLow:
            ucCommandLSB = MSL_SHT31_CORE_TWO_MEASUREMENT_PER_SECOND_LOW_REPEATABILITY_LSB;
            break;
        };
    }
    else if( eMeasurementPerSecond == eFourMeasurementPerSecond )
    {
        switch( eRepeatability )
        {
        case eRepeatabilityHigh:
            ucCommandLSB = MSL_SHT31_CORE_FOUR_MEASUREMENT_PER_SECOND_HIGH_REPEATABILITY_LSB;
            break;
        case eRepeatabilityMedium:
            ucCommandLSB = MSL_SHT31_CORE_FOUR_MEASUREMENT_PER_SECOND_MEDIUM_REPEATABILITY_LSB;
            break;
        case eRepeatabilityLow:
            ucCommandLSB = MSL_SHT31_CORE_FOUR_MEASUREMENT_PER_SECOND_LOW_REPEATABILITY_LSB;
            break;
        };
    }
    else if( eMeasurementPerSecond == eTenMeasurementPerSecond )
    {
        switch( eRepeatability )
        {
        case eRepeatabilityHigh:
            ucCommandLSB = MSL_SHT31_CORE_TEN_MEASUREMENT_PER_SECOND_HIGH_REPEATABILITY_LSB;
            break;
        case eRepeatabilityMedium:
            ucCommandLSB = MSL_SHT31_CORE_TEN_MEASUREMENT_PER_SECOND_MEDIUM_REPEATABILITY_LSB;
            break;
        case eRepeatabilityLow:
            ucCommandLSB = MSL_SHT31_CORE_TEN_MEASUREMENT_PER_SECOND_LOW_REPEATABILITY_LSB;
            break;
        };
    }
    else
    {
        return eMSLError;
    }
    
    eMSLReturnResponse = eMSLSHT31CoreSendCommand( pxMSLSHT31Device, eMeasurementPerSecond, ucCommandLSB );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    return eMSLSuccess;
}

eMSLReturnResponse_t eMSLSHT31CoreSingleShotDataAcquisition( xMSLSHT31Device_t *pxMSLSHT31Device, eClockStretching_t eClockStretching, eRepeatability_t eRepeatability, float *pfTemperatureValue, float *pfHumidityValue)
{
    eMSLReturnResponse_t eMSLReturnResponse = eMSLError;
    uint8_t ucCommandLSB = 0x00;
    
  	if( pxMSLSHT31Device == NULL )
	{
		return eMSLError;
	}
	
    if( eClockStretching == eClockStretchingEnable )
    {
        switch( eRepeatability )
        {
        case eRepeatabilityHigh:
            ucCommandLSB = MSL_SHT31_CORE_COCK_STRETCHING_ENABLE_HIGH_REPEATABILITY_LSB;
            break;
        case eRepeatabilityMedium:
            ucCommandLSB = MSL_SHT31_CORE_COCK_STRETCHING_ENABLE_MEDIUM_REPEATABILITY_LSB;
            break;
        case eRepeatabilityLow:
            ucCommandLSB = MSL_SHT31_CORE_COCK_STRETCHING_ENABLE_LOW_REPEATABILITY_LSB;
            break;
        };
    }
    else if( eClockStretching == eClockStretchingDisable )
    {
        switch( eRepeatability )
        {
        case eRepeatabilityHigh:
            ucCommandLSB = MSL_SHT31_CORE_COCK_STRETCHING_DISABLE_HIGH_REPEATABILITY_LSB;
            break;
        case eRepeatabilityMedium:
            ucCommandLSB = MSL_SHT31_CORE_COCK_STRETCHING_DISABLE_MEDIUM_REPEATABILITY_LSB;
            break;
        case eRepeatabilityLow:
            ucCommandLSB = MSL_SHT31_CORE_COCK_STRETCHING_DISABLE_LOW_REPEATABILITY_LSB;
            break;
        };
    }
    else
    {
        return eMSLError;
    }
    
    eMSLReturnResponse = eMSLSHT31CoreSendCommand( pxMSLSHT31Device, eClockStretching, ucCommandLSB );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    if( eClockStretching == eClockStretchingDisable )
    {
        if( eRepeatability == eRepeatabilityHigh )
        {
            eMSLReturnResponse = eMSLSHT31UserDefineDelay( MSL_SHT31_CORE_MEASUREMENT_DURATION_HIGH_REPEATABILITY );
            if( eMSLReturnResponse != eMSLSuccess )
            {
                return eMSLReturnResponse;
            }
        } else if( eRepeatability == eRepeatabilityMedium )
        {
            eMSLReturnResponse = eMSLSHT31UserDefineDelay( MSL_SHT31_CORE_MEASUREMENT_DURATION_MEDIUM_REPEATABILITY );
            if( eMSLReturnResponse != eMSLSuccess )
            {
                return eMSLReturnResponse;
            }
        } else if( eRepeatability == eRepeatabilityLow )
        {
            eMSLReturnResponse = eMSLSHT31UserDefineDelay( MSL_SHT31_CORE_MEASUREMENT_DURATION_LOW_REPEATABILITY );
            if( eMSLReturnResponse != eMSLSuccess )
            {
                return eMSLReturnResponse;
            }
        } else
        {
            return eMSLError;
        }
        
        eMSLReturnResponse = eMSLSHT31CoreDataAcquisition( pxMSLSHT31Device, pfTemperatureValue, pfHumidityValue );
        if( eMSLReturnResponse != eMSLSuccess )
        {
            return eMSLReturnResponse;
        }
    } else if( eClockStretching == eClockStretchingEnable )
    {
        eMSLReturnResponse = eMSLSHT31CoreDataAcquisition( pxMSLSHT31Device, pfTemperatureValue, pfHumidityValue );
        if( eMSLReturnResponse != eMSLSuccess )
        {
            return eMSLReturnResponse;
        }
    }
    return eMSLSuccess;
}

eMSLReturnResponse_t eMSLSHT31CoreStatusRegister( xMSLSHT31Device_t *pxMSLSHT31Device, uint16_t *pucStatusRegisterValue )
{
    eMSLReturnResponse_t eMSLReturnResponse = eMSLError;
    uint8_t ucCommunicationBuffer[ MSL_SHT31_CORE_ADDRESS_LENGTH + MSL_SHT31_CORE_STATUS_REGISTER_LENGTH + MSL_SHT31_CORE_CRC_LENGTH ] = { 0 };
	uint8_t ucCommunicationBufferLength = MSL_SHT31_CORE_ADDRESS_LENGTH + MSL_SHT31_CORE_STATUS_REGISTER_LENGTH + MSL_SHT31_CORE_CRC_LENGTH;
    
    if( pxMSLSHT31Device == NULL || pucStatusRegisterValue == NULL )
	{
		return eMSLError;
	}
	
    eMSLReturnResponse = eMSLSHT31CoreSendCommand( pxMSLSHT31Device, MSL_SHT31_CORE_STATUS_REGISTER_COMMAND_MSB, MSL_SHT31_CORE_STATUS_REGISTER_COMMAND_LSB );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    ucCommunicationBuffer[ MSL_SHT31_CORE_ADDRESS_POS ] = pxMSLSHT31Device->ucDeviceAddress;
    
    eMSLReturnResponse = eMSLSHT31UserDefineReceive( pxMSLSHT31Device, ucCommunicationBuffer, ucCommunicationBufferLength );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    eMSLReturnResponse = eMSLSHT31CoreCRCValidation( ucCommunicationBuffer + MSL_SHT31_CORE_COMMAND_POS, MSL_SHT31_CORE_COMMAND_LENGTH, ucCommunicationBuffer[ MSL_SHT31_CORE_COMMAND_CRC_POS ] );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    *pucStatusRegisterValue = USHRT_UCHAR_CONCATENATION( ucCommunicationBuffer[ MSL_SHT31_CORE_COMMAND_POS_MSB ], ucCommunicationBuffer[ MSL_SHT31_CORE_COMMAND_POS_LSB ]);
    
    return eMSLSuccess;
}

eMSLReturnResponse_t eMSLSHT31CoreSendCommand( xMSLSHT31Device_t *pxMSLSHT31Device, uint8_t ucCommandMSB, uint8_t ucCommandLSB )
{
    eMSLReturnResponse_t eMSLReturnResponse = eMSLError;
    uint8_t ucCommunicationBuffer[ MSL_SHT31_CORE_ADDRESS_LENGTH + MSL_SHT31_CORE_COMMAND_LENGTH ] = { 0 };
    uint8_t ucCommunicationBufferLength = MSL_SHT31_CORE_ADDRESS_LENGTH + MSL_SHT31_CORE_COMMAND_LENGTH;
    
    if( pxMSLSHT31Device == NULL)
    {
        return eMSLError;
    }
    
    ucCommunicationBuffer[ MSL_SHT31_CORE_ADDRESS_POS ] = pxMSLSHT31Device->ucDeviceAddress;
    ucCommunicationBuffer[ MSL_SHT31_CORE_COMMAND_POS_MSB ] = ucCommandMSB;
    ucCommunicationBuffer[ MSL_SHT31_CORE_COMMAND_POS_LSB ] = ucCommandLSB;
    
    eMSLReturnResponse = eMSLSHT31UserDefineSend( pxMSLSHT31Device, ucCommunicationBuffer, ucCommunicationBufferLength );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    return eMSLSuccess;
}

eMSLReturnResponse_t eMSLSHT31CoreDataAcquisition( xMSLSHT31Device_t *pxMSLSHT31Device, float *pfTemperatureValue, float *pfHumidityValue )
{
    eMSLReturnResponse_t eMSLReturnResponse = eMSLError;
    uint8_t ucCommunicationBuffer[ MSL_SHT31_CORE_ADDRESS_LENGTH + MSL_SHT31_CORE_TEMPERATURE_LENGTH + MSL_SHT31_CORE_HUMIDITY_LENGTH + ( MSL_SHT31_CORE_CRC_LENGTH * 2 ) ] = { 0 };
	uint8_t ucCommunicationBufferLength = MSL_SHT31_CORE_ADDRESS_LENGTH + MSL_SHT31_CORE_TEMPERATURE_LENGTH + MSL_SHT31_CORE_HUMIDITY_LENGTH + ( MSL_SHT31_CORE_CRC_LENGTH * 2 );
    float fTemperatureValue;
    float fHumidityValue;
    
    if( pxMSLSHT31Device == NULL )
    {
        return eMSLError;
    }
    
    ucCommunicationBuffer[ MSL_SHT31_CORE_ADDRESS_POS ] = pxMSLSHT31Device->ucDeviceAddress;
    
    eMSLReturnResponse = eMSLSHT31UserDefineReceive( pxMSLSHT31Device, ucCommunicationBuffer, ucCommunicationBufferLength );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    if( pfTemperatureValue != NULL )
    {
        eMSLReturnResponse = eMSLSHT31CoreCRCValidation( ucCommunicationBuffer + MSL_SHT31_CORE_TEMPERATURE_POS, MSL_SHT31_CORE_TEMPERATURE_LENGTH, ucCommunicationBuffer[ MSL_SHT31_CORE_TEMPERATURE_CRC_POS ] );
        if( eMSLReturnResponse != eMSLSuccess )
        {
            return eMSLReturnResponse;
        }
        
        fTemperatureValue =  ( ( USHRT_MSB_BYTE_MASK & ( ucCommunicationBuffer[ MSL_SHT31_CORE_TEMPERATURE_POS_MSB ] << CHAR_BIT ) ) | ucCommunicationBuffer[ MSL_SHT31_CORE_TEMPERATURE_POS_LSB ] );
        fTemperatureValue /= USHRT_MAX;
        fTemperatureValue *= 175;
        fTemperatureValue -= 45;
        
        *pfTemperatureValue = fTemperatureValue;
    }
    
    if( pfHumidityValue != NULL )
    {
        eMSLReturnResponse = eMSLSHT31CoreCRCValidation( ucCommunicationBuffer + MSL_SHT31_CORE_HUMIDITY_POS, MSL_SHT31_CORE_HUMIDITY_LENGTH, ucCommunicationBuffer[ MSL_SHT31_CORE_HUMIDITY_CRC_POS ] );
        if( eMSLReturnResponse != eMSLSuccess )
        {
            return eMSLReturnResponse;
        }
        
        fHumidityValue = USHRT_UCHAR_CONCATENATION( ucCommunicationBuffer[ MSL_SHT31_CORE_HUMIDITY_POS_MSB ], ucCommunicationBuffer[ MSL_SHT31_CORE_HUMIDITY_POS_LSB ]);
        fHumidityValue /= USHRT_MAX;
        fHumidityValue *= 100;
        
        *pfHumidityValue = fHumidityValue;
    }
    
    return eMSLSuccess;
}

eMSLReturnResponse_t eMSLSHT31CoreCRCValidation( uint8_t *pucDataBuffer, uint8_t pucDataBufferLength, uint8_t ucReceivedCRCValue )
{
    eMSLReturnResponse_t eMSLReturnResponse = eMSLError;
    uint8_t ucCalculatedCRCValue = 0;
    
	if( pucDataBuffer == NULL )
	{
		return eMSLError;
	}
	
    eMSLReturnResponse = eMSLSHT31CoreCRCCalculation( pucDataBuffer, pucDataBufferLength, &ucCalculatedCRCValue );
    if( eMSLReturnResponse != eMSLSuccess )
    {
        return eMSLReturnResponse;
    }
    
    if( ucReceivedCRCValue != ucCalculatedCRCValue )
    {
        return eMSLError;
    }
    
    return eMSLSuccess;
}

eMSLReturnResponse_t eMSLSHT31CoreCRCCalculation( uint8_t *pucDataBuffer, uint8_t ucDataBufferLength, uint8_t *pucCalculatedCRCValue )
{
    if( pucDataBuffer == NULL )
    {
        return eMSLError;
    }
    
    if( pucCalculatedCRCValue == NULL )
    {
        return eMSLError;
    }
    
    *pucCalculatedCRCValue = MSL_SHT31_CORE_CRC_INITIALISATION;
    
    for( uint8_t ucI = 0; ucI < ucDataBufferLength; ucI++ )
    {
        *pucCalculatedCRCValue ^= *pucDataBuffer++;
        
        for ( uint8_t ucJ = 0; ucJ < MSL_SHT31_CORE_CRC_WIDTH; ucJ++ )
        {
            if( *pucCalculatedCRCValue & MSL_SHT31_CORE_CRC_MSB )
            {
                *pucCalculatedCRCValue = ( *pucCalculatedCRCValue << MSL_SHT31_CORE_CRC_LSB ) ^ MSL_SHT31_CORE_CRC_POLYNOMIAL;
            }
            else
            {
                *pucCalculatedCRCValue = ( *pucCalculatedCRCValue << MSL_SHT31_CORE_CRC_LSB );
            }
        }
    }
    
    return eMSLSuccess;
}
