#include "NavigationLogic.h"
#include "Manager.h"
NavigationLogic::NavigationLogic(Manager* manager)
{
	std::cout << "nav";
	manager->getControllerLogic();
}

NavigationLogic::~NavigationLogic()
{
}

void NavigationLogic::startRoute()
{
}

void NavigationLogic::stopRoute()
{
}

void NavigationLogic::resumeRoute()
{
}

void NavigationLogic::calculateDirection()
{
}

void NavigationLogic::sendMovement()
{
}

void NavigationLogic::getNextWayPoint()
{
}

void NavigationLogic::setCurrenWaypoint(std::vector<int> getNextWayPoint)
{
}

