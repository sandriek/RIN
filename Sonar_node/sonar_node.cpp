// SRF02 example coder for the Raspberry pi
//
// This code will work for the SRF02/ 10/ 235 and 08.
// It will take a ranging from the module and print results
// to the screen.
//
// By James Henderson, 2016.
#include "ros/ros.h"
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "std_msgs/String.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

std::stringstream S;
std_msgs::String msgs;

int main(int argc, char **argv)
{
	ros::init(argc, argv,"sonar_node");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<std_msgs::String>("Sonarsignals",500);

	printf("**** SRF02/10/235 example program ****\n");
	
	int fd;														// File descrition
	// For older raspberry pi modules use "/dev/i2c-0" instead of "/dev/i2c-1" for the i2c port
	char *fileName = "/dev/i2c-1";								// Name of the port we will be using
	int  address = 0x71;										// Address of the SRF02 shifted right one bit
	unsigned char buf[10];										// Buffer for data being read/ written on the i2c bus
	
	while(true){
		for(size_t i = 0; i < 7; i++)
		{
			address = 0x70 + i;
			if ((fd = open(fileName, O_RDWR)) < 0) {					// Open port for reading and writing
				printf("Failed to open i2c port\n");
				exit(1);
			}
	
			if (ioctl(fd, I2C_SLAVE, address) < 0) {					// Set the port options and set the address of the device we wish to speak to
				printf("Unable to get bus access to talk to slave\n");
				exit(1);
			}
			buf[0] = 0;													// Commands for performing a ranging
			buf[1] = 81;	
			if ((write(fd, buf, 2)) != 2) {								// Write commands to the i2c port
				printf("Error writing to i2c slave\n");
				exit(1);
			}
	
			usleep(90000);												// This sleep waits for the ping to come back
	
			buf[0] = 0;													// This is the register we wish to read from
	
			if ((write(fd, buf, 1)) != 1) {								// Send the register to read from
				printf("Error writing to i2c slave\n");
				exit(1);
			}
			if (read(fd, buf, 4) != 4) {								// Read back data into buf[]
				printf("Unable to read from slave\n");
				exit(1);
			}
			else {
				unsigned char highByte = buf[2];
				unsigned char lowByte = buf[3];
				unsigned int result = highByte;				// Calculate range as a word value
				result <<= 8;
				result += lowByte;
				//printf("Software v: %d\n",buf[0]);
				printf("Sensor 7%u",i);	//adress
				printf(" = %u\n",result);
				S.str(std::string());//maak stringstream leeg
				S << "Sensor 7" << i << " = " << result; //afstand
				msgs.data = S.str();
				pub.publish(msgs);
				
			}
		}//for
	}//while
	
	close(fd);	
	
	return 0;
}

