#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <string>
using namespace sdt;

class Game_Object
{
private:
  int posX;
  int posY;
  char body;

public:
  //Métodos padroes da classe abstrata
  Game_Object();
  virtual ~Game_Object() = 0;

  int getPosX();
  void setPosX(int x);

  int getPosY();
  void setPosY(int y);

  char getBody();
  void setBody(char body);

}


#endif
