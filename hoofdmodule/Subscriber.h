#include "SonarObject.h"
#include "BumperObject.h"
#include "NavigationObject.h"
#include "MapObject.h"
#include "RosariaObject.h"
#include "ControllerObject.h"
#include <iostream>
class Manager;

class Subscriber
{
public:
	Subscriber(Manager* manager);
	~Subscriber();

private:
	/*hier moeten nog alle callback functies*/
};
