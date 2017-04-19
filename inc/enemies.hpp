#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <ctime>
#include <cstdlib>
#include "colisor.hpp"
#include "player.hpp"

#include "game_object.hpp"

class Enemies : public Game_Object
{
private:
  int radius;
  int initPosX, initPosY;

public:
  //Metodos padroes da Classe Enemies
  Enemies();
  Enemies(int x, int y, int radius);
  Enemies(int x, int y, char body, int radius);
  ~Enemies();

  int getRadius();
  void setRadius(int Radius);
  int getInitPosX();
  void setInitPosX(int x);
  int getInitPosY();
  void setInitPosY(int y);


  void act(Player player, Colisor mapColisor);

};

#endif
