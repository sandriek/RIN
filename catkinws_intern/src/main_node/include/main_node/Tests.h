#ifndef HEADERFILE_Tests
#define HEADERFILE_Tests
#include <stdlib.h> 
#include <vector>
#include <iostream>

class Manager;
class Tests
{
public:
	Tests(Manager* manager);
	~Tests();
	void TestFirstWayPoint();
private:
	
	Manager* manager;
};

#endif