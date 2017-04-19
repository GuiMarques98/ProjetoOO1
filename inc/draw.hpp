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
  int delay; //delay de atualização da tela

public:
  //Metodos padroes da classe Draw
  Draw();
  Draw(Map gameMap, int delay);
  ~Draw();

  void setPicture(std::vector<std::string> picture);
  std::vector<std::string> getPicture();
  void setDelay(int delay);
  int getDelay();

  //Metodos para interagir com a tela
  void clean();
  void printScr();
  void printScr(char body, int posX, int posY);
  void printScr(Game_Object* gameObject);
  void putDelay();

};

#endif
