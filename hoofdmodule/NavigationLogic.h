#include <stdlib.h> 
#include <vector>
class NavigationLogic
{
public:
	NavigationLogic();
	~NavigationLogic();
	void startRoute();
	void stopRoute();
	void resumeRoute();
	void calculateDirection();
	void sendMovement();
	void getNextWayPoint();
	void setCurrenWaypoint(std::vector<int> getNextWayPoint);

private:
	std::vector<int> currentWayPoint;
	std::vector<int> nextWayPoint;
	double Orientation;
	std::vector<double> position;
};
