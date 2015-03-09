#include "Chassis.h"

#include <wiringPi.h> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "../constants.h"

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		cout << "[Test] Error:wiringPi setup failed." << endl;
		return 1;
	}

	cout << "[Test] Starting" << endl;
	cout << "[Test] Creating Chassis object" << endl;
	
	Chassis Chassis;

	while(1) 
	{
		string opcion = "";
		int speed = ROBOT_BASE_SPEED;
		cout << "Selecciona una opción (W - Adelante, A - Izquierda, D - Derecha, S - Atras, Q - Parar): ";
		getline (cin, opcion);
		if(opcion == "W") {
			cout << "[Test] Forward" << endl;
			Chassis.left_forward(speed);
			Chassis.right_forward(speed);
		} else if(opcion == "A") {
			cout << "[Test] Left" << endl;
			Chassis.right_forward(speed);
			Chassis.left_backward(speed);
		} else if(opcion == "D") {
			cout << "[Test] Right" << endl;
			Chassis.left_forward(speed);
			Chassis.right_backward(speed);
		} else if(opcion == "S") {
			cout << "[Test] Backward" << endl;
			Chassis.left_backward(speed);
			Chassis.right_backward(speed);
		} else if(opcion == "Q") {
			cout << "[Test] Stop" << endl;
			Chassis.stop();
		}		
	}
	return 0;
}