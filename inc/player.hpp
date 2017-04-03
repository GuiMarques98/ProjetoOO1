#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "game_object.hpp"

class Player : public Game_Object
{
private:
  bool alive;
  bool winner;
  int score;

public:
  //Metodos padroes da Classe player
  Player();
  Player(int x, int y);
  ~Player();

  bool getAlive();
  void setAlive(bool alive);

  bool getWinner();
  void setWinner(bool winner);

  int getScore();
  void setScore(int score);

}

#endif
