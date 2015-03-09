#include "Chassis.h"

#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>

#include "../constants.h"

using namespace std;

Chassis::~Chassis()
{
	this->stop();
}

Chassis::Chassis()
{
	// Se ponen los pines como salidas
	cout << "\t[Chassis] GPIOS as outputs" << endl;
	pinMode (GPIO_M1_IN, OUTPUT);
	pinMode (GPIO_M2_IN, OUTPUT);
	pinMode (GPIO_M1_PWM, PWM_OUTPUT);
	pinMode (GPIO_M2_PWM, PWM_OUTPUT);

	// Se inicializan los PWMs
	cout << "\t[Chassis] PWM setup" << endl;
	softPwmCreate(GPIO_M1_PWM, PWM_MIN_VALUE, PWM_MAX_VALUE);
	softPwmCreate(GPIO_M2_PWM, PWM_MIN_VALUE, PWM_MAX_VALUE);

	// Se pone en estado parado
	cout << "\t[Chassis] State stopped" << endl;
	softPwmWrite(GPIO_M1_PWM, PWM_MIN_VALUE); 
	softPwmWrite(GPIO_M2_PWM, PWM_MIN_VALUE); 
	digitalWrite(GPIO_M1_IN, BACKWARD);
	digitalWrite(GPIO_M2_IN, BACKWARD);
}

void Chassis::right_forward(int speed)
{
	speed = constraint(speed, 100, 0);
	digitalWrite(GPIO_M1_IN, BACKWARD);
	softPwmWrite(GPIO_M1_PWM, speed);
}

void Chassis::right_backward(int speed)
{
	speed = constraint(speed, 100, 0);
	speed = 100 - speed;
	digitalWrite(GPIO_M1_IN, FORWARD);
	softPwmWrite(GPIO_M1_PWM, speed); 
}

void Chassis::left_forward(int speed)
{
	speed = constraint(speed, 100, 0);
	digitalWrite(GPIO_M2_IN, BACKWARD);
	softPwmWrite(GPIO_M2_PWM, speed); 
}

void Chassis::left_backward(int speed)
{
	speed = constraint(speed, 100, 0);
	speed = 100 - speed;
	digitalWrite(GPIO_M2_IN, FORWARD);
	softPwmWrite(GPIO_M2_PWM, speed); 
}

void Chassis::stop()
{
	softPwmWrite(GPIO_M1_PWM, PWM_MIN_VALUE); 
	softPwmWrite(GPIO_M2_PWM, PWM_MIN_VALUE); 
	digitalWrite(GPIO_M1_IN, BACKWARD);
	digitalWrite(GPIO_M2_IN, BACKWARD);
}