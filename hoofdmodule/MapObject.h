#pragma once
#include <stdlib.h> 
#include <vector>
class MapObject
{
public:
	MapObject();
	~MapObject();
	std::vector<std::vector<int>> getClusteredMap();
	std::vector<std::vector<int>> getPixelMap();
private:
	std::vector<std::vector<int>> ClusteredMap;
	std::vector<std::vector<int>> PixelMap;
};
