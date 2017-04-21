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
	Player player(19,18);
	Colisor colisor(map.getAllMap());
	std::vector<Trap> trap;
	std::vector<Bonus> bonus;
	Trap trap1(2, 2, '#');
	trap.push_back(trap1);
	trap1.setXY(9, 9);

	trap.push_back(trap1);


	initscr();
	noecho();
	nodelay(stdscr, true);//getch nao espera o usuário pressionar a tecla
	curs_set(0);
	draw.printScr();
	draw.printScr(&player);
	draw.printTrap(trap);

	while (player.getAlive())
	{
		player.act(colisor);
		player.act(colisor);
		draw.printScr(&player);
		draw.putDelay();
	}
	nodelay(stdscr, false);
	echo();
	getch();
	endwin();
	return 0;
}
