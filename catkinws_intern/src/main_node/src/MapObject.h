#pragma once
#include <stdlib.h> 
#include <vector>
class MapObject
{
public:
	MapObject(std::vector<std::vector<int>> clusteredMap, std::vector<std::vector<int>> pixelMap);
	~MapObject();
	std::vector<std::vector<int>> getClusteredMap();
	std::vector<std::vector<int>> getPixelMap();
private:
	std::vector<std::vector<int>> ClusteredMap;
	std::vector<std::vector<int>> PixelMap;
};
