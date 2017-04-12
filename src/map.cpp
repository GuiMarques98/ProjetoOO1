#include "../inc/map.hpp"

Map::Map()
{
  path = "../doc/map.txt";
}

Map::Map(std::string path)
{
  this->path = path;
}

Map::~Map(){}

void Map::setPath(std::string path)
{
  this->path = path;
}

std::string Map::getPath()
{
  return path;
}
