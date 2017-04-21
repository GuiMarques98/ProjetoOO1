#ifndef BONUS_HPP
#define BONUS_HPP

#include "game_object.hpp"

class Bonus : public Game_Object
{
private:
  int score;

public:
  //Metodos padroes da classe Bonus
  Bonus();
  Bonus(int x, int y, int score);
  Bonus(int x, int y, int score, char body);
  ~Bonus();

  int getScore();
  void setScore(int score);
  void setXY(int x, int y);
};

#endif
