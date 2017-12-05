#include <stdlib.h> 
#include <vector>
class RouteLogic
{
public:
	RouteLogic();
	~RouteLogic();
	void calculateWaypoints();
	void calculateNextWayPoint();
private:
	std::vector<int> wayPoints;
	std::vector<std::vector<int>> ClusterMap;
	std::vector<std::vector<int>> pixelMap;
};
