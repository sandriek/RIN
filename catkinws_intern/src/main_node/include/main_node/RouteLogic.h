#ifndef HEADERFILE_RouteLogic
#define HEADERFILE_RouteLogic
#include <stdlib.h> 
#include <vector>
#include <iostream>
class Manager;

class RouteLogic
{
public:
	RouteLogic(Manager* manager);
	~RouteLogic();
	void calculateWaypoints();
	std::vector<int> calculateNextWayPoint(std::vector<int> wayPoint);
	std::vector<double> calculateFirstWayPoint(std::vector<double> wayPoint);
	std::vector<int> checkClosest(std::vector<int> wayPoint, int steps);

	void setMaps(std::vector<std::vector<int>> map, int maptype);
	void setWayPoints(std::vector<std::vector<int>> wayPoints);
	std::vector<std::vector<int>>  getWayPoints();
private:
	Manager* manager;
	std::vector<std::vector<std::vector<int>>> wayPointsGrid;
	std::vector<std::vector<int>> wayPoints;
	std::vector<std::vector<int>> closestPoints;
	std::vector<std::vector<int>> clusterMap;
	std::vector<std::vector<int>> pixelMap;
	double clusterSize;
};
#endif