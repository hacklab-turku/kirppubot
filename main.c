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
		if(nesread()&(1<<BUTTON_A))
			stepMotors();
		if(nesread()&(1<<BUTTON_LEFT))
		{
			setMotorDir(MOTOR_FRONT_RIGHT, FORWARD);
			setMotorDir(MOTOR_BACK_RIGHT, FORWARD);
			setMotorDir(MOTOR_BACK_LEFT, REVERSE);
			setMotorDir(MOTOR_FRONT_LEFT, REVERSE);
			stepMotors();
		}
		else if(nesread()&(1<<BUTTON_RIGHT))
		{
			setMotorDir(MOTOR_FRONT_RIGHT, REVERSE);
			setMotorDir(MOTOR_BACK_RIGHT, REVERSE);
			setMotorDir(MOTOR_BACK_LEFT, FORWARD);
			setMotorDir(MOTOR_FRONT_LEFT, FORWARD);
			stepMotors();
		}
		else
		{
			setMotorDir(MOTOR_FRONT_RIGHT, FORWARD);
			setMotorDir(MOTOR_BACK_RIGHT, FORWARD);
			setMotorDir(MOTOR_BACK_LEFT, FORWARD);
			setMotorDir(MOTOR_FRONT_LEFT, FORWARD);
		}
		_delay_ms(1);
	}

}
