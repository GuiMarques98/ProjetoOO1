#include "../inc/player.hpp"

//Metodos padroes da Classe Player

Player::Player()
{
  setPosX(0);
  setPosY(0);
  setBody('@');
  setAlive(true);
  setDirection(0);
}

Player::Player(int x, int y)
{
  setPosX(x);
  setPosY(y);
  setBody('@');
  setAlive(true);
  setDirection(0);

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

char Player::getDirection()
{
  return direction;
}

void Player::setDirection(char direction)
{
  this->direction = direction;
}
