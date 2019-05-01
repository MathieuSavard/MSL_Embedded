#ifndef __MSLCORE_H
#define __MSLCORE_H

#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define USHRT_LSB_BYTE_MASK                                                    ( UCHAR_MAX )
#define USHRT_MSB_BYTE_MASK                                                    ( USHRT_MAX - UCHAR_MAX )

#define USHRT_LSB_BYTE( USHRT )                                                ( USHRT & USHRT_LSB_BYTE_MASK )
#define USHRT_MSB_BYTE( USHRT )                                                ( ( USHRT & USHRT_MSB_BYTE_MASK ) >> CHAR_BIT )

#define USHRT_UCHAR_CONCATENATION( UCHAR_MSB, UCHAR_LSB )                      ( ( USHRT_MSB_BYTE_MASK & ( UCHAR_MSB << CHAR_BIT ) ) | UCHAR_LSB )

typedef enum eMSLReturnResponse{
  eMSLSuccess = 0,
  eMSLError = 1,
}eMSLReturnResponse_t;

#endif
