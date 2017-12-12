#include "Publisher.h"
#include "Manager.h"
//#include "ros/ros.h"
Publisher::Publisher(Manager *manager)
{
	this->manager = manager;
	//this->setpoint_pub = manager->setpoint_pub;
}

Publisher::~Publisher()
{
}

void Publisher::publishMovements(double dist, double angle)
{
	/*
	geometry_msgs::Twist Twister;
	Twister.linear.x = dist;
	Twister.angular.z = angle;

	setpoint_pub.publish();
	ros::spinOnce();
	*/
}

void Publisher::publishWeb()
{

}