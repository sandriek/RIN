#ifndef HEADERFILE_ControllerLogic
#define HEADERFILE_ControllerLogic
#include <stdlib.h> 
#include <vector>
#include <iostream>

class Manager;
class ControllerLogic
{
public:
	ControllerLogic(Manager* manager);
	~ControllerLogic();
	void stopRoute();
	void resumeRoute();
	void sendMovements();

private:
	std::vector<bool> pressedButtons;
};
#endif