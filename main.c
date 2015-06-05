#include "./stepper.h"
#include "./nes.h"
#include "./usart.h"

#include <avr/io.h>
#include <avr/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

int main()
{
	uint8_t nes;
	nessetup();
	initMotors();
	initUSART();
	sei();

	while(1)
	{
		nes=nesread();
		if(nes&(1<<BUTTON_LEFT))	//turn left
		{
			setMotorDir(MOTOR_FRONT_RIGHT, FORWARD);
			setMotorDir(MOTOR_BACK_RIGHT, FORWARD);
			setMotorDir(MOTOR_BACK_LEFT, REVERSE);
			setMotorDir(MOTOR_FRONT_LEFT, REVERSE);
			setMotorEnable(1);
			stepMotors();
		}
		else if(nes&(1<<BUTTON_RIGHT))	//turn right
		{
			setMotorDir(MOTOR_FRONT_RIGHT, REVERSE);
			setMotorDir(MOTOR_BACK_RIGHT, REVERSE);
			setMotorDir(MOTOR_BACK_LEFT, FORWARD);
			setMotorDir(MOTOR_FRONT_LEFT, FORWARD);
			setMotorEnable(1);
			stepMotors();
		}
		else	//no direction chosen, go straight
		{
			setMotorDir(MOTOR_FRONT_RIGHT, FORWARD);
			setMotorDir(MOTOR_BACK_RIGHT, FORWARD);
			setMotorDir(MOTOR_BACK_LEFT, FORWARD);
			setMotorDir(MOTOR_FRONT_LEFT, FORWARD);
			if(nes&(1<<BUTTON_A))	//drive
			{
				setMotorEnable(1);
				stepMotors();
			}
			else if(nes&(1<<BUTTON_B))	//break
				setMotorEnable(1);
			else
				setMotorEnable(0);
		}
	}

}
