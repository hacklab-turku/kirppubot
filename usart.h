#ifndef usart_h

#define usart_h

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

void initUSART();
uint8_t getCommand();

#endif
