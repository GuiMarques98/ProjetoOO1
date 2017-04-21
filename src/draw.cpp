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
//Parametros: o caracter referente ao corpo, e as coordenadas na tela
void Draw::printScr(char body, int posX, int posY)
{
  move(posY, posX);
  printw("%c", body);
  refresh();
}

//Desenha todas as Traps na tela
//Parametro: Vector com todas as traps
void Draw::printTrap(std::vector<Trap> trap)
{
  for(size_t i=0;i<trap.size();++i)
  {
    move(trap[i].getPosY(), trap[i].getPosX());
    addch(trap[i].getBody());
    refresh();
  }
}


void Draw::printBonus(std::vector<Bonus> bonus)
{
  for(size_t i=0;i<bonus.size();++i)
  {
    move(bonus[i].getPosY(), bonus[i].getPosX());
    addch(bonus[i].getBody());
    refresh();
  }
}

//Desenha na tela
//Parametro: Um ponteiro para o objeto que sera desenhado
void Draw::printScr(Game_Object* gameObject)
{
  move(gameObject->getPosY(), gameObject->getPosX());
  addch(gameObject->getBody());
  refresh();
}
//Aplica delay a tela
void Draw::putDelay()
{
  unsigned int retTime = time(0) + delay/20;
  while (time(0) < retTime);
}

//Desenha o score
//Parametro: Score
void Draw::printScore(int score)
{
  move(21,1);
  printw("Score: %d", score);
  refresh();
}

//Menu para o labirinto
//Saida: Se vai ou nao iniciar o jogo
bool Draw::menu(size_t maxLine, size_t maxColum)
{
  char board =(char)219;
  for(size_t i=0; i<maxLine;++i)
  {
    move(i,0);
    addch(board);
    refresh();
    move(i, maxColum-1);
    addch(board);
    refresh();
  }
  for(size_t i=0;i<maxColum;++i)
  {
    move(0, i);
    addch(board);
    refresh();
    move(maxLine-1, i);
    addch(board);
    refresh();
  }

  move(1, (maxColum/2)-9);
  printw("Jogo do labirinto");
  refresh();
  move((maxLine/2)-1, (maxColum/2)-6);
  printw("Iniciar Jogo");
  move(maxLine/2, (maxColum/2)-2);
  printw("Sair");
  bool option = true, finish = true;

  while(finish)
  {
    switch (tolower(getch()))
    {
      case 'w':
        option = !option;
        break;
      case 's':
        option = !option;
        break;
      case 'd':
        finish = false;
        break;
      case '\n':
        finish = false;
    }
  }
  return option;
}
