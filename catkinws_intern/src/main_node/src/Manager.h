#pragma once
#ifndef HEADERFILE_Manager
#define HEADERFILE_Manager

#include "Subscriber.h"
#include "ControllerLogic.h"
#include "SensorLogic.h"
#include "RouteLogic.h"
#include "NavigationLogic.h"
#include "Publisher.h"
#include "Tests.h"
#include <ros/ros.h>

class Manager
{
public:
	int i;
	Manager(int argc, char ** argv);
	~Manager();
	SensorLogic * getSensorLogic();
	ControllerLogic * getControllerLogic();
	NavigationLogic * getNavigationLogic();
	RouteLogic * getRouteLogic();
	Subscriber * getSubscriber();
	void setSubscriber(Subscriber *sub);
	Publisher *getPublisher();

Subscriber*			S;
	Publisher*			P;
	SensorLogic*		sensor;
	ControllerLogic*	controller;
	RouteLogic*			route;
	NavigationLogic	*	nav;
	Tests*				test;
private:
	
};
#endif
