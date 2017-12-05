#include <stdlib.h> 
#include <vector>
class SensorLogic
{
public:
	SensorLogic();
	~SensorLogic();
	void updateMap();
private:
	std::vector<int> Sonars;
	std::vector<bool> Bumpers;
	std::vector<double> GPS;
};
