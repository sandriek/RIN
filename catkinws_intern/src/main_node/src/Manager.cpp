#include "Manager.h"
#include <iostream>
#include <ros/ros.h>


int main(int argc, char ** argv)
{
	
	Manager* m = new Manager(argc, argv);
	
	while (true) {}
	return 0;
}
Manager::Manager(int argc, char ** argv)
{
	std::cout << "starting MainNode" << std::endl;

	
			S = new Subscriber(this);
			P = new Publisher(this);
			sensor = new SensorLogic(this);
			controller = new ControllerLogic(this);
			route = new RouteLogic(this);
			nav = new NavigationLogic(this);
			test = new Tests(this);
			std::cout << "All objects are created" << std::endl;
			test->TestFirstWayPoint();
}

Manager::~Manager()
{
}
SensorLogic * Manager::getSensorLogic()
{
	return sensor;
}

ControllerLogic * Manager::getControllerLogic()
{
	return controller;
}

NavigationLogic * Manager::getNavigationLogic()
{
	return nav;
}

RouteLogic * Manager::getRouteLogic()
{
	return route;
}

Subscriber * Manager::getSubscriber()
{
	return S;
}
Publisher * Manager::getPublisher()
{
	return P;
}


