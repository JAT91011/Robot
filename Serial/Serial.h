#ifndef Serial_h
#define Serial_h

#include <atomic>
#include <string>

using namespace std;

	class Serial
	{
	private:		
		int fileDescriptor;

	public:
		Serial();
		~Serial();

    	bool available();
		string read();
		string createSentence(int id, string data);
		void write(const char* line);
	};

#endif // Serial_h
