#ifndef __MSL_PCF8574_CORE_H
#define __MSL_PCF8574_CORE_H

#include "stdint.h"
#include "MSL_Core.h"

#define PCF8574_WRITE_READ_MASK								   	  			                     ( 0x01 )
#define PCF8574_WRITE 										   				                           ( 0x00 )
#define PCF8574_READ 										   				                             ( 0x01 )

#define PCF8574_A0_MASK 													                             ( 0x02 )
#define PCF8574_A1_MASK 											    	                           ( 0x04 )
#define PCF8574_A2_MASK 													                             ( 0x08 )

#define PCF8574_FIXED_ADDRESS_MASK	 										                       ( 0xF0 )
#define PCF8574_PCF8574_FIXED_ADDRESS 										                     ( 0x40 )
#define PCF8574_PCF8574A_FIXED_ADDRESS 										                     ( 0x70 )

typedef struct
{
  uint8_t ucDeviceID;
} eMSLPCF8574Device_t;

extern eMSLReturnResponse_t eMSLPCF8574Send( eMSLPCF8574Device_t *peMSLPCF8574Device, uint8_t ucWriteBuffer );
extern eMSLReturnResponse_t eMSLPCF8574Receive( eMSLPCF8574Device_t *peMSLPCF8574Device, uint8_t *ucReadBuffer );

#endif
