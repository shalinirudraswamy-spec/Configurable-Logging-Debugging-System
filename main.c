#include "header.h"
#include "delay.h"

int main(void)
{
    uart0_init(9600);

    led_init();

    LOG_INFO("System Started");

    LOG_DEBUG("UART0 Initialized");

    LOG_DEBUG("LED GPIO Initialized");

    led_on(0);

    LOG_INFO("LED1 ON");

    LOG_DEBUG("LED1 connected to P0.16");

    delay_ms(500);

    led_off(0);

    LOG_INFO("LED1 OFF");

    led_on(1);

    LOG_INFO("LED2 ON");

    LOG_DEBUG("LED2 connected to P0.17");

    delay_ms(500);

    led_off(1);

    LOG_INFO("LED2 OFF");

    led_on(2);

    LOG_INFO("LED3 ON");

    LOG_DEBUG("LED3 connected to P0.18");

    delay_ms(500);

    led_off(2);

    LOG_INFO("LED3 OFF");

    led_on(3);

    LOG_INFO("LED4 ON");

    LOG_DEBUG("LED4 connected to P0.19");

    delay_ms(500);

    led_off(3);

    LOG_INFO("LED4 OFF");

    LOG_ERROR("Test error message");

    while(1)
    {
        led_on(0);

        LOG_DEBUG("System monitoring");

        delay_ms(500);

        led_off(0);

        delay_ms(500);
    }
}
