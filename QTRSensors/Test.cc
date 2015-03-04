#include "QTRSensors.h"
#include "../constants.h"

#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

int main(void) {
	
	cout << "[Test] Starting" << endl;
	cout << "[Test] Creating IR object" << endl;

	array<int, 8> pines {GPIO_QTR_SENSOR_0, GPIO_QTR_SENSOR_1, GPIO_QTR_SENSOR_2, GPIO_QTR_SENSOR_3, GPIO_QTR_SENSOR_4, GPIO_QTR_SENSOR_5, GPIO_QTR_SENSOR_6, GPIO_QTR_SENSOR_7};
	QTRSensors sensors (pines);
	sensors.start_reading();

    while(1) {
      int position = sensors.get_position();
      cout << "Posicion = " << position << endl;
      this_thread::sleep_for(chrono::milliseconds(50));
    }
  sensors.stop_reading();

	return 0;
}