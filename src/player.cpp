#include "../inc/player.hpp"

//Metodos padroes da Classe Player

Player::Player()
{
  setPosX(0);
  setPosY(0);
  setBody('@');
  setAlive(true);
  setWinner(false);
  setScore(0);
}

Player::Player(int x, int y)
{
  setPosX(x);
  setPosY(y);
  setBody('@');
  setAlive(true);
  setWinner(false);
  setScore(0);
}

Player::~Player(){}

bool Player::getAlive()
{
  return alive;
}

void Player::setAlive(bool alive)
{
  this->alive = alive;
}

bool Player::getWinner()
{
  return winner;
}

void Player::setWinner(bool winner)
{
  this->winner = winner;
}

int Player::getScore()
{
  return score;
}

void Player::setScore(int score)
{
  this->score = score;
}
