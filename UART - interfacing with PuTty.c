/*******************************************************

Project : Orbit Lab 6 ATE (UART)
Version : 1.0
Date    : 2/20/2013
Author  : Brian Zufelt / Craig Kief
Company : COSMIAC/UNM
Comments:
This source provides an introduction to communication concepts.
The student will enable one of the GPIO ports to function
as a UART. This will allow the board to have a basic serial
port to transmit/ Receive data/commands.

******************************************************
Chip type               : ARM TM4C123GH6PM
Program type            : Firmware
Core Clock frequency    : 80.000000 MHz
*******************************************************/

// Define needed for pin_map.h
#define PART_TM4C123GH6PM

#include <stdbool.h>
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "inc/hw_i2c.h"
#include "driverlib/i2c.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"

int main(void) {

    long C;         // Temp Character holder

SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);  
// Set up Clock

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);        // Enable UART hardware
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);        // Enable Pin hardware

    GPIOPinConfigure(GPIO_PA0_U0RX);        // Configure GPIO pin for UART RX line
    GPIOPinConfigure(GPIO_PA1_U0TX);        // Configure GPIO Pin for UART TX line
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);     // Set Pins for UART

    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,  // Configure UART to 8N1 at 115200bps
        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    while (1)
    {

        UARTCharPut(UART0_BASE, '\n');        //
        UARTCharPut(UART0_BASE, '\n');        //
        UARTCharPut(UART0_BASE, '\r');        //
        UARTCharPut(UART0_BASE, 'E');        //
        UARTCharPut(UART0_BASE, 'n');        //
        UARTCharPut(UART0_BASE, 't');        //
        UARTCharPut(UART0_BASE, 'e');        //
        UARTCharPut(UART0_BASE, 'r');        //
        UARTCharPut(UART0_BASE, ' ');        //
        UARTCharPut(UART0_BASE, 'A');        //    -----> Print Start Text
        UARTCharPut(UART0_BASE, ' ');        //
        UARTCharPut(UART0_BASE, 'C');        //
        UARTCharPut(UART0_BASE, 'h');        //
        UARTCharPut(UART0_BASE, 'a');        //
        UARTCharPut(UART0_BASE, 'r');        //
        UARTCharPut(UART0_BASE, ':');        //
        UARTCharPut(UART0_BASE, '\n');        //
        UARTCharPut(UART0_BASE, '\n');        //
        UARTCharPut(UART0_BASE, '\r');        //

        C = UARTCharGet(UART0_BASE);

        UARTCharPut(UART0_BASE, '\n');        //
        UARTCharPut(UART0_BASE, '\r');        //
        UARTCharPut(UART0_BASE, 'Y');        //
        UARTCharPut(UART0_BASE, 'o');        //
        UARTCharPut(UART0_BASE, 'u');        //
        UARTCharPut(UART0_BASE, ' ');        //
        UARTCharPut(UART0_BASE, 'E');        //
        UARTCharPut(UART0_BASE, 'n');        //
        UARTCharPut(UART0_BASE, 't');        //    -----> Print Start Text
        UARTCharPut(UART0_BASE, 'e');        //
        UARTCharPut(UART0_BASE, 'r');        //
        UARTCharPut(UART0_BASE, 'e');        //
        UARTCharPut(UART0_BASE, 'd');        //
        UARTCharPut(UART0_BASE, ':');        //
        UARTCharPut(UART0_BASE, '-');        //
        UARTCharPut(UART0_BASE, '>');        //
        UARTCharPut(UART0_BASE, ' ');        //
        UARTCharPut(UART0_BASE, C);            // <------- Notice the use of a variable
        UARTCharPut(UART0_BASE, '\n');        //
        UARTCharPut(UART0_BASE, '\n');        //
        UARTCharPut(UART0_BASE, '\r');        //
    }
}
