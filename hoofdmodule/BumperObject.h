#pragma once
#include <stdlib.h> 
#include <vector>
class BumperObject
{
public:
	BumperObject();
	~BumperObject();
	std::vector<int> getBumpers();
private:
	bool Bumper1;
	bool Bumper2;
	bool Bumper3;
	bool Bumper4;
	bool Bumper5;
	bool Bumper6;
};