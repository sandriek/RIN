#pragma once
#include <stdlib.h> 
#include <vector>
class NavigationObject
{
public:
	NavigationObject();
	~NavigationObject();
	std::vector<double> getPosition();
	double getRotation();

private:
		double XPosition;
		double YPosition;
		double ZPosition;
		double Rotation;
};
