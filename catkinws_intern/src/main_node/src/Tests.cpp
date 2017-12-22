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
	wayPoints.push_back({ -1,-1,0 });
	wayPoints.push_back({ 2,0,0 });
	wayPoints.push_back({ 3,0,0 });

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
	std::cout << "Angle: " << firstWayPoint[4] <<std::endl;
	std::cout << "Distance: " << firstWayPoint[5] << std::endl;
	
	manager->getNavigationLogic()->sendMovement(firstWayPoint[5],firstWayPoint[4]);
}
void Tests::TestRoute(){
	RouteLogic* routeLogic = manager->getRouteLogic();

	std::vector<std::vector<int>> firstRoute = {{25,25,0,0,0,0,0}};
	std::cout << "Starting test for Route" << std::endl;
	std::cout << "set Maps" << std::endl;
	std::vector<std::vector<int>> pixel;
	std::vector<std::vector<int>> cluster;
	for(int index = 0; index<300;index++){
	pixel.push_back({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
	}
	for(int index = 0; index<6;index++){
	cluster.push_back( {0,0,0,0,0,0});
	}
	routeLogic->setMaps(pixel,0);
	routeLogic->setMaps(cluster,1);
	std::cout << "stest" << std::endl;





	routeLogic->calculate();
std::cout << "calculate route"<< std::endl;;
	
	
	for(int i = 0; i <36;i++){
	std::vector<std::vector<std::vector<int>>> route;
	if(i == 0){
	std::cout << "1"<< std::endl;
	route.push_back(manager->getRouteLogic()->calculateNextWayPoint(firstRoute[0]));
	for (size_t i = 0; i < 3; i++)
		{
			std::cout << route[0][route.size()-1][i];
			if (i != 2) {
				std::cout << ",";
			}
		}
	std::cout<< std::endl;
	manager->getNavigationLogic()->setNextWaypoint(route[0][route[0].size()-1]);
	}else{
	std::cout << i+1<< std::endl;;
	manager->getNavigationLogic()->getNextWayPoint();
	route.clear();
	route.push_back( manager->getNavigationLogic()->getRoute());
	}
		for (size_t i = 0; i < 3; i++)
		{
			std::cout << route[0][route.size()][i];
			if (i != 2) {
				std::cout << ",";
			}
		}
		std::cout<<std::endl;
		std::cout<<std::endl;
		
	}
	
}

