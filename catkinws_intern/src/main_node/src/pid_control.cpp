#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "/home/rickynator/rosaria_ws/devel/include/rosaria/BumperState.h"
#include "math.h"
#include <stdlib.h>
#include <pioneer_pid/controller.h>

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"

#include <geometry_msgs/Twist.h>

#define PI 3.14159265



//berekenen van kp, ki en kd
//gewenste nauwkeurigheid is 1 graad 1/180*pi = 0.017 rad
//kp = (afwijking amp / max fout) * J *(3 *2Pi)^2
//kp = (0.17/0.017) * 0.256 * 355
//kp = 10 * 0.256 * 355
//kp = 2.56 * 355 = 909.6 = 900

//wb = sqr(kp / J) = 60.6Hz  
//kd = 3/wb = 3/60 =0.05
//ki = 10/wb = 10/60 = 1/6 = 0.16666


double error[3];
double error_v[3];
// PID gains
//double Kp = 900, Ki = 0.16666, Kd = 0.05;
double Kp   = 2, Ki = 0.0003, Kd = 0.00023;
double Kp_v = 2, Ki_v = 0.0003, Kd_v = 0.5;
double error_deriv[3];
double error_deriv_v[3];
// Upper and lower saturation limits
double upper_limit =  1;
double lower_limit = -1; 
double upper_limit_v = 0.2;
double lower_limit_v = -0.2;
double massa_robot = 20;//kg
double J = 0.256; //J = (m * r^2)/2
double alpha = 0; 
double draaisnelheid = 0;
double rijsnelheid = 0;
double gewenste_hoek = 0;
double gewenste_positie_x = 0;
double huige_positie_x = 0;
double huidige_hoek = 0;
double error_integral;
double error_integral_v;
double proportional;
double proportional_v;
double integral;
double integral_v;
double derivative;
double derivative_v;
double control_effort;
double control_effort_v;
double od_hoek;
double od_v;
double R;
double G;
double F;
double Fv;




//odemetry sensor data
void chatterCallback(const nav_msgs::Odometry::ConstPtr& msg)
	{
	
	od_hoek = msg->pose.pose.orientation.z;
	huidige_hoek = od_hoek;
	F =   gewenste_hoek - huidige_hoek;
	ROS_INFO("huidige_hoek: [%f]" , huidige_hoek);

	od_v = msg->pose.pose.position.x;
	huige_positie_x = od_v;
	Fv = gewenste_positie_x - huige_positie_x;
	ROS_INFO("huidige_x: [%f]" , huige_positie_x);

	}
//gewenste setpoint uitlezen
void setpointCallback(const geometry_msgs::Twist::ConstPtr& twist)//setpoint uitlezen en de fout bepalen (want de fout bepaald de draairichting van de robot)
	{  
	G = twist->angular.z;//Dit is de gewenste positie
	gewenste_hoek = twist->angular.z;
	ROS_INFO("gewenste_hoek:[%f]" , twist->angular.z);
 	gewenste_positie_x = twist->linear.x;
	ROS_INFO("gewenste_x:[%f]" , twist->linear.x);	
	}

int main(int argc, char **argv)
{
	////   initialisatie   ////

	ros::init(argc, argv, "PID_regelaar");
	ros::NodeHandle n;
	ros::Rate rate(10);//loop dit programma met 10Hz

	ros::Subscriber sub = n.subscribe("/RosAria/pose", 1000, chatterCallback);
	
 	ros::Publisher  setpoint_pub = n.advertise<geometry_msgs::Twist>("setpoint", 1000);//publisher om met verschillende setpoints te testen.
	ros::Publisher  gewenste_snelheid_pub = n.advertise<geometry_msgs::Twist>("/RosAria/cmd_vel", 1000);
	ros::Subscriber setpoint_sub = n.subscribe("setpoint", 1000, setpointCallback);


	ros::Time prev_time;
	ros::Duration delta_t;
	////   continu    ////
	while (ros::ok)
	{
	/////////////////////////////////////



	error[2] = error[1];//error bij vorige vorige sample
	error[1] = error[0];//error bij vorige sample
	error[0] = F;

	error_v[2] = error_v[1];//error bij vorige vorige sample
	error_v[1] = error_v[0];//error bij vorige sample
	error_v[0] = Fv;

	ROS_INFO("error:[%f]" , error[0]);
	ROS_INFO("error_v:[%f]" , error_v[0]);
	ROS_INFO("gewenste_hoek:[%f]" , gewenste_hoek);
	ROS_INFO("gewenste_x:[%f]" , gewenste_positie_x);
	//ROS_INFO("error:[%f]" , error[0]);
	//ROS_INFO("error:[%f]" , error[0]);



		  // calculate delta_t
		  if (!prev_time.isZero()) // Not first time through the program  
		  {
		    delta_t = ros::Time::now() - prev_time;
		    prev_time = ros::Time::now();
		    if (0 == delta_t.toSec())
		    {
		      ROS_ERROR("delta_t is 0, skipping this loop. Possible overloaded cpu at time: %f", ros::Time::now().toSec());
		      //return;
		    }
		  }
		  else
		  {
		    ROS_INFO("prev_time is 0, doing nothing");
		    prev_time = ros::Time::now();
		   // return;
		  }

		  // integrate the error
		  error_integral += error[0] * delta_t.toSec();

		  // Apply windup limit to limit the size of the integral term
		  if ( error_integral > 1)
		    error_integral = 1;

		  if ( error_integral < -1)
		    error_integral = -1;
		    //ROS_INFO("error_integral:[%f]" , error_integral);

		//
		//als de error nagenoeg 0 is of langs de 0 wordt bewogen moet error_integral nul gesteld worden.
		//


		  // Take derivative of error (derivative is bepalen snelheid van afnamen fout)
		  // First the raw, unfiltered data:
		  error_deriv[2] = error_deriv[1]; 
		  error_deriv[1] = error_deriv[0]; 
		  error_deriv[0] = (error[0]-error[1])/delta_t.toSec();//geeft de snelheid waarmee de fout afneemt 
		  //ROS_INFO("error_deriv:[%f]" , error_deriv[0]);
		derivative = error_deriv[0] * Kd;
			

		  // calculate the control effort
		  proportional = Kp * error[0]; 			//P
		  integral = Ki * error_integral;			//i
		  derivative = Kd * error_deriv[0];			//d
		  control_effort = proportional + derivative;// + integral;	//de som van p+i+d is de regelwaarde
		ROS_INFO("control effort:[%f]" , control_effort);

		  error_deriv_v[2] = error_deriv_v[1]; 
		  error_deriv_v[1] = error_deriv_v[0]; 
		  error_deriv_v[0] = (error_v[0]-error_v[1])/delta_t.toSec();//geeft de snelheid waarmee de fout afneemt 
		derivative_v = error_deriv_v[0] * Kd_v;

		// calculate the control effort_v
		proportional_v = Kp_v * error_v[0]; 			
		control_effort_v = proportional_v + derivative_v;// + integral;	//de som van p+i+d is de regelwaarde
		ROS_INFO("control effort_v:[%f]" , control_effort_v);


		  // stel een limiet aan het maximale aanstuurkoppel
		  if (control_effort > upper_limit)
		  {
		    control_effort = upper_limit;
		  }
		  else if (control_effort < lower_limit)
		  {
		    control_effort = lower_limit;
		  }

		if(error[0] > 0.06 || error[0] < -0.06){//als de robot heading niet binnen 20 graden goed is mag hij niet vooruit rijden
			control_effort_v = 0;
			}
			else if (control_effort_v > upper_limit_v) // stel een limiet aan de maximale aanstuur snelheid
			  {
			    control_effort_v = upper_limit_v;
			  }
			  else if (control_effort_v < lower_limit_v)
				  {
				    control_effort_v = lower_limit_v;
				  }
		
		
		
	

	ROS_INFO("gewenste DSnelheid:[%f]" , control_effort);
	ROS_INFO("gewenste RSnelheid:[%f]" , control_effort_v);

	geometry_msgs::Twist Twister;
	Twister.linear.x = control_effort_v;
	Twister.angular.z = control_effort;

	//nieuwe gewenste draaisnelheid posten op "rosaria/cmd_vel" topic 
	gewenste_snelheid_pub.publish(Twister);
	

	/////////////////////////////////////
    	ros::spinOnce();
    	rate.sleep();//zorg dat dit 5 x per seconden wordt uitgevoerd. 
  	}
	

  return 0;
}

