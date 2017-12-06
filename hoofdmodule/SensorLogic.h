#ifndef HEADERFILE_SensorLogic
#define HEADERFILE_SensorLogic
#include <stdlib.h> 
#include <vector>
#include <iostream>

class Manager;

class SensorLogic
{
public:
	SensorLogic(Manager *manager);
	~SensorLogic();
	void updateMap();
private:
	std::vector<int> Sonars;
	std::vector<bool> Bumpers;
	std::vector<double> GPS;
};
#endif