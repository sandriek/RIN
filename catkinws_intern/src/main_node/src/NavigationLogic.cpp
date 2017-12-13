#include "NavigationLogic.h"
#include "Manager.h"
#include <cmath>
NavigationLogic::NavigationLogic(Manager* manager)
{
	this->manager = manager;
}

NavigationLogic::~NavigationLogic()
{
}

void NavigationLogic::startRoute()
{

	getNextWayPoint();
	//setCurrenWaypoint();
	calculateDirection();
}

void NavigationLogic::stopRoute()
{

}

void NavigationLogic::resumeRoute()
{
}

void NavigationLogic::calculateDirection()
{
	double rotation;
	nextWayPoint = { -1,0,0 };
	position = { 0,0,0 };
	
	double difX =  position[0] - nextWayPoint[0];
	double difY =  position[1] - nextWayPoint[1];
	double angleNeeded;
	double difAngle;
	double distance;
	if (difY > 0) {
		//up
		angleNeeded = 0;
		distance = difY;
	}
	if (difY < 0) {
		//down
		angleNeeded = 180;
		distance = -difY;
	}
	if (difX < 0) {
		//left
		angleNeeded = -90;
		distance = -difX;
	}
	if (difX > 0) {
		//right
		angleNeeded = 90;
		distance = difX;
	}
	
	difAngle = Orientation - angleNeeded;
	if (difAngle > 180 || difAngle < -180) {
		difAngle = angleNeeded - Orientation;
	}
	turn(difAngle);
	driveForward(distance);

	
	
}

void NavigationLogic::sendMovement(double distance, double angle)
{
	manager->getPublisher()->publishMovements(distance, angle);
}

void NavigationLogic::getNextWayPoint()
{
	nextWayPoint = manager->getRouteLogic()->calculateNextWayPoint(nextWayPoint);
}

void NavigationLogic::setCurrenWaypoint(std::vector<int> WayPoint)
{
	currentWayPoint = WayPoint;
}

void NavigationLogic::driveForward(double distance)
{
	std::cout << "Charge!!!!!!!!! " << std::endl;;
}

void NavigationLogic::turn(double angle)
{
	if (angle < 0) {
		if (angle < -90) {
			turnAround();
		}
		else {
			turnLeft();
		}
	}
	if (angle > 0) {
		if (angle > 90) {
			turnAround();
		}
		else {
			turnRight();
		}
	}
	
}

void NavigationLogic::turnRight()
{
	std::cout << "Turn Right " << std::endl;;
}

void NavigationLogic::turnLeft()
{
	std::cout << "Turn Left " << std::endl;;
}

void NavigationLogic::turnAround()
{
	std::cout << "Turn Around" << std::endl;;
}

std::vector<double> NavigationLogic::getPosition()
{
	return position;
}

void NavigationLogic::setStartingWaypoint()
{
	firstWayPoint = manager->getRouteLogic()->calculateFirstWayPoint(position);
}

void NavigationLogic::goToFirstPoint()
{
	/*set robot angle to angle from nextWayPoint*/
	/*drive distance*/
	/*return to 0 angle*/
}


void NavigationLogic::setPosition(std::vector<double> pos)
{
	this->position = pos;
}

std::vector<double> NavigationLogic::getFirstWayPoint() {
	return firstWayPoint;
}
void NavigationLogic::CorrectMovement() {
	std::vector<double> position = manager->getNavigationLogic()->getPosition();
	std::vector<int> WayPoint = this->nextWayPoint;
	double angle;

		double difX = position[0] - WayPoint[0];
		double difY = position[1] - WayPoint[1];
		angle = tan(difY / difX);
		double distance = sqrt((difY*difY) + (difX*difX));
		sendMovement(distance, angle);

}
