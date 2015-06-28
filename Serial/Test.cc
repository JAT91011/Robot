#include "Serial.h"
#include "../constants.h"

#include <wiringPi.h> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(void) {
	
	cout << "[Test] Starting" << endl;
	cout << "[Test] Creating serial object" << endl;
	Serial serial();
	
	while (true)
	{
		string cadena;
		cout << "Introduce una cadena: ";
		getline (cin, cadena);
		serial.write(cadena);
		serial.read();
	}
	return 0;
}