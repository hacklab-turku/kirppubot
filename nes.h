#ifndef NES_H_INCLUDED
#define NES_H_INCLUDED

#define CLOCK 0
#define LATCH 1
#define DATA 2
#define NESDELAY 70 //microseconds

#define BUTTON_A 	7
#define BUTTON_B	6
#define BUTTON_SELECT	5
#define BUTTON_START	4
#define BUTTON_UP	3
#define BUTTON_DOWN	2
#define BUTTON_LEFT	1
#define BUTTON_RIGHT	0

void nessetup();
uint8_t nesread();
void nesdebug();

#endif
