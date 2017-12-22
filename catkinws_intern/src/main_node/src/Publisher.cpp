#include "Publisher.h"
#include "Subscriber.h"
#include "Manager.h"
#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
Publisher::Publisher(Manager *manager , ros::NodeHandle n)
{
	this->manager = manager;
	setpoint_pub = n.advertise<geometry_msgs::Twist>("setpoint", 1000);
}

Publisher::~Publisher()
{
}

void Publisher::publishMovements(double dist, double angle)
{
	if(ros::ok()){
	
	geometry_msgs::Twist Twister;
	Twister.linear.x = dist;
	Twister.angular.z = (angle/180);
	while(!manager->getSubscriber()->isReceived()){
	setpoint_pub.publish(Twister);
	ros::Duration(2).sleep();
	}	
	ros::spinOnce();
std::cout << "send " << std::endl;
	}
}

void Publisher::publishWeb()
{

}
