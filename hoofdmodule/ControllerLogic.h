#include <stdlib.h> 
#include <vector>
class ControllerLogic
{
public:
	ControllerLogic();
	~ControllerLogic();
	void stopRoute();
	void resumeRoute();
	void sendMovements();

private:
	std::vector<bool> pressedButtons;
};
