#include "../inc/game_object.hpp"

//Metodos padroes Classe abstrata Game_Object
Game_Object::Game_Object()
{
  setPosX(0);
  setPosY(0);
  setBody(0);
}

Game_Object::~Game_Object(){}

int Game_Object::getPosX()
{
  return posX;
}

void Game_Object::setPosX(int x)
{
   posX= x;
}

int Game_Object::getPosY()
{
  return posY;
}

void Game_Object::setPosY(int y)
{
  posY = y;
}

char Game_Object::getBody()
{
  return body;
}

void Game_Object::setBody(char body)
{
  this->body = body;
}
