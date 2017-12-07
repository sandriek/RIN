#include "ros/ros.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include <array>
#include <vector>

void subvectorCallback(const std_msgs::Int32MultiArray::ConstPtr& msg) {
	std::vector<int> vec(36, 0);	//Aanmaken van vector waarin de data uit de message wordt geplaatst.
	ROS_INFO("Map Received!");

	vec = msg->data;		//Zorgen dat de vector een pointer naar de data van de message krijgt.
	int intarray[6][6];		

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			intarray[i][j] = vec[i * 6 + j];
			ROS_INFO("X%d - Y%d  :   %i", j, i, intarray[i][j])
		}
	}
}

int main(int argc, char **argv) {

	ros::init(argc, argv, "subscriberMap");						//Initialiseren van de subscriber
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("clusterMap", 1000, subvectorCallback);
	ros::spin();

	return 0;
}
