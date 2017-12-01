#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "/home/rickynator/rosaria_ws/devel/include/rosaria/BumperState.h"
#include "math.h"
#include <stdlib.h>

#define PI 3.14159265


//void bumper_state(const rosaria::BumperState msg)
//{


//}//void

int pixels_per_centimeter = 1;
int pixels_wide_and_hight_of_one_square = 50; 

double waypointsX[6];
double waypointsY[6];

double waypoint[/*collom*/6][/*row*/6][/*height*/3];
int cwr = 0; //current_waypoint_row;
int cwc = 0; //current_waypoint_collom;

double current_waypoint[3];

double pos_Robot[3]; // = {x,y,z}

double waypoint_minus_robotPosition[2]; 	// = {x,y}
double radius; 
double switch_radius = 10;//cm




int main(int argc, char **argv)
{
	////   initialisatie   ////

	//ros::init(argc, argv, "inspectie_programma");
	//ros::NodeHandle n;
	//ros::Subscriber sub = n.subscribe("RosAria/bumper_state", 1000, bumper_state);
	//ros::Publisher  nood = n.advertise<geometry_msgs::Twist>("RosAria/cmd_vel", 1);
	//ros::Publisher pub = n.advertise<std_msgs::String>("bumpersignal", 1000);


	//waypoints uitzetten
	for(int r = 0; r++; r < 6){//step a row
		for(int c = 0; c++; c < 6){//step a collom
			waypoint[r][c][0] = (r*50)+25; //X
			waypoint[r][c][1] = (c*50)+25; //Y
			waypoint[r][c][2] = 0;         //Z
		}
	}
        //huidige waypoint om te volgen initialiseren
	//current_waypoint[]= {waypoint[r][c][0], waypoint[r][c][1], waypoint[r][c][2]};//x,y,z
	current_waypoint[0]= waypoint[0][0][0];//x
 	current_waypoint[1]= waypoint[0][0][1];//y
	current_waypoint[2]= waypoint[0][0][2];//z

	ros::Rate rate(10);


	////   continu    ////
	while (ros::ok)
	{
	/// bepalen afstand (radius) tussen robot xy positie en huidig waypoint xy positie ///
        waypoint_minus_robotPosition[0] = current_waypoint[0] - pos_Robot[0];//x
	waypoint_minus_robotPosition[1] = current_waypoint[1] - pos_Robot[1];//y
	radius = sqrt((waypoint_minus_robotPosition[1]*waypoint_minus_robotPosition[1]) + (waypoint_minus_robotPosition[0]*waypoint_minus_robotPosition[0]));


    	//switchen tussen waypoints
	if(radius <= switch_radius){

		if(current_waypoint[1] == 5){//aan het einde van rij?
			current_waypoint[0]++;//een rij verder gaan
			current_waypoint[1] = 0;//collom op 0 zetten
		}	
		else{//niet aan het einde van rij
			current_waypoint[1]++;//een collom verder gaan
			
		}

	}
	//robot orientatie en positie bepalen
	//subscriber odementry robot


	//robot commando's opstellen
	

	//


	//programma beeindigen


   
    	ros::spinOnce();
    	rate.sleep();
  	}

  return 0;
}

