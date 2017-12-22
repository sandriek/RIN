#pragma once
#include <stdlib.h> 
#include <vector>
class ControllerObject
{
public:
	ControllerObject();
	~ControllerObject();
	std::vector<float> getAxes();
	std::vector<int> getButtons();
private:
	std::vector<float> axes;
	std::vector<int> buttons;
};
