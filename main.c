#include <LPC21xx.h>

/*====================================================
        CONFIGURATION
====================================================*/

/* Enable or disable required log levels */

#define ENABLE_INFO
#define ENABLE_DEBUG
#define ENABLE_ERROR


/*====================================================
        UART0 FUNCTIONS
====================================================*/

void uart0_init(void)
{
    /* P0.0 = TXD0
       P0.1 = RXD0 */

    PINSEL0 &= ~0x0000000F;
    PINSEL0 |=  0x00000005;

    /* UART0: 8-bit, 1 stop bit, no parity */

    U0LCR = 0x83;

    /*
       Baud rate = 9600
       Assuming PCLK = 15 MHz
    */

    U0DLL = 98;
    U0DLM = 0;

    U0LCR = 0x03;
}


void uart0_tx(char ch)
{
    while((U0LSR & 0x20) == 0);

    U0THR = ch;
}


void uart0_string(char *str)
{
    while(*str != '\0')
    {
        uart0_tx(*str);
        str++;
    }
}


/*====================================================
        CONFIGURABLE LOGGING MACROS
====================================================*/

#ifdef ENABLE_INFO

#define LOG_INFO(msg)           \
do                              \
{                               \
    uart0_string("[INFO] ");    \
    uart0_string(msg);          \
    uart0_string("\r\n");       \
} while(0)

#else

#define LOG_INFO(msg)

#endif


#ifdef ENABLE_DEBUG

#define LOG_DEBUG(msg)          \
do                              \
{                               \
    uart0_string("[DEBUG] ");   \
    uart0_string(msg);          \
    uart0_string("\r\n");       \
} while(0)

#else

#define LOG_DEBUG(msg)

#endif


#ifdef ENABLE_ERROR

#define LOG_ERROR(msg)          \
do                              \
{                               \
    uart0_string("[ERROR] ");   \
    uart0_string(msg);          \
    uart0_string("\r\n");       \
} while(0)

#else

#define LOG_ERROR(msg)

#endif


/*====================================================
        LED FUNCTIONS
====================================================*/

void led_init(void)
{
    /* P0.16 to P0.19 as output */

    IODIR0 |= (0x0F << 16);

    /* LEDs initially OFF */

    IOCLR0 = (0x0F << 16);
}


void led_on(unsigned int led)
{
    IOSET0 = (1 << (16 + led));
}


void led_off(unsigned int led)
{
    IOCLR0 = (1 << (16 + led));
}


/*====================================================
        DELAY FUNCTION
====================================================*/

void delay(unsigned int count)
{
    unsigned int i;

    for(i = 0; i < count; i++)
    {
        ;
    }
}


/*====================================================
        MAIN FUNCTION
====================================================*/

int main(void)
{
    /* Initialize peripherals */

    uart0_init();
    led_init();

    LOG_INFO("System Started");
    LOG_DEBUG("UART0 Initialized");
    LOG_DEBUG("LED GPIO Initialized");


    /* LED 1 */

    led_on(0);

    LOG_INFO("LED1 ON");
    LOG_DEBUG("LED1 connected to P0.16");

    delay(1000000);

    led_off(0);

    LOG_INFO("LED1 OFF");


    /* LED 2 */

    led_on(1);

    LOG_INFO("LED2 ON");
    LOG_DEBUG("LED2 connected to P0.17");

    delay(1000000);

    led_off(1);

    LOG_INFO("LED2 OFF");


    /* LED 3 */

    led_on(2);

    LOG_INFO("LED3 ON");
    LOG_DEBUG("LED3 connected to P0.18");

    delay(1000000);

    led_off(2);

    LOG_INFO("LED3 OFF");


    /* LED 4 */

    led_on(3);

    LOG_INFO("LED4 ON");
    LOG_DEBUG("LED4 connected to P0.19");

    delay(1000000);

    led_off(3);

    LOG_INFO("LED4 OFF");


    /* Test error message */

    LOG_ERROR("Test error message");


    /* Continuous monitoring */

    while(1)
    {
        led_on(0);

        LOG_DEBUG("System monitoring");

        delay(1000000);

        led_off(0);

        delay(1000000);
    }
}
