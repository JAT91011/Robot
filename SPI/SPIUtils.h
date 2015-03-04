#ifndef SPIUTILS_SPIUTILS_H_
#define SPIUTILS_SPIUTILS_H_

#include <atomic>

using namespace std;

	class SPIUtils
	{
	private:
		int channel;
		double volts;
		atomic_bool reading;
		atomic_bool stopped;

		void read_volts();
	public:
		SPIUtils(const int channel);
		~SPIUtils();
		SPIUtils(SPIUtils& copy) = delete;

		void start_reading();
		void stop_reading();
		bool is_reading() {return this->reading;}

		double get_volts() {return this->volts;}
		double get_percent();
		double get_distance();
	};

#endif // SPIUTILS_SPIUTILS_H_
