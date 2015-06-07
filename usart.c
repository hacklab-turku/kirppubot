#include "./usart.h"
#include "./nes.h"

volatile uint8_t data=0x0;

void initUSART()
{
	UCSR1B|=(1<<RXCIE1)|(1<<RXEN1)|(1<<TXEN1)|(1<<UCSZ11)|(1<<UCSZ10); //rx interrupt, enable rx/tx, 8-bit characters
	UBRR1=103;	//115200 bps
}

SIGNAL(USART1_RX_vect)
{
	data=UDR1;
	UDR1=data;	//echo recieved message back
	switch(data)
	{
		case 'w':
			data=(1<<BUTTON_UP);
			break;
		case 's':
			data=(1<<BUTTON_DOWN);
			break;
		case 'a':
			data=(1<<BUTTON_LEFT);
			break;
		case 'd':
			data=(1<<BUTTON_RIGHT);
			break;
	}
}

uint8_t getCommand()
{
	return data;
}
