#include <avr/io.h>
#include <avr/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>


#include "./stepper.h"
#include "./nes.h"
#include "./usart.h"


int main()
{
	uint8_t nes;
	//nessetup();
	initMotors();
	initUSART();
	sei();
	setMotorEnable(0);

	while(1)
	{
		/*setMotorDir(MOTOR_FRONT_RIGHT, FORWARD);
		setMotorDir(MOTOR_BACK_RIGHT, FORWARD);
		setMotorDir(MOTOR_BACK_LEFT, FORWARD);
		setMotorDir(MOTOR_FRONT_LEFT, FORWARD);
		setMotorEnable(1);
		stepMotors();*/
		_delay_ms(20);
		//nes=nesread();
		nes=getCommand();
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
			if(nes&(1<<BUTTON_UP))	//drive
			{
				setMotorDir(MOTOR_FRONT_RIGHT, FORWARD);
				setMotorDir(MOTOR_BACK_RIGHT, FORWARD);
				setMotorDir(MOTOR_BACK_LEFT, FORWARD);
				setMotorDir(MOTOR_FRONT_LEFT, FORWARD);
				setMotorEnable(1);
				stepMotors();
			}
			else if(nes&(1<<BUTTON_DOWN))	//reverse
			{
				setMotorDir(MOTOR_FRONT_RIGHT, REVERSE);
				setMotorDir(MOTOR_BACK_RIGHT, REVERSE);
				setMotorDir(MOTOR_BACK_LEFT, REVERSE);
				setMotorDir(MOTOR_FRONT_LEFT, REVERSE);
				setMotorEnable(1);
				stepMotors();
			}
			else
				setMotorEnable(0);
		}
	}

}
