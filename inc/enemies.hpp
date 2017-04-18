#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include "game_object.hpp"

class Enemies : public Game_Object
{
private:
  int damage;
  char direction;


public:
  //Metodos padroes da Classe Enemies
  Enemies();
  Enemies(int x, int y, int damage);
  Enemies(int x, int y, char body, int damage);
  ~Enemies();

  int getDamage();
  void setDamage(int damage);

  char getDirection();
  void setDirection(char direction);
};

#endif
