#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <ctime>
#include <cstdlib>
#include "colisor.hpp"
#include "player.hpp"

#include "game_object.hpp"

class Trap : public Game_Object
{
private:
  int radius;
  int initPosX, initPosY;

public:
  //Metodos padroes da Classe Enemies
  Trap();
  Trap(int x, int y, int radius);
  Trap(int x, int y, char body, int radius);
  ~Trap();

  int getRadius();
  void setRadius(int Radius);
  int getInitPosX();
  void setInitPosX(int x);
  int getInitPosY();
  void setInitPosY(int y);




};

#endif
