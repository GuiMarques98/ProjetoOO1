#include "../inc/trap.hpp"
//Metodos padroes da Classe Enemies

Trap::Trap()
{
  setPosX(0);
  setPosY(0);
  setBody('#');
}

Trap::Trap(int x, int y, char body)
{
  setPosX(x);
  setPosY(y);
  setBody(body);
}

Trap::~Trap(){}

//Modifica as posicoes
//Parametro: Posicoes X e Y
void Trap::setXY(int x, int y)
{
  this->setPosX(x);
  this->setPosY(y);
}
