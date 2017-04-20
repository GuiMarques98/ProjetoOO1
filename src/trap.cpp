#include "../inc/trap.hpp"
//Metodos padroes da Classe Enemies

Trap::Trap()
{
  setPosX(0);
  setInitPosX(0);
  setPosY(0);
  setInitPosY(0);
  setBody('#');
  setRadius(0);
}

Trap::Trap(int x, int y, int radius)
{
  setPosX(x);
  setInitPosX(x);
  setPosY(y);
  setInitPosY(y);
  setBody('#');
  setRadius(radius);
}

Trap::Trap(int x, int y, char body, int radius)
{
  setPosX(x);
  setInitPosX(x);
  setPosY(y);
  setInitPosY(y);
  setBody(body);
  setRadius(radius);
}

Trap::~Trap(){}

int Trap::getRadius()
{
  return radius;
}

void Trap::setRadius(int Radius)
{
  this->radius = radius;
}

int Trap::getInitPosX()
{
  return initPosX;
}

void Trap::setInitPosX(int x)
{
  this->initPosX = x;
}

int Trap::getInitPosY()
{
  return initPosY;
}

void Trap::setInitPosY(int y)
{
  this->initPosY = y;
}
