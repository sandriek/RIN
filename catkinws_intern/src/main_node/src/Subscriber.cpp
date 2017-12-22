#include "Subscriber.h"
#include "Manager.h"
#include <ros/ros.h>
Manager* managertemp;
bool Received;
Subscriber::Subscriber(Manager* manager, ros::NodeHandle n)
{
	this->manager = manager;
	managertemp = manager;
	/* alle subscribers aanmaken enzo*/

	
	void pixelMapCallback(const std_msgs::Int32MultiArray::ConstPtr& pixelMsg);
	void clusterMapCallback(const std_msgs::Int32MultiArray::ConstPtr& clusterMsg);
	void bumperCallback(const std_msgs::String::ConstPtr& bumperMsg);
	void sonarCallback(const std_msgs::String::ConstPtr& sonarMsg);
	void gpsCallback(const marvelmind_nav::hedge_pos_a& hedgehog_pos_msg);
	void MotionSend(std_msgs::String s );
	void CheckReached(std_msgs::String s );

	ros::Duration(10).sleep();
	ros::Subscriber subpixelMap = n.subscribe("pixelMap", 1000, pixelMapCallback);
	ros::Subscriber subclusterMap = n.subscribe("clusterMap", 1000, clusterMapCallback);

	ros::Subscriber subBumper = n.subscribe("bumpersignal", 1000, bumperCallback);

	ros::Subscriber subSonar = n.subscribe("Sonarsignals", 1000, sonarCallback);

	ros::Subscriber subGPS = n.subscribe("GPS", 1000, gpsCallback);
	ros::Subscriber sub_checkMotionSend = n.subscribe("motion", 100, MotionSend);
	ros::Subscriber sub_checkReached = n.subscribe("WPC", 100, CheckReached);
	while(ros::ok()) { 
		ros::spinOnce();
		}
	
}

Subscriber::~Subscriber()
{

}
void Subscriber::setReceived(bool b){
	Received = false;
}
void pixelMapCallback(const std_msgs::Int32MultiArray::ConstPtr& pixelMsg)
{
	
	//Aanmaken van vector waarin de data uit de message wordt geplaatst.
	std::vector<int> vec(90000, 0);
	ROS_INFO("pixelMap Received!");

	//Zorgen dat de vector een pointer naar de data van de message krijgt.
	vec = pixelMsg->data;
	std::vector<std::vector<int>> intarray;

	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			intarray[i][j] = vec[i * 300 + j];
		}
	}
	managertemp->getRouteLogic()->setMaps(intarray,0);
	
}

void clusterMapCallback(const std_msgs::Int32MultiArray::ConstPtr& clusterMsg)
{
	
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

	managertemp->getRouteLogic()->setMaps(intarray,1);
	
}
bool Subscriber::isReceived(){


return Received;
}

void bumperCallback(const std_msgs::String::ConstPtr& bumperMsg)
{

}

void sonarCallback(const std_msgs::String::ConstPtr& sonarMsg)
{

}

void gpsCallback(const marvelmind_nav::hedge_pos_a& hedgehog_pos_msg){
/*set Position*/
std::vector<double> pos;
pos.push_back(hedgehog_pos_msg.x_m);
pos.push_back(hedgehog_pos_msg.y_m);
pos.push_back(0);
managertemp->getNavigationLogic()->setPosition(pos);
}
void MotionSend(std_msgs::String s)
{
	Received = true;
	std::cout<< "received Movent " <<std::endl;
}
void CheckReached(std_msgs::String s)
{
	managertemp->getNavigationLogic()->reachedWayPoint(true);
	std::cout<< "at waypoint" <<std::endl;
}
