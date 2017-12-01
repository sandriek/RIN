#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "/home/rickynator/rosaria_ws/devel/include/rosaria/BumperState.h"
#include "math.h"
#include <stdlib.h>
#include <pioneer_pid/controller.h>

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
// PID gains
double Kp = 900, Ki = 0.16666, Kd = 0.05;
double error_deriv[3]
// Upper and lower saturation limits
double upper_limit =  2, lower_limit = 2; //maximale en minimale aanstuur koppel
double massa_robot = 20;//kg
double J = 0.256; //J = (m * r^2)/2
double alpha; 
double draaisnelheid;
double max draaisnelheid;
double minimum_draaisnelheid = -2;
double maximum_draaisnelheid =  2;  

int main(int argc, char **argv)
{
	////   initialisatie   ////

	//ros::init(argc, argv, "inspectie_programma");
	//ros::NodeHandle n;
	//ros::Subscriber sub = n.subscribe("RosAria/bumper_state", 1000, bumper_state);
	//ros::Publisher  nood = n.advertise<geometry_msgs::Twist>("RosAria/cmd_vel", 1);
	//ros::Publisher pub = n.advertise<std_msgs::String>("bumpersignal", 1000);



	////   continu    ////
	while (ros::ok)
	{
	/////////////////////////////////////

	error[2] = error[1];//error bij vorige vorige sample
	error[1] = error[0];//error bij vorige sample
	error[0] = gewenste_hoek - huidige_hoek; //Current error 



  // calculate delta_t
  if (!prev_time.isZero()) // Not first time through the program  
  {
    delta_t = ros::Time::now() - prev_time;
    prev_time = ros::Time::now();
    if (0 == delta_t.toSec())
    {
      ROS_ERROR("delta_t is 0, skipping this loop. Possible overloaded cpu at time: %f", ros::Time::now().toSec());
      return;
    }
  }
  else
  {
    ROS_INFO("prev_time is 0, doing nothing");
    prev_time = ros::Time::now();
    return;
  }

  // integrate the error
  error_integral += error[0] * delta_t.toSec();

  // Apply windup limit to limit the size of the integral term
  if ( error_integral > 1)
    error_integral = 1;

  if ( error_integral < -1)
    error_integral = -1;

  // Take derivative of error (derivative is bepalen snelheid van afnamen fout)
  // First the raw, unfiltered data:
  error_deriv[2] = error_deriv[1]; 
  error_deriv[1] = error_deriv[0]; 
  error_deriv[0] = (error[0]-error[1])/delta_t.toSec();//geeft de snelheid waarmee de fout afneemt 
  
  // calculate the control effort
  proportional = Kp * error[0]; 			//P
  integral = Ki * error_integral;			//i
  derivative = Kd * error_deriv[0];			//d
  control_effort = proportional + derivative;// + integral;	//de som van p+i+d is de regelwaarde

  // stel een limiet aan het maximale aanstuurkoppel
  if (control_effort > upper_limit)
  {
    control_effort = upper_limit;
  }
  else if (control_effort < lower_limit)
  {
    control_effort = lower_limit;
  }

//aanstuur koppel omzetten naar gewenste versnelling of vertraging 
//T = alpha * J
//alpha = T/J
alpha = control_effort / J;

//de snelheid aanpassen om gecontroleerd te draaien naar de gewenste draaihoek. 
draaisnelheid = draaisnelheid + alpha; 

//draaisnelheid limiteren


  if (draaisnelheid > maximum_draaisnelheid)
  {
    draaisnelheid = maximum_draaisnelheid;
  }
  else if (draaisnelheid < minimum_draaisnelheid)
  {
    draaisnelheid = minimum_draaisnelheid;
  }




//nieuwe gewenste draaisnelheid posten op "rosaria/cmd_vel" topic 


	/////////////////////////////////////
    	ros::spinOnce();
    	rate.sleep();//zorg dat dit 5 x per seconden wordt uitgevoerd. 
  	}

  return 0;
}

