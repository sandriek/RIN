#include "MapObject.h"

MapObject::MapObject(std::vector<std::vector<int>> clusteredMap, std::vector<std::vector<int>> pixelMap)
{
	ClusteredMap = clusteredMap;
	PixelMap = pixelMap;
}

MapObject::~MapObject()
{

}

std::vector<std::vector<int>> MapObject::getClusteredMap()
{
	std::vector<std::vector<int>> null;
	return null;
}

std::vector<std::vector<int>> MapObject::getPixelMap()
{
	std::vector<std::vector<int>> null;
	return null;
}