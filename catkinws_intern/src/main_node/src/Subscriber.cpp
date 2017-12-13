#include "Subscriber.h"
#include "Manager.h"
#include <iostream>
#include <ros/ros.h>
Subscriber::Subscriber(Manager* manager)
{
	this->manager = manager;
	/* alle subscribers aanmaken enzo*/

	
	/*
	ros::Subscriber subpixelMap = manager->n.subscribe("pixelMap", 1000, pixelMapCallback);
	ros::Subscriber subclusterMap = manager->n.subscribe("clusterMap", 1000, clusterMapCallback);

	ros::Subscriber subBumper = manager->n.subscribe("bumpersignal", 1000, bumperCallback);

	ros::Subscriber subSonar = manager->n.subscribe("Sonarsignals", 1000, sonarCallback);

	ros::Subscriber subGPS = manager->n.subscribe("TOPIC_GPS!?", 1000, gpsCallback);

	*/
}

Subscriber::~Subscriber()
{

}

void Subscriber::pixelMapCallback(/*const std_msgs::Int32MultiArray::ConstPtr& pixelMsg*/)
{
	/*
	//Aanmaken van vector waarin de data uit de message wordt geplaatst.
	std::vector<int> vec(90000, 0);
	ROS_INFO("pixelMap Received!");

	//Zorgen dat de vector een pointer naar de data van de message krijgt.
	vec = pixelMsg->data;
	int intarray[300][300];

	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			intarray[i][j] = vec[i * 300 + j];
		}
	}
	manager->getRouteLogic()->setMaps(array,0);
	*/
}

void Subscriber::clusterMapCallback(/*const std_msgs::Int32MultiArray::ConstPtr& clusterMsg*/)
{
	/*
	//Aanmaken van vector waarin de data uit de message wordt geplaatst.
	std::vector<int> vec(36, 0);
	ROS_INFO("clusterMap Received!");

	//Zorgen dat de vector een pointer naar de data van de message krijgt.
	vec = clusterMsg->data;
	std::vector<std::vector<int>> intarray;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			intarray[i][j] = vec[i * 6 + j];
			//ROS_INFO("X%d - Y%d  :   %i", j, i, intarray[i][j]); // << Output data (handig voor debug)
		}
	}

	manager->getRouteLogic()->setMaps(intarray,1);
	*/
}

void Subscriber::bumperCallback(/*const std_msgs::String::ConstPtr& bumperMsg*/)
{

}

void Subscriber::sonarCallback(/*const std_msgs::String::ConstPtr& sonarMsg*/)
{

}

void Subscriber::gpsCallback(/*const marvelmind_nav::hedge_pos_a& hedgehog_pos_msg*/)
{

}
