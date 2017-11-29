#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "/home/rickynator/rosaria_ws/devel/include/rosaria/BumperState.h"
#include <stdlib.h>
bool front = false;
bool back = false;

bool frontbumper[5];
bool frontbumper_pre[5];
bool rearbumper[5]; 
bool rearbumper_pre[5]; 

geometry_msgs::Twist t;
std::stringstream S;
std_msgs::String msgs;

void bumper_state(const rosaria::BumperState msg)
{

////    Voorbumpers    ////
	for (size_t i = 0; i < 5; i++)
	{

		if( msg.front_bumpers[i]==true )
		{
		frontbumper[i] = true;	//toestand van bumper onthouden
			if(frontbumper[i] == true && frontbumper_pre[i] == false)//ooow shiiiit rising edge
			{
				frontbumper_pre[i] = true;
				S.str(std::string());//maak de strinstream leeg voordat er nieuwe waarde naartoe woorden geschreven
				S << "front_" << i << "_High ";
				msgs.data = S.str();
				ROS_INFO_STREAM(S.str());
			}

			
	   			
	  	}//if
		else if( msg.front_bumpers[i]==false )
		{
		frontbumper[i] = false;//toestand van bumper onthouden

			if(frontbumper[i] == false && frontbumper_pre[i] == true)//ooow shiiiit faling edge
			{
				frontbumper_pre[i] = false;
				S.str(std::string());
				S << "front_" << i << "_Clear ";
				msgs.data = S.str();
				ROS_INFO_STREAM(S.str());
			}
			
		}//if
	}//for

////    achter bumpers
	for (size_t i = 0; i < 5; i++)
	{
	   	if( msg.rear_bumpers[i]== true )
		{
			rearbumper[i] = true;	//toestand van achter bumper onthouden 
			if(rearbumper[i] == true && rearbumper_pre[i] == false)//ooow shiiiit rising edge
			{
				rearbumper_pre[i] = true;
				S.str(std::string());
				S << "Rear_" << i << "_High ";
				msgs.data = S.str();
				ROS_INFO_STREAM(S.str());

			}
		}//if
		else if( msg.rear_bumpers[i]==false )
		{
			rearbumper[i] = false;	//toestand van achter bumper onthouden
			if(rearbumper[i] == false && rearbumper_pre[i] == true)//ooow shiiiit faling edge
			{
				rearbumper_pre[i] = false;
				S.str(std::string());
				S << "Rear_" << i << "_Clear ";
				msgs.data = S.str();
				ROS_INFO_STREAM(S.str());
			}
		    	
	  	}//if
	}//for
}//void

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "bumper_Node");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("RosAria/bumper_state", 1000, bumper_state);
  ros::Publisher  nood = n.advertise<geometry_msgs::Twist>("RosAria/cmd_vel", 1);
  ros::Publisher pub = n.advertise<std_msgs::String>("bumpersignal", 1000);
  

    
  ros::Rate rate(10);

  while (ros::ok)
  {
    

    pub.publish(msgs);
    nood.publish(t);
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
//t.linear.x = -1; //commando om de robot achteruit te laten rijden. 
//t.linear.x = 1; //commando om de robot achteruit te laten rijden. 
