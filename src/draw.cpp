#include "../inc/draw.hpp"

//Funcoes padroes da classe Draw

Draw::Draw(){}

Draw::Draw(Map gameMap, int delay)
{
  try
  {
    picture = gameMap.getAllMap();
  }catch (char const* msg)
  {
    std::cout << msg << '\n';
  }
  this->delay = delay;
}

Draw::~Draw(){}

void Draw::setPicture(std::vector<std::string> picture)
{
  this->picture = picture;
}

std::vector<std::string> Draw::getPicture()
{
  return picture;
}

void Draw::setDelay(int delay)
{
  this->delay = delay;
}

int Draw::getDelay()
{
  return delay;
}

//Limpa o vetor da pintura
void Draw::clean()
{
  picture.clear();
}

//Desenha na tela o que esta no vector picture
void Draw::printScr()
{
  for(size_t i=0;i<picture.size();++i)
  {
    printw("%s", picture[i].c_str());
    refresh();
  }
}

//Desenha na tela
//Entrada: o caracter referente ao corpo, e as coordenadas na tela
void Draw::printScr(char body, int posX, int posY)
{
  move(posY, posX);
  printw("%c", body);
  refresh();
}

//Desenha na tela
//Entrada: Um ponteiro para o objeto que sera desenhado
void Draw::printScr(Game_Object* gameObject)
{
  move(gameObject->getPosY(), gameObject->getPosX());
  addch(gameObject->getBody());
  refresh();
}

//Aplica delay a tela
void Draw::putDelay()
{

}
