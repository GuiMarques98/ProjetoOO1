#include "../inc/map.hpp"

Map::Map()
{
  path = "./doc/map.txt";
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
