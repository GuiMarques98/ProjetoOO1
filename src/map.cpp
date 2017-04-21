#include "../inc/map.hpp"

Map::Map()
{
  path = "./doc/map.txt";
  maxLine = 0;
  maxColum = 0;
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

//Função que plota o mapa
//Retorno: Matriz do mapa
std::vector<std::string> Map::getAllMap()
{
  std::ifstream mapFile(path);
  std::string line;
  std::vector<std::string> mapLine;

  if(mapFile.is_open())  //Verifica se o arquivo foi aberto
  {
    while(!mapFile.eof())
    {
      std::getline(mapFile, line);
      line += '\n';
      mapLine.push_back(line);
    }
  }
  else//Caso o arquivo nao tenha sido aberto encerra o programa com mensagem de erro
  {
    throw "File can not be open!";
  }
  mapFile.close();
  return mapLine;
}

size_t Map::getMaxLine()
{
    std::ifstream mapFile(path);
    std::string line;
    std::vector<std::string> mapLine;
  if(mapFile.is_open())
  {
    while(!mapFile.eof())
    {
      std::getline(mapFile, line);
      line += '\n';
      mapLine.push_back(line);
    }
  }
  else//Caso o arquivo nao tenha sido aberto encerra o programa com mensagem de erro
  {
    throw "File can not be open!";
  }
  mapFile.close();
  return mapLine.size();

}

size_t Map::getMaxColum()
{

  std::ifstream mapFile(path);
  std::string line;
  std::vector<std::string> mapLine;
  if(mapFile.is_open())  //Verifica se o arquivo foi aberto
  {
    while(!mapFile.eof())
    {
      std::getline(mapFile, line);
      line += '\n';
      mapLine.push_back(line);
    }
  }
  else//Caso o arquivo nao tenha sido aberto encerra o programa com mensagem de erro
  {
    throw "File can not be open!";
  }
  mapFile.close();
  return mapLine[0].size();
}
