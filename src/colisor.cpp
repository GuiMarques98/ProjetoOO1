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
bool Colisor::isColision(int x  , int y, char direction)
{
  switch (direction)
  {
    case 'u':
      if(y-1 <= 0)
        return true;
      else
        if(map[y-1][x] != ' ')
          return true;
      break;
    case 'd':
      if(y-1 >= map.size()-1)
        return true;
      else
        if(map[y+1][x] != ' ')
          return true;
      break;
    case 'l':
      if(x-1<=0)
        return true;
      else
        if(map[y][x-1] != ' ')
          return true;
      break;
    case 'r':
      if(x+1 >= map[y].size()-1)
        return true;
      else
        if(map[y][x+1] != ' ')
          return true;
      break;
    default:
      return false;
  }
  return false;
}

//Verifica se ha colisoes
//Parametro: Ponteiro que aponta para a classe Game_Object
//Retorno: ha ou nao colisao
bool Colisor::isColision(Game_Object* gameObject, char direction)
{
  return isColision(gameObject->getPosX(), gameObject->getPosY(), direction);
}

//Verifica a colisao player e inimigo
//Parametro: Dois ponteiros da classe Game_Object
//Retorno: Se ha ou nao colisao
bool Colisor::isPColision(Game_Object* player, Game_Object* objectGame)
{
  if(player->getPosY() == objectGame->getPosY() and player->getPosX() == objectGame->getPosX())
    return true;
  return false;
}
