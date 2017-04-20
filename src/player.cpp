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
  switch (direction)
  {
    case 'w':
      this->direction = 'u';
      return;
    case 's':
      this->direction = 'd';
      return;
    case 'a':
      this->direction = 'l';
      return;
    case 'd':
      this->direction = 'r';
      return;
    default:
      this->direction = 0;
  }

}

//Atualiza as cordenadas de acordo com a direcao
void Player::updateDirection()
{
  move(getPosY(), getPosX());
  addch(' ');
  refresh();
  switch (getDirection()) {
    case 'u': //move para cima up
      setPosY(getPosY()-1);
      break;
    case 'd': // move para baixo down
      setPosY(getPosY()+1);
      break;
    case 'r': //move para direita right
      setPosX(getPosX()+1);
      break;
    case 'l'://move para esquerda
      setPosX(getPosX()-1);
  }
  setDirection(0);
}

//Move o player
//Entrada: Classe colisor
void Player::act(Colisor mapColisor)
{
  char a = getch();
  setDirection(a);
  if(mapColisor.isColision(this, getDirection()))//Verifica se colidiu com o mapa
    setDirection(0);
  updateDirection();
}
