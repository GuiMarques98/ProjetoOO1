#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "game_object.hpp"

class Player : public Game_Object
{
private:
  bool alive;
  char direction;

public:
  //Metodos padroes da Classe player
  Player();
  Player(int x, int y);
  ~Player();

  bool getAlive();
  void setAlive(bool alive);

  char getDirection();
  void setDirection(char direction);

};

#endif
