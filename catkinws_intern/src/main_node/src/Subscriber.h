#ifndef HEADERFILE_Subscriber
#define HEADERFILE_Subscriber
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include <array>
#include <vector>
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

#include "/home/sander/Ros/devel/include/marvelmind_nav/hedge_pos.h"
#include "/home/sander/Ros/devel/include/marvelmind_nav/hedge_pos_a.h"
#include "/home/sander/Ros/devel/include/marvelmind_nav/beacon_pos_a.h"

#include "SonarObject.h"
#include "BumperObject.h"
#include "NavigationObject.h"
#include "MapObject.h"
#include "RosariaObject.h"
#include "ControllerObject.h"
#include <ros/ros.h>
#include <iostream>
class Manager;

class Subscriber
{
public:
	Subscriber(Manager* manager, ros::NodeHandle n);
	~Subscriber();
	Manager* manager;
	bool isReceived();
	void setReceived(bool b);
	//Tijdelijke public variabele.
	//MapObject* maps = new MapObject();

private:
	
};
#endif
