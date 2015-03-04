#ifndef DAGU_DAGU_H_
#define DAGU_DAGU_H_

using namespace std;

class Dagu
{
public:
	Dagu();
	~Dagu();
	Dagu(Dagu& copy) = delete;

	void left_backward(int speed);
	void left_forward(int speed);
	void right_backward(int speed);
	void right_forward(int speed);
	void stop();
};


#endif // DAGU_DAGU_H_
