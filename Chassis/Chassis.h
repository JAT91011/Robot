#ifndef CHASSIS_CHASSIS_H_
#define CHASSIS_CHASSIS_H_

using namespace std;

class Chassis
{
public:
	Chassis();
	~Chassis();
	Chassis(Chassis& copy) = delete;

	void left_backward(int speed);
	void left_forward(int speed);
	void right_backward(int speed);
	void right_forward(int speed);
	void stop();
};

inline int constraint(int speed, int max, int min)
{
	if (speed > max) {
		return max;
	} else if (speed < min) {
		return min;
	} 
	return speed;
}


#endif // CHASSIS_CHASSIS_H_
