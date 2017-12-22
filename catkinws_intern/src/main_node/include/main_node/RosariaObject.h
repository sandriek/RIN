#pragma once
#include <stdlib.h> 
#include <vector>
class RosariaObject
{
public:
	RosariaObject();
	~RosariaObject();
	double getCurrentRotation();
	double getBatteryStatus();
	std::vector<std::vector<double>> getCurrentMovement();
private:
	double CurrentRotation;
	double BatteryStatus;
	std::vector<std::vector<double>> CurrentMovement; /* op positie 0 de linear movement en op 1 de angular movement */
};
