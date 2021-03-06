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

//Aplica delay a tela
void Draw::putDelay(int seg)
{
  unsigned int retTime = time(0) + seg;
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
//Parametro: Maximo de linhas e colunas da tela
//Retorno: Se vai ou nao iniciar o jogo
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
  move(3, (maxColum/2)-5);
  printw("@: Player");
  move(4, (maxColum/2)-6);
  printw("#: Armadilha");
  move(5, (maxColum/2)-4);
  printw("$: Bonus");
  move(6, (maxColum/2)-5);
  printw("=: Parede");
  move(7, (maxColum/2)- 16);
  printw("Movimentacao com as teclas WASD");
  move(9, (maxColum/2)- 18);
  printw("Chegue ao '&' para terminar o jogo!");
  refresh();

  bool option= true, finish=true, blink = true;
  while(finish)
  {
      if(option)
      {
        if(blink)
        {
          attron(A_REVERSE);
          move((maxLine/2)-1, (maxColum/2)-6);
          printw("Iniciar Jogo");
          attroff(A_REVERSE);
          move(maxLine/2, (maxColum/2)-2);
          printw("Sair");
        }
        else{
          move((maxLine/2)-1, (maxColum/2)-6);
          printw("Iniciar Jogo");
          move(maxLine/2, (maxColum/2)-2);
          printw("Sair");
        }
      }
      else{
        if(blink)
        {
          move((maxLine/2)-1, (maxColum/2)-6);
          printw("Iniciar Jogo");
          move(maxLine/2, (maxColum/2)-2);
          attron(A_REVERSE);
          printw("Sair");
          attroff(A_REVERSE);
        }
        else{
          move((maxLine/2)-1, (maxColum/2)-6);
          printw("Iniciar Jogo");
          move(maxLine/2, (maxColum/2)-2);
          printw("Sair");
        }
      }
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
    putDelay();
  }
  return option;
}

//Desenha a tela de final de jogo
//Parametro: maximo de linhas e maximo de colunas da janela
void Draw::end(int maxLine, int maxColum, int score)
{
  char board =(char)219;
  WINDOW* endWin;
  endWin = newwin(maxLine, maxColum+2, 0,0);
  wrefresh(endWin);
  for(int i=0; i<maxLine;++i)
  {
    move(i,0);
    addch(board);
    refresh();
    move(i, maxColum-1);
    addch(board);
    refresh();
  }
  for(int i=0;i<maxColum;++i)
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
  move(maxLine/2, (maxColum/2)-5),
  printw("Score: %d", score);
  refresh();
  move(maxLine-2, (maxColum/2)-6);
  printw("FIM DE JOGO!");
  refresh();
  nodelay(endWin, false);
  getch();
  delwin(endWin);

}
