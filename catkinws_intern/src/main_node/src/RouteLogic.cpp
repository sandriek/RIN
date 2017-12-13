#include "RouteLogic.h"
#include "Manager.h"
#include <string> 
#include <cmath>
RouteLogic::RouteLogic(Manager *manager)
{
	this->manager = manager;
}

RouteLogic::~RouteLogic()
{
}

void RouteLogic::calculateWaypoints()
{
	clusterSize = pixelMap.size() / clusterMap.size();
	for (int x = 0; x < clusterMap.size(); x++)
	{
		for (int y = 0; y < clusterMap[x].size(); y++)
		{
			wayPointsGrid[x][y] = { (int)(clusterSize / 2) * x , (int)(clusterSize / 2) * y , 0 , 0, 0 };
			wayPoints[x + y] = { (int)(clusterSize / 2) * x ,  (int)(clusterSize / 2) * y , 0 , 0, 0 };
		}
	}
}

std::vector<int> RouteLogic::calculateNextWayPoint(std::vector<int> wayPoint)
{
	checkClosest(wayPoint, 0);
	manager->getNavigationLogic()->setCurrenWaypoint(wayPoint);
	return wayPoint;
}
std::vector<double> RouteLogic::calculateFirstWayPoint(std::vector<double> wayPoint)
{
	manager->getSubscriber();
	std::vector<double> position = manager->getNavigationLogic()->getPosition();
	std::vector<double> closestTemp = { 0,0,0,0,0 };
	std::vector<double> closest = { 0,0,0,0,0,0 };
	double angle ;
	for (int index = 0; index < wayPoints.size(); index++)
	{
		double difX =  wayPoints[index][0] - position[0];
		double difY =  wayPoints[index][1] - position[1];
		
		angle = atan(difY / difX);
		double distance = sqrt((difY*difY) + (difX*difX));
		if (closestTemp[3] == 0) {

			for (int i = 0; i < 3; i++)
			{
				closest[i] = wayPoints[index][i];
				closestTemp[i] = wayPoints[index][i];
			}
			
			closestTemp[3] = distance;
			closestTemp[4] = angle* (180 / 3.14159265358979323846);
			if (difX < 0 && difY == 0) {
				closestTemp[4] = 180;
			}
		}
		if (closestTemp[3] > distance) {
			for (int i = 0; i < 3; i++)
			{
				closest[i] = wayPoints[index][i];
				closestTemp[i] = wayPoints[index][i];
			}
			closestTemp[3] = distance;
			closestTemp[4] = angle* (180 / 3.14159265358979323846);
			if (difX < 0 && difY == 0) {
				closestTemp[4] = 180;
			}
		}
	}
	closest[4] = closestTemp[4];
	
	closest[5] = closestTemp[3];
	return closest;
}
std::vector<int> RouteLogic::checkClosest(std::vector<int> wayPoint, int steps)
{
	std::vector<int> closest;
	std::vector<std::vector<int>> temp;
	if (       wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5][3] == 0) {
			   wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5][4] = steps;
			   wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5][3] = 1;
		return wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5];
	}
	if (	   wayPointsGrid[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5][3] == 0) {
		 	   wayPointsGrid[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5][4] = steps;
			   wayPointsGrid[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5][3] = 1;
		return wayPointsGrid[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5];
	}
	if (	   wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5][3] == 0) {
			   wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5][4] = steps;
			   wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5][3] = 1;
		return wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5];
	}
	if (	   wayPointsGrid[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize)][3] == 0) {
			   wayPointsGrid[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize)][4] = steps;
			   wayPointsGrid[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize)][3] = 1;
		return wayPointsGrid[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize)];
	}


	std::vector<int> first	= checkClosest(wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5]	, steps + 1);
	std::vector<int> second = checkClosest(wayPointsGrid[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5]	, steps + 1);
	std::vector<int> third	= checkClosest(wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5]	, steps + 1);
	std::vector<int> fourt	= checkClosest(wayPointsGrid[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize)]		, steps + 1);

	temp[0] = first;
	temp[1] = second;
	temp[2] = third;
	temp[3] = fourt;
	
	for (int i = 0; i < temp.size(); i++)
	{
		if (i == 0)
		{
			closest = temp[0];
		}
		if (closest[4] < temp[i][4]) {
			closest = temp[i];
		}

	}
	return closest;
}








void RouteLogic::setMaps(std::vector<std::vector<int>> map, int maptype)
{
	if (maptype == 0) {
		pixelMap = map;
	}
	if (maptype == 1) {
		clusterMap = map;
	}
}

void RouteLogic::setWayPoints(std::vector<std::vector<int>> wayPoints)
{
	this->wayPoints = wayPoints;
}
std::vector<std::vector<int>> RouteLogic::getWayPoints()
{
	return wayPoints;
}


