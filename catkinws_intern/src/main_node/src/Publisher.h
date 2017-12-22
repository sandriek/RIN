#pragma once
#ifndef HEADERFILE_Publisher
#define HEADERFILE_Publisher
//#include "Manager.h"
#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <ros/ros.h>
class Manager;
class Publisher
{
public:
	Publisher(Manager *manager, ros::NodeHandle n);
	~Publisher();
	void publishMovements(double dist, double angle);
	void publishWeb();
	Manager *manager;
	ros::Publisher  setpoint_pub;
	bool NotReceived = true;
private:

};
#endif
