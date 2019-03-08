![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Diff_Press Click

- **CIC Prefix**  : DIFFPRESS
- **Author**      : Aleksandar Paunovic
- **Verison**     : 1.0.0
- **Date**        : Nov 2018.

---

### Software Support

We provide a library for the Diff_Press Click on our [LibStock](https://libstock.mikroe.com/projects/view/2665/diff-press-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

 Library contains function for reading raw ADC data and function for reading data in [kPa]

Key functions :

- ``` uint16_t diffpress_getAdcData( void ) ```         - reads raw ADC data from device
- ``` float diffpress_getPressureDifference( void ) ``` - calculates pressure difference from raw ADC data
- ```  ``` - 

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes LOG and I2C
- Application Initialization - Initializes I2C driver
- Application Task - Logs pressure difference


```.c

void applicationTask( )
{
    pressureDifference = diffpress_getPressureDifference( );

    FloatToStr( pressureDifference, text );
    
    mikrobus_logWrite( "pressure difference : ", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_TEXT );
    mikrobus_logWrite( " kPa", _LOG_LINE );

    Delay_ms(100);
}

```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2665/diff-press-click) page.

Other mikroE Libraries used in the example:

- I2C
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
