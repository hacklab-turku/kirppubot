/*
pololu motordriver controller (A4988)

*/

#include "./stepper.h"

int8_t motorDir[4];

void initMotors()
{
	//front right motor
	DDRC|=(1<<5);	//x-dir	as output
	DDRD|=(1<<7);	//x-step as output
	//back right motor
	DDRC|=(1<<7);	//y-dir	as output
	DDRC|=(1<<6);	//y-step as output
	//back left motor
	DDRB|=(1<<2);	//z-dir	as output
	DDRB|=(1<<3);	//z-step as output
	//front right motor
	DDRB|=(1<<0);	//e-dir	as output
	DDRB|=(1<<1);	//e-step as output
	//enables for the motors
	DDRA|=(1<<5);	//z-en as output
	DDRC|=(1<<6);	//xye-en as output
}

void setMotorEnable(uint8_t status)
{
	if(status==0)	//motor disable
	{
		PORTA|=(1<<5);
		PORTD|=(1<<6);
	}
	else	//motor enable
	{
		PORTA&=~(1<<5);
		PORTD&=~(1<<6);
	}

}

void setMotorDir(uint8_t motor, int8_t dir)	//translate desired directions of motors
{
	switch(motor)	//set software values to match desired
	{
		//forward means rotate clockwise
		case MOTOR_FRONT_RIGHT:	
		case MOTOR_BACK_RIGHT:
			if(dir == FORWARD || dir == CLOCKWISE)
				motorDir[motor]=CLOCKWISE;
			else if(dir == REVERSE || dir == COUNTERCLOCKWISE)
				motorDir[motor]=COUNTERCLOCKWISE;
			else
				motorDir[motor]=STOP;
			break;
		
		//forward means counter clockwise
		case MOTOR_BACK_LEFT:
		case MOTOR_FRONT_LEFT:
			if(dir == FORWARD || dir == COUNTERCLOCKWISE)
				motorDir[motor]=COUNTERCLOCKWISE;
			else if(dir == REVERSE || dir == CLOCKWISE)
				motorDir[motor]=CLOCKWISE;
			else
				motorDir[motor]=STOP;
			break;
	}

	switch(motor)	//set output pins to match software
	{
		case MOTOR_FRONT_RIGHT:
			if(motorDir[motor]==1)
				MOTOR_FRONT_RIGHT_CLOCKWISE;
			else
				MOTOR_FRONT_RIGHT_COUNTERCLOCKWISE;	
			break;
		case MOTOR_BACK_RIGHT:
			if(motorDir[motor]==1)
				MOTOR_BACK_RIGHT_CLOCKWISE;
			else
				MOTOR_BACK_RIGHT_COUNTERCLOCKWISE;	
			break;
		case MOTOR_BACK_LEFT:
			if(motorDir[motor]==1)
				MOTOR_BACK_LEFT_CLOCKWISE;
			else
				MOTOR_BACK_LEFT_COUNTERCLOCKWISE;	
			break;
		case MOTOR_FRONT_LEFT:
			if(motorDir[motor]==1)
				MOTOR_FRONT_LEFT_CLOCKWISE;
			else
				MOTOR_FRONT_LEFT_COUNTERCLOCKWISE;	
			break;
	}
	
}

void stepMotors()	//step all motors at once
{
	for(uint8_t j=0;j<2;j++)
		for(uint8_t i=0;i<=3;i++)	//for all the motors
		{
			if(motorDir[i]!=0)	//toggle output pin if motor is desired to step
				switch(i)
				{
					case MOTOR_FRONT_RIGHT:
						MOTOR_FRONT_RIGHT_STEP;
						break;
					case MOTOR_BACK_RIGHT:
						MOTOR_BACK_RIGHT_STEP;
						break;
					case MOTOR_BACK_LEFT:
						MOTOR_BACK_LEFT_STEP;
						break;
					case MOTOR_FRONT_LEFT:
						MOTOR_FRONT_LEFT_STEP;
						break;
				}
		}
}
