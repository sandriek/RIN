#include "NavigationLogic.h"
#include "Manager.h"
#include <cmath>
NavigationLogic::NavigationLogic(Manager* manager)
{
	this->manager = manager;
}

NavigationLogic::~NavigationLogic()
{
}

bool NavigationLogic::startRoute()
{
	if(!manager->getRouteLogic()->clusterMap.empty() &&!manager->getRouteLogic()->pixelMap.empty()){
		manager->getNavigationLogic()->setStartingWaypoint();
		//getNextWayPoint();
		goToFirstPoint();
		
		while(WayPointReached){

		}

		sendMovement(0, -getFirstWayPoint()[4]);
	//mischien nieuwe thread starten voor het route volgen.
		
		while(followingRoute){
	
			if(WayPointReached && Route.size() > 1){
				setCurrenWaypoint(nextWayPoint);
				Route.erase(Route.begin());
				setNextWaypoint(Route[0]);
				calculateDirection();
	
			}else{
				
				if(WayPointReached && Route.size() <= 1){	
					getNextWayPoint();
				}else{
				calculateDirection();
				}		
			}
		}
		return true;
	}
	return false;
}

void NavigationLogic::stopRoute()
{
followingRoute = false;
}

void NavigationLogic::resumeRoute()
{
followingRoute = true;
	while(followingRoute){

		if(WayPointReached && Route.size() > 1){
			setCurrenWaypoint(nextWayPoint);
			Route.erase(Route.begin());
			setNextWaypoint(Route[0]);
			calculateDirection();

		}else{
			
			if(WayPointReached && Route.size() <= 1){	
				getNextWayPoint();
			}else{
			calculateDirection();
			}		
		}
	}
}

void NavigationLogic::calculateDirection()
{
	double rotation;
	/*nextWayPoint = { 0,0,0 };
	position = { 0,0,0 };*/
	
	double difX =  position[0] - nextWayPoint[0];
	double difY =  position[1] - nextWayPoint[1];
	double angleNeeded;
	double difAngle;
	double distance;

	angleNeeded = atan(difY / difX);
	distance = sqrt((difY*difY) + (difX*difX));


	difAngle = Orientation - angleNeeded;
	
	sendMovement(distance, difAngle);

	
	
}

void NavigationLogic::sendMovement(double distance, double angle)
{
	manager->getPublisher()->publishMovements(distance, angle);
}

void NavigationLogic::getNextWayPoint()
{
	Route = manager->getRouteLogic()->calculateNextWayPoint(nextWayPoint);
	setNextWaypoint(Route[Route.size()-1]);

}

void NavigationLogic::setCurrenWaypoint(std::vector<int> WayPoint)
{
	if(currentWayPoint.size()<WayPoint.size()){
		for(int index = 0; index <WayPoint.size();index++){
			currentWayPoint.push_back( WayPoint[index]);
		}
	}
	else{
		for(int index = 0; index <WayPoint.size();index++){
			currentWayPoint[index] = WayPoint[index];
		}
	}
}
void NavigationLogic::setNextWaypoint(std::vector<int> WayPoint)
{
	if(nextWayPoint.size()<WayPoint.size()){
		for(int index = 0; index <WayPoint.size();index++){
			nextWayPoint.push_back(WayPoint[index]);
		}
	}
	else{
		for(int index = 0; index <WayPoint.size();index++){
			nextWayPoint[index] = WayPoint[index];
		}
	}

}

std::vector<double> NavigationLogic::getPosition()
{
	return position;
}

void NavigationLogic::setStartingWaypoint()
{
	firstWayPoint = manager->getRouteLogic()->calculateFirstWayPoint(position);
	//std::cout << "wayoints set" << std::endl;	
std::vector<int> temp;
	for(int i = 0; i < 6; i++){	
	temp.push_back((int)firstWayPoint[i]);
	}
	for(int i = 0; i < 6; i++){	
	nextWayPoint.push_back((int)temp[i]);
	}
	Route.push_back(nextWayPoint);
}

void NavigationLogic::goToFirstPoint()
{
	std::vector<double> first = getFirstWayPoint();

	sendMovement(first[5], first[4]);
}


void NavigationLogic::setPosition(std::vector<double> pos)
{
	this->position = pos;
}

std::vector<double> NavigationLogic::getFirstWayPoint() {
	return firstWayPoint;
}
void NavigationLogic::CorrectMovement() {
	std::vector<double> position = manager->getNavigationLogic()->getPosition();
	std::vector<int> WayPoint = this->nextWayPoint;
	double angle;

		double difX = position[0] - WayPoint[0];
		double difY = position[1] - WayPoint[1];
		angle = tan(difY / difX);
		double distance = sqrt((difY*difY) + (difX*difX));
		sendMovement(distance, angle);

}
std::vector<std::vector<int>> NavigationLogic::getRoute(){

return Route;
}
void NavigationLogic::NavigationLogic::reachedWayPoint(bool boolean){
	WayPointReached = boolean;
}
