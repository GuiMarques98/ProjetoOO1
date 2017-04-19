#include "../inc/game_object.hpp"
#include "../inc/enemies.hpp"
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
	Draw draw(map, 10000);
	Player player(19,18);
	Colisor colisor(map.getAllMap());

	initscr();
	noecho();
	//nodelay(stdscr, true);//getch nao espera o usuário pressionar a tecla
	curs_set(0);
	draw.printScr();
	draw.printScr(&player);
	while (player.getAlive())
	{
		player.act(colisor);
		draw.printScr(&player);
	}
	getch();
	endwin();
	return 0;
}
