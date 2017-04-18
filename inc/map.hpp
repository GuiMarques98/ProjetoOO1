#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Map {
private:
  std::string path;

public:
  //Metodos padroes da classe Map
  Map ();
  Map(std::string path);
  ~Map ();

  void setPath(std::string path);
  std::string getPath();

  //Retorna um vector de strings que contem o mapa do jogo
  std::vector<std::string> getAllMap();
};
#endif
