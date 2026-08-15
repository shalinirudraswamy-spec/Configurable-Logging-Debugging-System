#ifndef HEADER_H
#define HEADER_H

#include <LPC21xx.h>

void uart0_init(unsigned int baud);
void uart0_tx(unsigned char data);
void uart0_string(char *str);

void led_init(void);
void led_on(unsigned int led);
void led_off(unsigned int led);

#define ENABLE_INFO
#define ENABLE_DEBUG
#define ENABLE_ERROR

#ifdef ENABLE_INFO
#define LOG_INFO(msg) do { uart0_string("[INFO] "); uart0_string(msg); uart0_string("\r\n"); } while(0)
#else
#define LOG_INFO(msg)
#endif

#ifdef ENABLE_DEBUG
#define LOG_DEBUG(msg) do { uart0_string("[DEBUG] "); uart0_string(msg); uart0_string("\r\n"); } while(0)
#else
#define LOG_DEBUG(msg)
#endif

#ifdef ENABLE_ERROR
#define LOG_ERROR(msg) do { uart0_string("[ERROR] "); uart0_string(msg); uart0_string("\r\n"); } while(0)
#else
#define LOG_ERROR(msg)
#endif

#endif
