#include <LPC21xx.h>
#include "header.h"

void uart0_init(unsigned int baud)
{
    unsigned int pclk;
    unsigned int u0dll;

    pclk = 15000000;

    u0dll = pclk / (16 * baud);

    PINSEL0 = 0x00000005;

    U0LCR = 0x83;

    U0DLL = u0dll & 0xFF;

    U0DLM = (u0dll >> 8) & 0xFF;

    U0LCR = 0x03;
}

void uart0_tx(unsigned char data)
{
    U0THR = data;

    while((U0LSR & 0x20) == 0);
}

void uart0_string(char *str)
{
    while(*str != '\0')
    {
        uart0_tx(*str);
        str++;
    }
}
