#include "../inc/bonus.hpp"

//Metodos padroes da Classe Bonus

Bonus::Bonus()
{
  setPosX(0);
  setPosY(0);
  setBody('$');
  setScore(0);
}

Bonus::Bonus(int x, int y, int score)
{
  setPosX(x);
  setPosY(y);
  setBody('$');
  setScore(score);
}

Bonus::Bonus(int x, int y, int score, char body)
{
  setPosX(x);
  setPosY(y);
  setBody(body);
  setScore(score);
}

int Bonus::getScore()
{
  return score;
}

void Bonus::setScore(int score)
{
  this->score = score;
}
