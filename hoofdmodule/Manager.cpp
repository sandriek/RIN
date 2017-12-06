#include "Manager.h"
#include <iostream>

int main(int argc, char ** argv)
{
	Manager* m = new Manager();
	Subscriber*			S = new Subscriber(m);
	Publisher*			P = new Publisher(m);
	SensorLogic*		sensor = new SensorLogic(m);
	ControllerLogic*	controller = new ControllerLogic(m);
	RouteLogic*			route = new RouteLogic(m);
	NavigationLogic	*nav = new NavigationLogic(m);
	while (true) {}
	return 0;
}
Manager::Manager()
{
	std::cout << "Manager";
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
	std::cout << "got ya Controller";
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