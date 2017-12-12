#include "Tests.h"
#include "Manager.h"
Tests::Tests(Manager* manager)
{
	this->manager = manager;
}

Tests::~Tests()
{
}

void Tests::TestFirstWayPoint()
{
	std::cout << std::endl;
	std::cout << "Starting test for first waypoint" << std::endl;
	std::vector<std::vector<int>> wayPoints;
	wayPoints.push_back({ 1,0,0 });
	wayPoints.push_back({ 2,0,0 });
	wayPoints.push_back({ 0,0,0 });

	manager->getRouteLogic()->setWayPoints(wayPoints);
	manager->getNavigationLogic()->setPosition({0,0,0});
	std::cout << "Position = {";

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << manager->getNavigationLogic()->getPosition()[i];
		if (i != 2) {
			std::cout << ",";
		}
	}

	std::cout << "}" <<std::endl;
	std::cout << std::endl;
	std::cout << "wayoints set" << std::endl;
	wayPoints = manager->getRouteLogic()->getWayPoints();
	for (size_t i = 0; i < wayPoints.size(); i++)
	{
		std::cout << "wayPoint " << i << " = {";
		for (size_t j = 0; j < 3; j++)
		{
			 std::cout << wayPoints[i][j];
			 if (j != 2) {
				 std::cout << ",";
			 }
		}
		std::cout << "}" <<std::endl;
	}
	manager->getNavigationLogic()->setStartingWaypoint();
	std::vector<double> firstWayPoint = manager->getNavigationLogic()->getFirstWayPoint();
	std::cout << "closest/first waypoint= {";
	std::cout << firstWayPoint[0] << ",";
	std::cout << firstWayPoint[1] << ",";
	std::cout << firstWayPoint[2];
	std::cout << "}" <<std::endl;
	std::cout << std::endl;
}

