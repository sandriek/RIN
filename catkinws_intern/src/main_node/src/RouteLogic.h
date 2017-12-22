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
	
	std::vector<std::vector<int>> calculateNextWayPoint(std::vector<int> wayPoint);
	std::vector<double> calculateFirstWayPoint(std::vector<double> wayPoint);
	std::vector<std::vector<int>> checkClosest(std::vector<int> wayPoint, int 	steps,std::vector<std::vector<std::vector<int>>> tempGrid);
	std::vector<std::vector<int>> checkClosestRoute(std::vector<int> currentwayPoint, int steps,std::vector<int> destinationwayPoint,  std::vector<std::vector<std::vector<int>>> tempGrid1);
	void setMaps(std::vector<std::vector<int>> map, int maptype);
	void setWayPoints(std::vector<std::vector<int>> wayPoints);
	std::vector<std::vector<int>>  getWayPoints();
	void calculate();

	Manager* manager;
	std::vector<std::vector<std::vector<int>>> wayPointsGrid;
	std::vector<std::vector<std::vector<int>>> tempGrid;
	std::vector<std::vector<int>> wayPoints;
	std::vector<std::vector<int>> closestPoints;
	std::vector<std::vector<int>> clusterMap;
	std::vector<std::vector<int>> pixelMap;
	double clusterSize;
private:
	
};
#endif
