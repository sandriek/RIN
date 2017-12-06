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
	void calculateNextWayPoint();
private:
	std::vector<int> wayPoints;
	std::vector<std::vector<int>> ClusterMap;
	std::vector<std::vector<int>> pixelMap;
};
#endif