#include "./stepper.h"

#include <avr/io.h>
#include <avr/delay.h>
#include <stdlib.h>

int main()
{
	initMotors();
	setMotorDir(MOTOR_FRONT_RIGHT, FORWARD);
	setMotorDir(MOTOR_BACK_RIGHT, FORWARD);
	setMotorDir(MOTOR_BACK_LEFT, FORWARD);
	setMotorDir(MOTOR_FRONT_LEFT, FORWARD);

	while(1)
	{
		stepMotors(1);
		_delay_ms(1);
	}

}
