#include "./usart.h"

void initUSART()
{
	UCSR1B|=(1<<RXCIE1)|(1<<RXEN1)|(1<<TXEN1)|(1<<UCSZ11)|(1<<UCSZ10); //rx interrupt, enable rx/tx, 8-bit characters
	UBRR1=8;	//115200 bps
	UDR1='a';
}

SIGNAL(USART1_RX_vect)
{
	uint8_t data=UDR1;
	UDR1=data;	//echo recieved message back
}
