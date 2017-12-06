#ifndef HEADERFILE_NavigationLogic
#define HEADERFILE_NavigationLogic



#include <stdlib.h> 
#include <vector>
#include <iostream>

class Manager;

class NavigationLogic
{
public:
	NavigationLogic(Manager* manager);
	~NavigationLogic();
	void startRoute();
	void stopRoute();
	void resumeRoute();
	void calculateDirection();
	void sendMovement();
	void getNextWayPoint();
	void setCurrenWaypoint(std::vector<int> getNextWayPoint);

private:
	std::vector<int> currentWayPoint;
	std::vector<int> nextWayPoint;
	double Orientation;
	std::vector<double> position;
};
#endif