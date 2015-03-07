#include "SPIUtils.h"

#include <thread>
#include <chrono>
#include <wiringPiSPI.h>
#include <math.h>
#include <softPwm.h>
#include <iostream>

using namespace std;

SPIUtils::~SPIUtils()
{
	if (this->reading)
		this->stop_reading();
}

SPIUtils::SPIUtils(int channel)
{
	cout << "[SPI] Debug: Constructor in channel: " << channel << endl;
	this->reading = false;
	this->stopped = true;
	this->channel = channel;

	int fh = wiringPiSPISetup(channel, 1000000);
	if (wiringPiSPISetup(channel, 1000000) < 0)
	{
		cout << "[SPI] Error: An error ocurred initializing SPI module." << endl;
	}
}

void SPIUtils::start_reading()
{
	if ( ! this->reading)
	{
		cout << "[SPI] Debug: SPI start reading." << endl;
		this->reading = true;
		this->stopped = false;
		thread t(&SPIUtils::read_volts, this);
		t.detach();
	}
}

void SPIUtils::stop_reading()
{
	this->reading = false;
	while( ! this->stopped);
	cout << "[SPI] Debug: SPI stop reading." << endl;
}

void SPIUtils::read_volts()
{
	while (this->reading)
	{
		unsigned char spiData [2];
		if (this->channel == 0) 
		{
			spiData[0] = 0b11010000;
		} else {
			spiData[0] = 0b11110000;
		}
		spiData[1] = 0;

		if (wiringPiSPIDataRW (this->channel, spiData, 2) > 0) 
		{
			int data = ((spiData [0] << 7) | (spiData [1] >> 1)) & 0x3FF;
			this->volts = (data * 3.3) / 1023.0;
		}
		this_thread::sleep_for(chrono::milliseconds(50));
	}
	this->stopped = true;
}

double SPIUtils::get_percent()
{
	return (this->volts * 100) / 3.3;
}

double SPIUtils::get_distance()
{
	return 26.434 * pow(this->volts, -1.211);
}
