#ifndef QTRSensors_h
#define QTRSensors_h

#include <array>
#include <atomic>

using namespace std;

	class QTRSensors
	{
	private:
		array<int,8> gpio_sensors;
		
		int position;

		atomic_bool reading;
		atomic_bool stopped;

		void read_position();
	public:
		QTRSensors(array<int,8> gpio_sensors);
		~QTRSensors();
		QTRSensors(QTRSensors& copy) = delete;

		void start_reading();
		void stop_reading();
		bool is_reading() {return this->reading;}

		int get_position() {return this->position;}
	};

#endif // QTRSensors_h
