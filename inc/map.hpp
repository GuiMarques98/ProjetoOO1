#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <fstream>
#include <string>

class Map {
private:
  std::ifstream mapTxt;
  std::string path;
public:
  //Metodos padroes da classe Map
  Map ();
  Map(std::string caminho);
  ~Map ();
  void setPath(std::string path);
  std::string getPath();
};
#endif
