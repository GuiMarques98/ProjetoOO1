#include "../inc/enemies.hpp"

//Metodos padroes da Classe Enemies

Enemies::Enemies()
{
  setPosX(0);
  setPosY(0);
  setBody('#');
  setDamage(0);
}

Enemies::Enemies(int x, int y, int damage)
{
  setPosX(x);
  setPosY(y);
  setBody('#');
  setDamage(damage);
}

Enemies::Enemies(int x, int y, char body, int damage)
{
  setPosX(x);
  setPosY(y);
  setBody(body);
  setDamage(damage);
}

Enemies::~Enemies(){}

int Enemies::getDamage()
{
  return damage;
}

void Enemies::setDamage(int damage)
{
  this->damage = damage;
}

char Enemies::getDirection()
{
  return direction;
}

void Enemies::setDirection(char direction)
{
  this->direction = direction
}
