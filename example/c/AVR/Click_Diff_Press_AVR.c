/*
Example for Diff_Press Click

    Date          : Nov 2018.
    Author        : Aleksandar Paunovic

Test configuration AVR :
    
    MCU              : ATMEGA32
    Dev. Board       : EasyAVR v7 
    AVR Compiler ver : v7.0.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes LOG and I2C
- Application Initialization - Initializes I2C driver
- Application Task - Logs pressure difference
*/

#include "Click_Diff_Press_types.h"
#include "Click_Diff_Press_config.h"


char text[100];
float pressureDifference;


void systemInit( )
{
    mikrobus_i2cInit( _MIKROBUS1, &_DIFFPRESS_I2C_CFG[0] );

    mikrobus_logInit( _LOG_USBUART, 9600 );

    Delay_ms(100);
    
    mikrobus_logWrite( " sys init done ", _LOG_LINE );
}

void applicationInit( )
{
    diffpress_i2cDriverInit( (T_DIFFPRESS_P)&_MIKROBUS1_GPIO, (T_DIFFPRESS_P)&_MIKROBUS1_I2C, _DIFFPRESS_DEVICE_ADDRESS );
    
    Delay_ms(500);
    
    mikrobus_logWrite( " app init done ", _LOG_LINE );
}

void applicationTask( )
{
    pressureDifference = diffpress_getPressureDifference( );

    FloatToStr( pressureDifference, text );
    
    mikrobus_logWrite( "pressure difference : ", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_TEXT );
    mikrobus_logWrite( " kPa", _LOG_LINE );

    Delay_ms(100);
}

void main( )
{
    systemInit( );
    applicationInit( );
    
    while (1)
    {
        applicationTask( );
    }
}