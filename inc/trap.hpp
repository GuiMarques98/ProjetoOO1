#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <ctime>
#include <cstdlib>
#include "colisor.hpp"
#include "player.hpp"

#include "game_object.hpp"

class Trap : public Game_Object
{
public:
  //Metodos padroes da Classe Enemies
  Trap();
  Trap(int x, int y, char body);
  ~Trap();

  void setXY(int x, int y);

};

#endif
