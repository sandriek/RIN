#include "Manager.h"
#include <iostream>
#include <ros/ros.h>
#include <thread>

int main(int argc, char ** argv)
{
	
	Manager* m = new Manager(argc, argv);
	
	return 0;
}
Manager::Manager(int argc, char ** argv)
{

	void initSubscriber(ros::NodeHandle n, Manager *manager);
	void initOther(ros::NodeHandle n, Manager *manager);
	std::cout << "starting MainNode" << std::endl;
		ros::init(argc, argv, "main_node");
     			ros::NodeHandle n;


			std::thread thread = std::thread(initSubscriber, n, this);
			std::thread thread2 = std::thread(initOther, n, this);
		std::cout << "Threads running" << std::endl;
		while(ros::ok()) { 
		ros::spinOnce();
		}
		
}

Manager::~Manager()
{
}
void initSubscriber(ros::NodeHandle n, Manager *manager)
{
 std::cout << "starting Subscriber Thread" << std::endl;
 manager->S = new Subscriber(manager,n);
}

void initOther(ros::NodeHandle n, Manager *manager)
{
			std::cout << "starting Main Thread" << std::endl;
			manager->P = new Publisher(manager,n);
			manager->sensor = new SensorLogic(manager);
			manager->controller = new ControllerLogic(manager);
			manager->route = new RouteLogic(manager);
			manager->nav = new NavigationLogic(manager);
			manager->test = new Tests(manager);
			std::cout << "All objects are created" << std::endl;
			//manager->test->TestFirstWayPoint();
			//manager->test->TestRoute();
			while(true){
			std::cout<<manager->getNavigationLogic()->startRoute()<< std::endl;}
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
void Manager::setSubscriber(Subscriber *sub){
	this->S = sub;
}


