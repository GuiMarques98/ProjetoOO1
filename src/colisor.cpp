#include "../inc/colisor.hpp"

//Metodos padroes da classe Colisor
Colisor::Colisor(){}

Colisor::Colisor(std::vector<std::string> map)
{
  this->map = map;
}

Colisor::~Colisor(){}

void Colisor::setMap(std::vector<std::string> map)
{
  this->map = map;
}

//Verifica se ha colisão
//Parametro: Coordenadas do objeto, direcao de movimento
//Retorno: ha ou nao colisao
bool Colisor::isColision(int x, int y, char direction)
{
  switch (direction) {
    case 'u':
      if(y-1 <= 0)
        return 0;
      else
        if(map[y-1][x] != ' ')
          return true;
    case 'd':
      if(map[y+1][x] != ' ')
        return true;
    case 'l':
      if(map[y][x-1] != ' ')
        return true;
    case 'r':
      if(map[y][x+1] !=' ')
        return true;
    default:
      return false;
  }
}

//Verifica se ha colisoes
//Parametro: Ponteiro que aponta para a classe Game_Object
//Retorno: ha ou nao colisao
bool Colisor::isColision(Game_Object* gameObject, char direction)
{
  switch (direction)
  {
    case 'u': //up pra cima
      if(gameObject->getPosY()-1 <= 0)
        return true;
      else
        if(map[gameObject->getPosY()-1][gameObject->getPosX()] != ' ')
          return true;
        break;
    case 'd'://down pra baixo
      if(map[gameObject->getPosY()+1][gameObject->getPosX()] != ' ')
        return true;
      break;
    case 'l'://left esquerda
      if(map[gameObject->getPosY()][gameObject->getPosX()-1] != ' ')
        return true;
      break;
    case 'r'://right direita
      if(map[gameObject->getPosY()][gameObject->getPosX()+1] !=' ')
        return true;
      break;
    default:
      return false;
  }
  return false;
}

//Verifica a colisao player e inimigo
//Parametro: Dois ponteiros da classe Game_Object
//Retorno: Se ha ou nao colisao
bool isPColision(Game_Object* player, Game_Object* enemie)
{
  if(player->getPosY() == enemie->getPosY() and player->getPosX() == enemie->getPosX())
    return true;
  return false;
}
