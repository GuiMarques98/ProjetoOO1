#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ncurses.h>

#include "game_object.hpp"
#include "colisor.hpp"

class Player : public Game_Object
{
private:
  bool alive;
  int score;
  char direction;

  void updateDirection();

public:
  //Metodos padroes da Classe player
  Player();
  Player(int x, int y);
  ~Player();

  bool getAlive();
  void setAlive(bool alive);
  char getDirection();
  void setDirection(char direction);
  int getScore();
  void setScore(int score);

  void act(Colisor mapColisor);

};

#endif
