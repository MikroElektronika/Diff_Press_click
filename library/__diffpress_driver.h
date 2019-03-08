/*
    __diffpress_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __diffpress_driver.h
@brief    Diff_Press Driver
@mainpage Diff_Press Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   DIFFPRESS
@brief      Diff_Press Click Driver
@{

| Global Library Prefix | **DIFFPRESS** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2018.**      |
| Developer             | **Aleksandar Paunovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _DIFFPRESS_H_
#define _DIFFPRESS_H_

/** 
 * @macro T_DIFFPRESS_P
 * @brief Driver Abstract type 
 */
#define T_DIFFPRESS_P    const uint8_t*

/** @defgroup DIFFPRESS_COMPILE Compilation Config */              /** @{ */

// #define   __DIFFPRESS_DRV_SPI__                            /**<     @macro __DIFFPRESS_DRV_SPI__  @brief SPI driver selector */
   #define   __DIFFPRESS_DRV_I2C__                            /**<     @macro __DIFFPRESS_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __DIFFPRESS_DRV_UART__                           /**<     @macro __DIFFPRESS_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup DIFFPRESS_VAR Variables */                           /** @{ */

/* device address */
extern const uint8_t _DIFFPRESS_DEVICE_ADDRESS;

                                                                       /** @} */
/** @defgroup DIFFPRESS_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup DIFFPRESS_INIT Driver Initialization */              /** @{ */

#ifdef   __DIFFPRESS_DRV_SPI__
void diffpress_spiDriverInit(T_DIFFPRESS_P gpioObj, T_DIFFPRESS_P spiObj);
#endif
#ifdef   __DIFFPRESS_DRV_I2C__
void diffpress_i2cDriverInit(T_DIFFPRESS_P gpioObj, T_DIFFPRESS_P i2cObj, uint8_t slave);
#endif
#ifdef   __DIFFPRESS_DRV_UART__
void diffpress_uartDriverInit(T_DIFFPRESS_P gpioObj, T_DIFFPRESS_P uartObj);
#endif
                                                                       /** @} */
/** @defgroup DIFFPRESS_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Reading raw ADC data
 *
 * @param[out] uint16_t adcData_ - raw ADC data
 *
 * This function reads raw ADC data from device
 */
uint16_t diffpress_getAdcData( void );

/**
 * @brief Calculating pressure difference
 *
 * @param[out] float pressureDifference_ - pressure difference
 *
 * This function calculates pressure difference from raw ADC data
 */
float diffpress_getPressureDifference( void );

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Diff_Press_STM.c
    @example Click_Diff_Press_TIVA.c
    @example Click_Diff_Press_CEC.c
    @example Click_Diff_Press_KINETIS.c
    @example Click_Diff_Press_MSP.c
    @example Click_Diff_Press_PIC.c
    @example Click_Diff_Press_PIC32.c
    @example Click_Diff_Press_DSPIC.c
    @example Click_Diff_Press_AVR.c
    @example Click_Diff_Press_FT90x.c
    @example Click_Diff_Press_STM.mbas
    @example Click_Diff_Press_TIVA.mbas
    @example Click_Diff_Press_CEC.mbas
    @example Click_Diff_Press_KINETIS.mbas
    @example Click_Diff_Press_MSP.mbas
    @example Click_Diff_Press_PIC.mbas
    @example Click_Diff_Press_PIC32.mbas
    @example Click_Diff_Press_DSPIC.mbas
    @example Click_Diff_Press_AVR.mbas
    @example Click_Diff_Press_FT90x.mbas
    @example Click_Diff_Press_STM.mpas
    @example Click_Diff_Press_TIVA.mpas
    @example Click_Diff_Press_CEC.mpas
    @example Click_Diff_Press_KINETIS.mpas
    @example Click_Diff_Press_MSP.mpas
    @example Click_Diff_Press_PIC.mpas
    @example Click_Diff_Press_PIC32.mpas
    @example Click_Diff_Press_DSPIC.mpas
    @example Click_Diff_Press_AVR.mpas
    @example Click_Diff_Press_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __diffpress_driver.h

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