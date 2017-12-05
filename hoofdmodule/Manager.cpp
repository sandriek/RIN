#include "Manager.h"

Manager::Manager()
{
}

Manager::~Manager()
{
}
SensorLogic Manager::getSensorLogic()
{
	SensorLogic s;
	return s;
}

ControllerLogic Manager::getControllerLogic()
{
	ControllerLogic c;
	return c;
}

NavigationLogic Manager::getNavigationLogic()
{
	NavigationLogic n;
	return n;
}

RouteLogic Manager::getRouteLogic()
{
	RouteLogic r;
	return r;
}

Subscriber Manager::getSubscriber()
{
	Subscriber s;
	return s;
}
Publisher Manager::getPublisher()
{
	Publisher p;
	return p;
}