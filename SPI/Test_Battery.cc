#include "SPIUtils.h"
#include "../constants.h"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(void) {
	
	cout << "[Test] Starting" << endl;
	cout << "[Test] Creating battery object with channel " << BATTERY_CHANNEL << endl;
	SPIUtils battery(BATTERY_CHANNEL);
	battery.start_reading();

	while(1) {
		double v = battery.get_volts();
		cout << "[Test] Info: Read volts: " << fixed << v << endl;
		double p = battery.get_percent();
		cout << "[Test] Info: Read percent: " << fixed << p << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	battery.stop_reading();
	return 0;
}