#include "ros/ros.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include <array>
#include <vector>
#include <fstream>

using namespace std;

int height = 300, width = 300;			// < Variabelen voor de breedte en hoogte van de bitmap. Deze staan vast omdat testomgeving 3mx3m is.
vector<int> pixelVector;			//Vector met daarin alle pixels van de bitmap, in deze vector staan waardes 0 of 1 (niet gevuld/gevuld).
vector<int> clusterVector;			//Vector met daarin de clusters van pixels, in deze vector staan waardes 0 of 1 (niet gevuld/gevuld.
std_msgs::Int32MultiArray pixelArrayToSend;	//Array met pixels die gepublished kan worden, deze komt van 'pixelVector'.
std_msgs::Int32MultiArray clusterArrayToSend;	//Array met clusters die gepublished kan worden, deze komt van 'clusterVector'.
unsigned char info[54];				//Info van de bitmap file opslaan
unsigned char* bmpdata;				//Data die in de bitmap staat opslaan
int size;					//Grootte van de bitmap file opslaan.
FILE* bmpFile;					//Verwijzing naar het bitmap bestand dat gebruikt gaat worden.

void readFile() {
	bmpFile = fopen("/home/chris/Desktop/vierkantRandom.bmp", "rb"); // < PAD NAAR BITMAP!

	fread(info, sizeof(unsigned char), 54, bmpFile);		//Info van de bitmap file ophalen, zoals hoogte en breedte.

	size = ((width * 3 + 3) & (~3)) * height; 			//BMP - HEIGHT: *(int*)&info[22]  -  WIDTH:*(int*)&info[18]
	bmpdata = new unsigned char[size];

	fread(bmpdata, sizeof(unsigned char), size, bmpFile);		//Data van de bitmap uitlezen.
	fclose(bmpFile);						//Bitmap file sluiten, klaar met gebruik.
}

void buildPixelMap() {
	int i = 0;
	vector<int> pixelvectorTemp((height * width), 0);
	pixelArrayToSend.data.clear();
	
	pixelArrayToSend.layout.dim.push_back(std_msgs::MultiArrayDimension());
	pixelArrayToSend.layout.dim.push_back(std_msgs::MultiArrayDimension());
	
	for (int a = (height -1); a > -1; a--) {
		for (int q = 0; q < width; q++) {
			if ((int(bmpdata[i] & 0xFF) + int(bmpdata[i + 1] & 0xFF) + int(bmpdata[i + 2] & 0xFF)) > 0) {
				pixelvectorTemp[a*width+q] = 0;
			}
			else {
				pixelvectorTemp[a*width+q] = 1;
				}
			i = i + 3;
		}
	}
	pixelArrayToSend.data = pixelvectorTemp;	//doorschrijven van de vector naar de array die gepublished wordt.
	pixelVector = pixelvectorTemp;			//doorschrijven van de temp vector naar de globale vector (pixelMap).
}

void buildClusterMap() {
	int pixelSum = 0;			//Variabele voor het bijhouden van de som van de 1'en in een cluster.
	vector<int> clustervectorTemp(36, 0);	//Tijdelijke vector aanmaken om de waarden in op te slaan.
	for (int z = 0; z <6; z++) {
		for (int q = 0; q < 6; q++) { 
			for (int i = 0; i < 50; i++) {
				for (int j = 0; j < 50; j++) {
					pixelSum += pixelVector[(i*width)+ ((z*50)*width) + (j+(q*50))];} //Optellen van het aantal 1'en die in het cluster zitten.
				}
			if (pixelSum > 625) { //Wanneer er meer dan 1/4 van de pixels een 1 zijn dan is het vak gevuld.
				clustervectorTemp[(z) * 6 + q] = 1;
			}
			else {
				clustervectorTemp[(z) * 6 + q] = 0;
			}
			pixelSum = 0;
		}
	}
	clusterArrayToSend.data = clustervectorTemp;	//doorschrijven van de vector naar de array die gepublished wordt.
	clusterVector = clustervectorTemp;		//doorschrijven van de temp vector naar de globale vector (clusterMap).
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "publiserMap");							//Publisher initialiseren
	ros::NodeHandle n;									
	ros::Publisher pubPixel = n.advertise<std_msgs::Int32MultiArray>("pixelMap", 100);	//Aanmaken van topic voor de pixelmap.
	ros::Publisher pubCluster = n.advertise<std_msgs::Int32MultiArray>("clusterMap", 100);	//Aanmaken van topic voor de clustermap.

	readFile(); // < Aanroepen van functie die de bitmap file gaat uitlezen en de data naar deze Node haalt.

	while (ros::ok()) {
		ROS_INFO("Building Pixel Map...");
		buildPixelMap(); // < Aanroepen van functie die de bitmap data uitleest en vervolgens deze data naar een 2D array/vector schrijft.

		ROS_INFO("Building Cluster Map...");
		buildClusterMap();			// < Aanroepen van funtie die de pixelmap omzet naar de clustermap.

		ROS_INFO("Publishing Maps!");
		pubPixel.publish(pixelArrayToSend);	//Pixel map publishen
		pubCluster.publish(clusterArrayToSend);	//Cluster map publishen

		ROS_INFO(" - BOTH MAPS PUBLISHED");
		ROS_INFO("");				//Lege regel invoegen.

		ros::Duration(10.0).sleep(); // < Sleep aanroepen om extreme spam te voorkomen...
		//!!!SLEEP later wijzigen voor het uitvoeren op basis van een aanvraag van het externe systeem???
		ros::spinOnce();
	}
	return 0;
}
