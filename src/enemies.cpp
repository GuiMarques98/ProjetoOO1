#include "../inc/enemies.hpp"

//Metodos padroes da Classe Enemies

Enemies::Enemies()
{
  setPosX(0);
  setInitPosX(0);
  setPosY(0);
  setInitPosY(0);
  setBody('#');
  setRadius(0);
}

Enemies::Enemies(int x, int y, int radius)
{
  setPosX(x);
  setInitPosX(x);
  setPosY(y);
  setInitPosY(y);
  setBody('#');
  setRadius(radius);
}

Enemies::Enemies(int x, int y, char body, int radius)
{
  setPosX(x);
  setInitPosX(x);
  setPosY(y);
  setInitPosY(y);
  setBody(body);
  setRadius(radius);
}

Enemies::~Enemies(){}

int Enemies::getRadius()
{
  return radius;
}

void Enemies::setRadius(int Radius)
{
  this->radius = radius;
}

int Enemies::getInitPosX()
{
  return initPosX;
}

void Enemies::setInitPosX(int x)
{
  this->initPosX = x;
}

int Enemies::getInitPosY()
{
  return initPosY;
}

void Enemies::setInitPosY(int y)
{
  this->initPosY = y;
}

//Movimenta o inimigo pelo mapa
//Entrada: Objeto player
void Enemies::act(Player player, Colisor mapColisor)
{
  if((player.getPosX() >= initPosX-radius) and (player.getPosX() <= initPosX+radius) and (player.getPosY() >= initPosY-radius) and (player.getPosY() <= initPosY+radius))
  {
    if(!mapColisor.isColision(this, 'l') and getPosX()-player.getPosX()>0)
      setPosX(getPosX()-1);
    else
    {
      if(!mapColisor.isColision(this, 'r') and getPosX()-player.getPosX()<0)
        setPosX(getPosX()+1);
    }
    if(!mapColisor.isColision(this, 'd') and getPosY()-player.getPosY()>0)
      setPosY(getPosY()-1);
    else
    {
      if(!mapColisor.isColision(this, 'u') and getPosY()-player.getPosY()<0)
        setPosY(getPosY()+1);
    }
  }
  else
  {
    //Proximas 3 linhas geral um numero aleatorio que vai de 0 ate 4
    //0 para nao movimenta e o resto explicado no switch
    srand((unsigned)time(0));
    int direction_int;
    direction_int = rand()%5;
    if(!direction_int)
      return;
    else
    {
      switch (direction_int) {
        case 1: //move para cima up
          if(!mapColisor.isColision(this, 'u') and getPosY()+1 <= initPosY + radius)
            setPosY(getPosY()+1);
          break;
        case 2: // move para baixo down
          if(!mapColisor.isColision(this, 'd') and getPosY()-1 >= initPosY - radius)
            setPosY(getPosY()-1);
          break;
        case 3: //move para direita right
          if(!mapColisor.isColision(this, 'r') and getPosX()+1 >= initPosX + radius)
            setPosX(getPosX()+1);
          break;
        case 4://move para esquerda left
          if(!mapColisor.isColision(this, 'l') and getPosX()+1 >= initPosX - radius)
            setPosX(getPosX()-1);
      }
    }
  }
}
