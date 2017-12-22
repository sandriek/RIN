#pragma once
#include <stdlib.h> 
#include <vector>
class SonarObject
{
public:
	SonarObject();
	~SonarObject();
	std::vector<int> getSonars();

private:
	int Sonar1;
	int Sonar2;
	int Sonar3;
	int Sonar4;
	int Sonar5;
	int Sonar6;
	int Sonar7;
};