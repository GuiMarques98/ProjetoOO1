#ifndef DRAW_HPP
#define DRAW_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <vector>
#include "player.hpp"
#include "enemies.hpp"
#include "bonus.hpp"
#include "map.hpp"

class Draw {
private:
  std::vector<std::string> picture;


public:
  //Metodos padroes da classe Draw
  Draw();
  Draw(Map gameMap);
  ~Draw();

  void setPicture(std::vector<std::string> picture);
  std::vector<std::string> getPicture();

  //Metodos para interagir com a tela
  void clean();
  void printScr();
  void printScr(char body, int posX, int posY);
  void printScr(Game_Object* gameObject);

};

#endif
