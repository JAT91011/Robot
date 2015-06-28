#include "Serial.h"
#include "../constants.h"

#include <stdio.h>
#include <string>
#include <atomic>
#include <errno.h>
#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>

using namespace std;

Serial::~Serial()
{
	serialClose(this->fileDescriptor);
}

Serial::Serial()
{
	cout << "\t[Serial] Debug: Constructor." << endl;

	if ((this->fileDescriptor = serialOpen("/dev/ttyAMA0", 115200)) < 0)
	{
		fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno));
	}

	if (wiringPiSetup () == -1)
	{
		fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno));
	}
}

bool Serial::available()
{
	return serialDataAvail(this->fileDescriptor);
}

string Serial::read()
{
	string str = "";
	while (serialDataAvail(this->fileDescriptor))
    {
    	str += (char)serialGetchar(this->fileDescriptor);
      	fflush (stdout);
    }

    return str.substr(3, str.size() - 3);
}

string Serial::createSentence(int id, string data)
{
	if (data.size() < 10)
	{
		return "#" + to_string(id) + "\045" + "0"+ to_string(data.size()) + "$" + data + ";";
	} else {
		return "#" + to_string(id) + "\045" + to_string(data.size()) + "$" + data + ";";
	}
}

void Serial::write(const char* line)
{
	serialPuts(this->fileDescriptor, line);
}