#pragma once
#ifndef HEADERFILE_Publisher
#define HEADERFILE_Publisher
//#include "Manager.h"
#include <iostream>
#include <stdlib.h> 
#include <vector>
class Manager;
class Publisher
{
public:
	Publisher(Manager *manager);
	~Publisher();
	void publishMovements(double dist, double angle);
	void publishWeb();
	Manager *manager;
	//ros::Publisher  setpoint_pub;
private:

};
#endif