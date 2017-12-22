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


std::vector<std::vector<int>> RouteLogic::calculateNextWayPoint(std::vector<int> wayPoint)
{

	std::vector<std::vector<std::vector<int>>> route;
	std::vector<std::vector<std::vector<int>>> tempGrid1;
	if(tempGrid.empty()){
	for (size_t ii = 0; ii < 3; ii++)
		{
			tempGrid1.push_back(wayPointsGrid[ii]);
			
		}
	}
	else{
	tempGrid1 = wayPointsGrid;
	}




	route.push_back(checkClosest(wayPoint, 0, tempGrid1));


	for (size_t i = 0; i < 3; i++)
		{
			std::cout << (route[0][route[0].size()-1][i]/clusterSize)- 0.5;
			if (i != 2) {
				std::cout << ",";
			}
		}
	std::cout<<std::endl;
	for (size_t x = 0; x < 6; x++)
		{
	for (size_t y = 0; y < 6; y++)
		{
			std::cout << wayPointsGrid[x][y][3];
		}
			std::cout <<std::endl;
		}
	std::cout<<std::endl;
	std::cout<<std::endl;

	manager->getNavigationLogic()->setCurrenWaypoint(wayPoint);
	return route[0];
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
	//wayPointsGrid[closest[0]/clusterSize-0.5][closest[1]/clusterSize-0.5][3] = 1;
	return closest;
}
std::vector<std::vector<int>> RouteLogic::checkClosest(std::vector<int> wayPoint, int steps, std::vector<std::vector<std::vector<int>>> tempGrid1)
{
	bool notDone = false;
	std::vector<std::vector<int>> closest;
	std::vector<std::vector<int>> closesttemp;
	std::vector<int> closestints;
	int closestindex;
	int closestint;
	std::vector<std::vector<std::vector<int>>> temp;
	closest.push_back(wayPoint);
	/*for (size_t i = 0; i < 3; i++)
		{
			std::cout << wayPoint[i];
			if (i != 2) {
				std::cout << ",";
			}
		}
	std::cout<<std::endl;*/

	

		if((wayPoint[1] / clusterSize) < (wayPointsGrid[0].size()-0.5))
		{
			
			if (       wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5][3] == 0) {
					//std::cout<<"up"<<std::endl;
					wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5][4] = steps;
					if(steps == 0){
					wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5][3] = 1;
					}
				closest.push_back(wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5]);
				return closest;
			}

			
			
		}
	


	
		if((wayPoint[0] / clusterSize) != 0.5)
		{
			
			if (wayPointsGrid[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5][3] == 0) {
					//std::cout<<"left"<<std::endl;
				 	wayPointsGrid[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5][4] = steps;
					if(steps == 0){
					wayPointsGrid[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5][3] = 1;
					}
				closest.push_back(wayPointsGrid[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5]);
				return closest;
			}
			
		}


		if((wayPoint[1] / clusterSize) != 0.5)
		{
			
			if (wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5][3] == 0) {
					//std::cout<<"down"<<std::endl;
					wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5][4] = steps;
					if(steps == 0){
						wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5][3] = 1;
					}
				closest.push_back(wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5]);
				return closest;
			}
			
		}
	

		if((wayPoint[0] / clusterSize) < (wayPointsGrid.size()-0.5))
		{
			
			if (	   wayPointsGrid[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize) - 0.5][3] == 0) {
					//std::cout<<"right"<<std::endl;	
					wayPointsGrid[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize) - 0.5][4] = steps;
					if(steps == 0){
					wayPointsGrid[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize) - 0.5][3] = 1;
					}
				closest.push_back(wayPointsGrid[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize) - 0.5]);
				return closest;
			}
			
		}
//std::cout<<"last"<<std::endl;
	if((wayPoint[1] / clusterSize) < (wayPointsGrid[0].size()-0.5)){
		if(tempGrid1[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5][3] < 2){
				//std::cout<<"up"<<std::endl;
				tempGrid1[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5][3] = 5;
				std::vector<std::vector<int>> first	= checkClosest(wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) + 0.5]	, steps + 1 , tempGrid1);
				temp.push_back(first);
					
				}
	}

	if((wayPoint[0] / clusterSize) != 0.5){
	if( tempGrid1[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5][3] < 2 ){
				//std::cout<<"left"<<std::endl;
				tempGrid1[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5][3] = 5;
				std::vector<std::vector<int>> second = checkClosest(wayPointsGrid[(wayPoint[0] / clusterSize) - 1.5][(wayPoint[1] / clusterSize) - 0.5]	, steps + 1 , tempGrid1);
				temp.push_back(second);
				
			}
	}
	if((wayPoint[1] / clusterSize) != 0.5){
	if(tempGrid1[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5][3] < 2){
				//std::cout<<"down"<<std::endl;
				tempGrid1[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5][3] = 5;	
				std::vector<std::vector<int>> third	= checkClosest(wayPointsGrid[(wayPoint[0] / clusterSize) - 0.5][(wayPoint[1] / clusterSize) - 1.5]	, steps + 1 , tempGrid1);
				temp.push_back(third);
				
			}
	}
	if((wayPoint[0] / clusterSize) < (wayPointsGrid.size()-0.5)){
	if(tempGrid1[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize)][3] < 2 ){
				//std::cout<<"right"<<std::endl;
				tempGrid1[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize)][3] = 5;
				std::vector<std::vector<int>> fourt	= checkClosest(wayPointsGrid[(wayPoint[0] / clusterSize) + 0.5][(wayPoint[1] / clusterSize)-0.5], steps + 1, tempGrid1);
				temp.push_back(fourt);
		
			}
	}

	if(temp.size() > 0){
	//	std::cout<<"  Steps:  " << steps<<std::endl;
	
	for (int i = 0; i < temp.size(); i++)
	{	
		closestints.push_back(temp[i][temp[i].size()-1][4]);
	}
	closestint = *std::min_element(closestints.begin(), closestints.end());
	//std::cout<<"closes="<<closestint<<std::endl;
	for (int i = 0; i < closestints.size(); i++)
		{
			if(closestints[i] == closestint){
			closestindex = i;
			}
		}
	//std::cout<<"closesed index="<<closestindex<<std::endl;
	for (int i = 0; i < temp[closestindex].size(); i++)
	{
		closest.push_back(temp[closestindex][i]);
	}
	}else{};
	if(steps == 0){
	int tempX = closest[closest.size()-1][0];
	int tempY =closest[closest.size()-1][1];
	wayPointsGrid[(tempX / clusterSize)-0.5][(tempY / clusterSize) - 0.5][3] = 1;}
	//std::cout<<"found "<< "Steps:  " << steps<<std::endl;
	
	return closest;
}








void RouteLogic::setMaps(std::vector<std::vector<int>> map, int maptype)
{
	if (maptype == 0) {
		for(int m = 0; m < map.size(); m++){
		pixelMap.push_back( map[m]);	
		}
	}
	if (maptype == 1) {
		for(int m = 0; m < map.size(); m++){
		clusterMap.push_back(map[m]);
		}
	}
	std::cout<<"done setting maps"<<std::endl;
	if(!pixelMap.empty() && !clusterMap.empty()){
		calculate();
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
void RouteLogic::calculate()
{

	for(int index = 0; index<6;index++){
	wayPointsGrid.push_back({{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}});
	}
	
	clusterSize = pixelMap.size() / clusterMap.size();
	for (int x = 0; x < clusterMap.size(); x++)
	{
		for (int y = 0; y < clusterMap[x].size(); y++)
		{
			wayPointsGrid[x][y] = { (int)(clusterSize) * x + 25, (int)(clusterSize) * y + 25 , 0 , 0, 0 };
			wayPoints.push_back({ (int)(clusterSize) * x +25 ,  (int)(clusterSize) * y + 25 , 0 , 0, 0 });
		}
	};
}
std::vector<std::vector<int>> RouteLogic::checkClosestRoute(std::vector<int> currentwayPoint, int steps,std::vector<int> destinationwayPoint,  std::vector<std::vector<std::vector<int>>> tempGrid1)
{







}

