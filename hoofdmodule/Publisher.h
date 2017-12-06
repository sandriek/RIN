#pragma once
#ifndef HEADERFILE_Publisher
#define HEADERFILE_Publisher
//#include "Manager.h"
#include <iostream>
class Manager;
class Publisher
{
public:
	Publisher(Manager *manager);
	~Publisher();
	void publishMovements();
	void publishWeb();
private:

};
#endif