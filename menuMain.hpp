#include <curses.h>
#include <iostream>
#include <string>

#include "menuOption.h"

class menu
{
	public:
		menu(option options[], int y_size, int x_size, int y_pos, int x_pos);
};

menu::menu(option options[], int y_size, int x_size, int y_pos, int x_pos)
{
	WINDOW* menuWin = newwin(y_size, x_size, y_pos, x_pos);
	box(menuWin, 0, 0);
	keypad(menuWin, true);

	int selection{ 0 };
	int choice;

    while (true)
    {
        for (int i = 0; i < sizeof(options) / sizeof(options[0]); i++)
        {
            if (i == selection)
            {
                wattron(menuWin, A_REVERSE);
            }
            mvwprintw(menuWin, i + 1, 1, options[i].name.c_str());
            wattroff(menuWin, A_REVERSE);
        }

        choice = wgetch(menuWin);

        switch (choice)
        {
            case KEY_UP:
                if (selection > 0)
                {
                    selection--;
                }
                break;
            case KEY_DOWN:
                if (selection < sizeof(options) / sizeof(options[0]) - 1)
                {
                    selection++;
                }
                break;
            case '\n':

                break;
        }
    }
    wrefresh(menuWin);
}
