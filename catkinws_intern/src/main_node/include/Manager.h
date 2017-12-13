
#ifndef HEADERFILE_Manager
#define HEADERFILE_Manager
//#include <ros/ros.h>
#include "Subscriber.h"
#include "ControllerLogic.h"
#include "SensorLogic.h"
#include "RouteLogic.h"
#include "NavigationLogic.h"
#include "Publisher.h"
#include "Tests.h"

class Manager
{
public:
	int i;
	Manager();
	~Manager();
	SensorLogic * getSensorLogic();
	ControllerLogic * getControllerLogic();
	NavigationLogic * getNavigationLogic();
	RouteLogic * getRouteLogic();
	Subscriber * getSubscriber();
	Publisher *getPublisher();
	ros::NodeHandle n;
private:
	Subscriber*			S;
	Publisher*			P;
	SensorLogic*		sensor;
	ControllerLogic*	controller;
	RouteLogic*			route;
	NavigationLogic	*	nav;
	Tests*				test;
};
#endif
