#include "SPIUtils.h"
#include "../constants.h"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(void) {
	
	cout << "[Test] Starting" << endl;
	cout << "[Test] Creating distance object with channel " << DISTANCE_CHANNEL << endl;
	SPIUtils distance(DISTANCE_CHANNEL);
	distance.start_reading();

	while(1) {
		double d = distance.get_distance();
		cout << "[Test] Info: Read distance: " << fixed << d << endl;
		double p = distance.get_percent();
		cout << "[Test] Info: Read percent: " << fixed << p << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	distance.stop_reading();
	return 0;
}