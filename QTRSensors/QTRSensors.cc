#include "QTRSensors.h"
#include "../constants.h"

#include <thread>
#include <math.h>
#include <iostream>
#include <wiringPi.h>
#include <array>

using namespace std;

QTRSensors::~QTRSensors()
{
	if (this->reading)
		this->stop_reading();
}

QTRSensors::QTRSensors(array<int,8> gpio_sensors)
{
	cout << "[QTRSensors] Debug: Constructor." << endl;

	wiringPiSetup(); 

	this->reading = false;
	this->stopped = true;

	this->gpio_sensors = gpio_sensors;

	for(int gpio : gpio_sensors) {
		pullUpDnControl (gpio, PUD_UP);
		pinMode (gpio, INPUT); 
	}
}

void QTRSensors::start_reading()
{
	if ( ! this->reading)
	{
		cout << "[QTRSensors] Debug: QTRSensors start reading." << endl;
		this->reading = true;
		this->stopped = false;
		thread t(&QTRSensors::read_position, this);
		t.detach();
	}
}

void QTRSensors::stop_reading()
{
	this->reading = false;
	while( ! this->stopped);
	cout << "[QTRSensors] Debug: QTRSensors stop reading." << endl;
}

void QTRSensors::read_position()
{
	while (this->reading)
	{
		if(digitalRead(this->gpio_sensors[0]) == 1 && digitalRead(this->gpio_sensors[1]) == 0) {
			this->position = 0;
		} else if(digitalRead(this->gpio_sensors[0]) == 1 && digitalRead(this->gpio_sensors[1]) == 1) {
			this->position = 1;
		} else if(digitalRead(this->gpio_sensors[1]) == 1 && digitalRead(this->gpio_sensors[2]) == 1) {
			this->position = 2;
		} else if(digitalRead(this->gpio_sensors[2]) == 1 && digitalRead(this->gpio_sensors[3]) == 1) {
			this->position = 3;
		} else if(digitalRead(this->gpio_sensors[3]) == 1 && digitalRead(this->gpio_sensors[4]) == 1) {
			this->position = 4;
		} else if(digitalRead(this->gpio_sensors[4]) == 1 && digitalRead(this->gpio_sensors[5]) == 1) {
			this->position = 5;
		} else if(digitalRead(this->gpio_sensors[5]) == 1 && digitalRead(this->gpio_sensors[6]) == 1) {
			this->position = 6;
		} else if(digitalRead(this->gpio_sensors[6]) == 1 && digitalRead(this->gpio_sensors[7]) == 1) {
			this->position = 7;
		} else if(digitalRead(this->gpio_sensors[6]) == 0 && digitalRead(this->gpio_sensors[7]) == 1) {
			this->position = 8;
		}
	}
	this->stopped = true;
}
