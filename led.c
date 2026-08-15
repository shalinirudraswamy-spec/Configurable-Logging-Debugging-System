#include <LPC21xx.h>
#include "header.h"

void led_init(void)
{
    IODIR0 |= 0x000F0000;

    IOCLR0 = 0x000F0000;
}

void led_on(unsigned int led)
{
    IOSET0 = 1 << (16 + led);
}

void led_off(unsigned int led)
{
    IOCLR0 = 1 << (16 + led);
}
