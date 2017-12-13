#include "Publisher.h"
#include "Manager.h"
Publisher::Publisher(Manager *manager)
{
	this->manager = manager;
	//setpoint_pub = manager->n.advertise<geometry_msgs::Twist>("setpoint", 1000);
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
