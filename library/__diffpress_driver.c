/*
    __diffpress_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__diffpress_driver.h"
#include "__diffpress_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* device address */
const uint8_t _DIFFPRESS_DEVICE_ADDRESS = 0x4D;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __DIFFPRESS_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __DIFFPRESS_DRV_SPI__

void diffpress_spiDriverInit(T_DIFFPRESS_P gpioObj, T_DIFFPRESS_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __DIFFPRESS_DRV_I2C__

void diffpress_i2cDriverInit(T_DIFFPRESS_P gpioObj, T_DIFFPRESS_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __DIFFPRESS_DRV_UART__

void diffpress_uartDriverInit(T_DIFFPRESS_P gpioObj, T_DIFFPRESS_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

uint16_t diffpress_getAdcData( void )
{
    uint16_t adcData_;
    uint8_t readBuffer[2];
    
    hal_i2cStart( );
    hal_i2cRead( _slaveAddress, readBuffer, 2, END_MODE_STOP );
    
    adcData_ = readBuffer[0];
    adcData_ <<= 8;
    adcData_ |= readBuffer[1];
    
    return adcData_;
}

float diffpress_getPressureDifference( void )
{
    float pressureDifference_;
    uint16_t adcData;
    
    adcData = diffpress_getAdcData( );
    
    pressureDifference_ = (float)adcData - 2048;
    pressureDifference_ /= 2048;
    pressureDifference_ *= 3.5;
    
    return pressureDifference_;
}

/* -------------------------------------------------------------------------- */
/*
  __diffpress_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */