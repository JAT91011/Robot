#include "SPIUtils.h"
#include "../constants.h"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(void) {
	
	cout << "[Test] Starting" << endl;
	cout << "[Test] Creating temperature object with channel " << TEMPERATURE_CHANNEL << endl;
	SPIUtils temperature(TEMPERATURE_CHANNEL);
	temperature.start_reading();

	while(1) {
		double t = temperature.get_distance();
		cout << "[Test] Info: Read temperature: " << fixed << t << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	temperature.stop_reading();
	return 0;
}