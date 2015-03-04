#include "Dagu.h"

#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>

#include "../constants.h"

using namespace std;

Dagu::~Dagu()
{
	this->stop();
}

Dagu::Dagu()
{
	// Se ponen los pines como salidas
	cout << "\t[Dagu] GPIOS as outputs" << endl;
	pinMode (GPIO_M1_IN, OUTPUT);
	pinMode (GPIO_M2_IN, OUTPUT);
	pinMode (GPIO_M1_PWM, PWM_OUTPUT);
	pinMode (GPIO_M2_PWM, PWM_OUTPUT);

	// Se inicializan los PWMs
	cout << "\t[Dagu] PWM setup" << endl;
	softPwmCreate(GPIO_M1_PWM, PWM_MIN_VALUE, PWM_MAX_VALUE);
	softPwmCreate(GPIO_M2_PWM, PWM_MIN_VALUE, PWM_MAX_VALUE);

	// Se pone en estado parado
	cout << "\t[Dagu] State stopped" << endl;
	softPwmWrite(GPIO_M1_PWM, PWM_MIN_VALUE); 
	softPwmWrite(GPIO_M2_PWM, PWM_MIN_VALUE); 
	digitalWrite(GPIO_M1_IN, BACKWARD);
	digitalWrite(GPIO_M2_IN, BACKWARD);
}

void Dagu::right_backward(int speed)
{
	if (speed > 100) {
		speed = 100;
	} else if (speed < 0) {
		speed = 0;
	}
	speed = 100 - speed;
	digitalWrite(GPIO_M1_IN, FORWARD);
	softPwmWrite(GPIO_M1_PWM, speed); 
}

void Dagu::right_forward(int speed)
{
	if (speed > 100) {
		speed = 100;
	} else if (speed < 0) {
		speed = 0;
	}
	digitalWrite(GPIO_M1_IN, BACKWARD);
	softPwmWrite(GPIO_M1_PWM, speed);
}

void Dagu::left_backward(int speed)
{
	if (speed > 100) {
		speed = 100;
	} else if (speed < 0) {
		speed = 0;
	}
	speed = 100 - speed;
	digitalWrite(GPIO_M2_IN, FORWARD);
	softPwmWrite(GPIO_M2_PWM, speed); 
}

void Dagu::left_forward(int speed)
{
	if (speed > 100) {
		speed = 100;
	} else if (speed < 0) {
		speed = 0;
	}
	digitalWrite(GPIO_M2_IN, BACKWARD);
	softPwmWrite(GPIO_M2_PWM, speed); 
}

void Dagu::stop()
{
	softPwmWrite(GPIO_M1_PWM, PWM_MIN_VALUE); 
	softPwmWrite(GPIO_M2_PWM, PWM_MIN_VALUE); 
	digitalWrite(GPIO_M1_IN, BACKWARD);
	digitalWrite(GPIO_M2_IN, BACKWARD);
}