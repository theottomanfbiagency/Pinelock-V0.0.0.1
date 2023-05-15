#include <curses.h>
#include <iostream>
#include <string>
#include "player.hpp"

Player::Player(WINDOW* win, int y, int x, int z, std::string uName, profession uProfession, gender uGender)
{
	name = uName;
	skill = uProfession;
	gen = uGender;

	curRoom = win;
	x_pos = x;
	y_pos = y;
	z_pos = z;

	getmaxyx(curRoom, y_col, x_col);
}

int Player::movement()
{
	int input = wgetch(curRoom);
	switch (input)
	{
		case KEY_UP:
			if (y_pos > 0);
				y_pos--;
			break;
		case KEY_DOWN:
			if (y_pos < y_col)
				y_pos++;
			break;
		case KEY_LEFT:
			if (x_pos > 0)
				x_pos--;
			break;
		case KEY_RIGHT:
			if (x_pos < x_col)
				x_pos++;
			break;
	}
	return(input);
}
