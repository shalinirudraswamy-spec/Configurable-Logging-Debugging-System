# Design and Implementation of a Configurable Logging and Debugging System Using C Preprocessor Directives

## Objective

To design and implement a configurable logging and debugging system using C preprocessor directives on the LPC2129 microcontroller.

## Hardware Requirements

- LPC2129 Development Board
- LED
- Resistor
- UART interface
- Power supply

## Software Requirements

- Embedded C
- ARM/LPC21xx compiler
- Keil IDE

## Methodology

The system uses C preprocessor directives to configure different logging levels such as INFO, DEBUG and ERROR.

The LPC2129 performs the required application operation and generates log messages for important system events. The logging messages are transmitted through UART for monitoring and debugging.

The required logging levels can be enabled or disabled during compilation using preprocessor directives.

## Features

- Configurable logging
- INFO messages
- DEBUG messages
- ERROR messages
- Compile-time configuration
- UART-based monitoring
- LPC2129 hardware implementation

## Project Files

- main.c – Main source code
- README.md – Project documentation

## Conclusion

The project provides a simple and configurable method for monitoring and debugging an embedded system using C preprocessor directives.
