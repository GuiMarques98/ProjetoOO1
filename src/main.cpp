#include "../inc/game_object.hpp"
#include "../inc/trap.hpp"
#include "../inc/player.hpp"
#include "../inc/bonus.hpp"
#include "../inc/map.hpp"
#include "../inc/colisor.hpp"
#include "../inc/draw.hpp"

#include <ncurses.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


int main()
{
	Map map("./doc/map.txt");
	Draw draw(map, 1);
	Player player(1,1);
	Colisor colisor(map.getAllMap());
	std::vector<Bonus> bonus;
	Bonus tBonus(16, 1, 10);//Objeto temporario para preencher
	//Iniciando os bonus
	bonus.push_back(tBonus);
	tBonus.setXY( 8, 5);
	bonus.push_back(tBonus);
	tBonus.setXY(3,5);
	bonus.push_back(tBonus);
	tBonus.setXY(1,18);
	bonus.push_back(tBonus);
	tBonus.setXY(64,1);
	bonus.push_back(tBonus);
	tBonus.setXY(64,4);
	bonus.push_back(tBonus);
	tBonus.setXY(28,18);
	bonus.push_back(tBonus);
	tBonus.setXY(29,18);
	bonus.push_back(tBonus);
	tBonus.setXY(30,18);
	bonus.push_back(tBonus);
	tBonus.setXY(31,18);
	bonus.push_back(tBonus);
	tBonus.setXY(32,18);
	bonus.push_back(tBonus);
	tBonus.setXY(33	,18);
	bonus.push_back(tBonus);
	tBonus.setXY(34,18);
	bonus.push_back(tBonus);
	tBonus.setXY(35,18);
	bonus.push_back(tBonus);
	tBonus.~Bonus(); //Destruindo o Objeto

	Trap tTrap(2, 1, '#');//Objeto temporario para preencher o vetor
	std::vector<Trap> trap;
	//Iniciando as traps
	trap.push_back(tTrap);
	tTrap.setXY(21,18);
	trap.push_back(tTrap);
	tTrap.setXY(2,12);
	trap.push_back(tTrap);
	tTrap.setXY(17,10);
	trap.push_back(tTrap);
	tTrap.setXY(18,10);
	trap.push_back(tTrap);
	tTrap.setXY(19,10);
	trap.push_back(tTrap);
	tTrap.setXY(16,8);
	trap.push_back(tTrap);
	tTrap.setXY(17,8);
	trap.push_back(tTrap);
	tTrap.setXY(18,8);
	trap.push_back(tTrap);
	tTrap.setXY(17,6);
	trap.push_back(tTrap);
	tTrap.setXY(18,6);
	trap.push_back(tTrap);
	tTrap.setXY(19,6);
	trap.push_back(tTrap);
	tTrap.~Trap();//Destruindo o Objeto

	initscr();
	noecho();
	nodelay(stdscr, false);
	nodelay(stdscr, true);//getch nao espera o usuário pressionar a tecla
	curs_set(0);

	int maxLine=0, maxColum=0;
	try{
		maxLine = map.getMaxLine();
		maxColum = map.getMaxColum();
	}
	catch(char *msg)
	{
		char a;
		std::cout << msg << '\n';
		std::cin >> a;
		exit(1);
	}
	if(draw.menu(maxLine, maxColum))
	{
		move(0,0);
		draw.printScr();
		draw.printScr(&player);
		draw.printTrap(trap);
		draw.printBonus(bonus);
		while (player.getAlive() and !player.getWin())
		{


			player.act(colisor);

			for(size_t i=0; i<trap.size() or i< bonus.size(); ++i)
			{
				if(colisor.isPColision(&player, &bonus[i]) and i< bonus.size())
				{
					player.setScore(bonus[i].getScore());
					bonus.erase(bonus.begin()+i);
				}
				else
				{
					if(colisor.isPColision(&player, &trap[i]) and i<trap.size())
					{
						player.setAlive(false);
						break;
					}
				}
			}
			if(player.getPosY() == 18 and player.getPosX()== 65)
			{
				player.setWin(true);
				continue;
			}
			draw.printScr(&player);
			draw.printScore(player.getScore());
		}//Fim do laco do jogo
		nodelay(stdscr, false);
		draw.end(maxLine, maxColum, player.getScore());
	}
	echo();
	endwin();
	return 0;
}
