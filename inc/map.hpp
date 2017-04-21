#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ncurses.h>


class Map {
private:
  std::string path;
  size_t maxLine, maxColum;

public:
  //Metodos padroes da classe Map
  Map ();
  Map(std::string path);
  ~Map ();

  void setPath(std::string path);
  std::string getPath();
  size_t getMaxLine();
  size_t getMaxColum();

  //Retorna um vector de strings que contem o mapa do jogo
  std::vector<std::string> getAllMap();

};
#endif
