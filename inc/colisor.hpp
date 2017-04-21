#ifndef COLISOR_HPP
#define COLISOR_HPP

#include <vector>
#include "game_object.hpp"

class Colisor {
private:
  std::vector<std::string> map;

public:
  //Metodos padroes da classe Colisor
  Colisor();
  Colisor(std::vector<std::string> map);
  ~Colisor();

  void setMap(std::vector<std::string> map);

  bool isColision(int x, int y, char direction);
  bool isColision(Game_Object* gameObject, char direction);
  bool isPColision(Game_Object* player, Game_Object* objectGame);

};
#endif
