#include "Dagu.h"

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
	cout << "[Test] Creating Dagu object" << endl;
	
	Dagu Dagu;

	while(1) 
	{
		string opcion = "";
		int speed = ROBOT_BASE_SPEED;
		cout << "Selecciona una opción (W - Adelante, A - Izquierda, D - Derecha, S - Atras): ";
		getline (cin, opcion);
		if(opcion == "W") {
			cout << "[Test] Forward" << endl;
			Dagu.left_forward(speed);
			Dagu.right_forward(speed);
		} else if(opcion == "A") {
			cout << "[Test] Left" << endl;
			Dagu.right_forward(speed);
			Dagu.left_backward(speed);
		} else if(opcion == "D") {
			cout << "[Test] Right" << endl;
			Dagu.left_forward(speed);
			Dagu.right_backward(speed);
		} else if(opcion == "S") {
			cout << "[Test] Backward" << endl;
			Dagu.left_backward(speed);
			Dagu.right_backward(speed);
		} else if(opcion == "Q") {
			cout << "[Test] Stop" << endl;
			Dagu.stop();
		}		
	}
	return 0;
}