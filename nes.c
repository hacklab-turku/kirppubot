#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "nes.h"

void nessetup()
{
	DDRA=(0<<DATA)|(1<<CLOCK)|(1<<LATCH);//0b011;
	PORTA=(1<<CLOCK); //HIGH
}

uint8_t nesread()
{
	uint8_t nes;
	uint8_t i;
	//reset shift registers
	PORTA|=(1<<LATCH); //HIGH
	_delay_us(NESDELAY);
	PORTA&=~(1<<LATCH); //LOW
	//insert bits into variable
	for(i=0;i<8;i++)
	{
		nes=(nes<<1)|((PINA>>(DATA))&0x1);
		//clock next bit in
		_delay_us(NESDELAY);
		PORTA|=(1<<CLOCK); //HIGH
		_delay_us(NESDELAY);
		PORTA&=~(1<<CLOCK); //LOW
	}
	return ~nes;
}

