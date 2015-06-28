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
	Serial serial;
	
	while (true)
	{
		//string cadena;
		//cout << "Introduce una cadena: ";
		//cin >> cadena;
		//serial.write(cadena.c_str());
		if (serial.available())
		{
			string str = "";
			str = serial.read();
			cout << str << endl;
			serial.write(serial.createSentence(1, str).c_str());
		}
	}
	return 0;
}