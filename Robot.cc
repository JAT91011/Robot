#include "Robot.h"
#include "Chassis/Chassis.h"
#include "SPI/SPIUtils.h"
#include "QTRSensors/QTRSensors.h"
#include "constants.h"

#include <signal.h>
#include <wiringPi.h> 
#include <stdio.h>
#include <stdlib.h>
#include <array>

void my_handler(int s){
	cout << "[Robot] Closing..." << endl;
	Chassis Chassis;
	Chassis.stop();
	exit(1);
}

int main(void)
{
	signal(SIGINT, my_handler);
	
	if(wiringPiSetup() == -1)
	{
		cout << "[Robot] Error: wiringPi setup failed." << endl;
		return 1;
	}

	cout << "[Robot] Starting" << endl;
	cout << "[Robot] Creating Chassis object" << endl;
	Chassis chassis;

	cout << "[Robot] Creating IR object" << endl;
	array<int, 8> pines {GPIO_QTR_SENSOR_0, GPIO_QTR_SENSOR_1, GPIO_QTR_SENSOR_2, GPIO_QTR_SENSOR_3, GPIO_QTR_SENSOR_4, GPIO_QTR_SENSOR_5, GPIO_QTR_SENSOR_6, GPIO_QTR_SENSOR_7};
	QTRSensors sensors (pines);
	sensors.start_reading();

	int lastError = 0;

    while(1) {
    	int position = sensors.get_position();
    	int error = 4 - position;
    	int speed = (PROPORTIONAL_CONSTANT * error + DERIVATIVE_CONSTANT * (error - lastError)) * 5;
    	lastError = error;

    	int m0Speed = ROBOT_BASE_SPEED + speed;
    	int m1Speed = ROBOT_BASE_SPEED - speed;

    	chassis.right_forward(m1Speed);
    	chassis.left_forward(m0Speed);
    }
}