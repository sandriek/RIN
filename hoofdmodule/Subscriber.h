#include "SonarObject.h"
#include "BumperObject.h"
#include "NavigationObject.h"
#include "MapObject.h"
#include "RosariaObject.h"
#include "ControllerObject.h"
#include <iostream>
class Manager;

class Subscriber
{
public:
	Subscriber(Manager* manager);
	~Subscriber();

	//Tijdelijke public variabele.
	MapObject maps = new MapObject();

private:
	void pixelMapCallback(const std_msgs::Int32MultiArray::ConstPtr& pixelMsg);
	void clusterMapCallback(const std_msgs::Int32MultiArray::ConstPtr& clusterMsg);

	void bumperCallback(const std_msgs::String::ConstPtr& bumperMsg);

	void sonarCallback(const std_msgs::String::ConstPtr& sonarMsg);

	void gpsCallback(const marvelmind_nav::hedge_pos_a& hedgehog_pos_msg);
};