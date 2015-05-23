#ifndef stepper_h

#define stepper_h

#include <avr/io.h>
#include <stdlib.h>

#define MOTOR_FRONT_RIGHT_STEP	PORTD^=(1<<7)	
#define MOTOR_BACK_RIGHT_STEP	PORTC^=(1<<6)	
#define MOTOR_BACK_LEFT_STEP	PORTB^=(1<<3)	
#define MOTOR_FRONT_LEFT_STEP	PORTB^=(1<<1)	

#define MOTOR_FRONT_RIGHT_CLOCKWISE	PORTC|=(1<<5)
#define MOTOR_FRONT_RIGHT_COUNTERCLOCKWISE	PORTC&=~(1<<5)
#define MOTOR_BACK_RIGHT_CLOCKWISE	PORTC|=(1<<7)
#define MOTOR_BACK_RIGHT_COUNTERCLOCKWISE	PORTC&=~(1<<7)
#define MOTOR_BACK_LEFT_CLOCKWISE	PORTB|=(1<<2)
#define MOTOR_BACK_LEFT_COUNTERCLOCKWISE	PORTB&=~(1<<2)
#define MOTOR_FRONT_LEFT_CLOCKWISE	PORTB|=(1<<0)
#define MOTOR_FRONT_LEFT_COUNTERCLOCKWISE	PORTB&=~(1<<0)

#define MOTOR_FRONT_RIGHT	0
#define MOTOR_BACK_RIGHT	1
#define MOTOR_BACK_LEFT		2
#define	MOTOR_FRONT_LEFT	3

#define REVERSE			-2
#define COUNTERCLOCKWISE	-1
#define	STOP			0
#define CLOCKWISE		1
#define FORWARD			2

void initMotors();
void setMotorDir(uint8_t motor, int8_t dir);
void stepMotors(uint16_t count);

#endif
