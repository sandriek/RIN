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
	void sendMovement(double distance, double angle);
	void getNextWayPoint();
	void setCurrenWaypoint(std::vector<int> WayPoint);
	void driveForward(double distance);
	void turn(double angle);
	void turnRight();
	void turnLeft();
	void turnAround();
	std::vector<double> getPosition();
	void setStartingWaypoint();
	void goToFirstPoint();

	void setPosition(std::vector<double> pos);

	std::vector<double> getFirstWayPoint();

	void CorrectMovement();


private:
	std::vector<int> currentWayPoint;
	std::vector<int> nextWayPoint;
	std::vector<double> firstWayPoint;
	double Orientation = 0; 
	std::vector<double> position = { 0,0,0 };
	Manager* manager;
};
#endif