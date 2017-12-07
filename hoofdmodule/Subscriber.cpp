#include "Subscriber.h"
Subscriber::Subscriber(Manager* manager)
{
	std::cout << "subscriber";
	/* alle subscribers aanmaken enzo*/

	ros::NodeHandle n;

	ros::Subscriber subpixelMap = n.subscribe("pixelMap", 1000, pixelMapCallback);
	ros::Subscriber subclusterMap = n.subscribe("clusterMap", 1000, clusterMapCallback);

	ros::Subscriber subBumper = n.subscribe("bumpersignal", 1000, bumperCallback);

	ros::Subscriber subSonar = n.subscribe("Sonarsignals", 1000, sonarCallback);

	ros::Subscriber subGPS = n.subscribe("TOPIC_GPS!?", 1000, gpsCallback);


}

Subscriber::~Subscriber()
{

}

void Subscriber::pixelMapCallback(const std_msgs::Int32MultiArray::ConstPtr& pixelMsg)
{
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
}

void Subscriber::clusterMapCallback(const std_msgs::Int32MultiArray::ConstPtr& clusterMsg)
{
	//Aanmaken van vector waarin de data uit de message wordt geplaatst.
	std::vector<int> vec(36, 0);
	ROS_INFO("clusterMap Received!");

	//Zorgen dat de vector een pointer naar de data van de message krijgt.
	vec = clusterMsg->data;
	int intarray[6][6];

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			intarray[i][j] = vec[i * 6 + j];
			//ROS_INFO("X%d - Y%d  :   %i", j, i, intarray[i][j]); // << Output data (handig voor debug)
		}
	}

	//WAAR DE INTARRAY LATEN?
}

void Subscriber::bumperCallback(const std_msgs::String::ConstPtr& bumperMsg)
{

}

void Subscriber::sonarCallback(const std_msgs::String::ConstPtr& sonarMsg)
{

}

void Subscriber::gpsCallback()
{

}