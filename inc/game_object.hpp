#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <string>
using namespace std;

class Game_Object
{
private:
  int posX, posY; //Coordenadas
  char body; //Corpo do objeto

public:
  //Métodos padroes da classe abstrata
  Game_Object();
  virtual ~Game_Object();

  int getPosX();
  void setPosX(int x);

  int getPosY();
  void setPosY(int y);

  char getBody();
  void setBody(char body);

};


#endif
