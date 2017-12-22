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
	bool startRoute();
	void stopRoute();
	void resumeRoute();
	void calculateDirection();
	void sendMovement(double distance, double angle);
	void getNextWayPoint();
	void setCurrenWaypoint(std::vector<int> WayPoint);
	void setNextWaypoint(std::vector<int> WayPoint);
	std::vector<double> getPosition();
	void setStartingWaypoint();
	void goToFirstPoint();

	void setPosition(std::vector<double> pos);

	std::vector<double> getFirstWayPoint();

	void CorrectMovement();
	std::vector<std::vector<int>> getRoute();
	void reachedWayPoint(bool boolean);
private:
	bool followingRoute;
	std::vector<int> currentWayPoint;
	std::vector<int> nextWayPoint;
	std::vector<int> estinationWayPoint;
	std::vector<double> firstWayPoint;
	double Orientation = 0; 
	std::vector<double> position = { 0,0,0 };
	Manager* manager;
	std::vector<std::vector<int>> Route;
	bool WayPointReached = false;
};
#endif
