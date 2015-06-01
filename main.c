#include "./stepper.h"
#include "./nes.h"

#include <avr/io.h>
#include <avr/delay.h>
#include <stdlib.h>

int main()
{
	nessetup();
	initMotors();
	setMotorDir(MOTOR_FRONT_RIGHT, FORWARD);
	setMotorDir(MOTOR_BACK_RIGHT, FORWARD);
	setMotorDir(MOTOR_BACK_LEFT, FORWARD);
	setMotorDir(MOTOR_FRONT_LEFT, FORWARD);

	while(1)
	{
		if(nesread()&(1<<BUTTON_A))	//drive
		{
			setMotorEnable(1);
			stepMotors();
		}

		if(nesread()&(1<<BUTTON_B))	//break
			setMotorEnable(1);
		else if(nesread()&(1<<BUTTON_LEFT))	//turn left
		{
			setMotorDir(MOTOR_FRONT_RIGHT, FORWARD);
			setMotorDir(MOTOR_BACK_RIGHT, FORWARD);
			setMotorDir(MOTOR_BACK_LEFT, REVERSE);
			setMotorDir(MOTOR_FRONT_LEFT, REVERSE);
			setMotorEnable(1);
			stepMotors();
		}
		else if(nesread()&(1<<BUTTON_RIGHT))	//turn right
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
			setMotorEnable(0);
		}
		_delay_ms(1);
	}

}
