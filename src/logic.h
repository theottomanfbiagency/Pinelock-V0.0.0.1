#pragma once
#include <curses.h>
#include <iostream>
#include <string>

#include "player.hpp"
#include "menuMain.hpp"
#include "menuOption.h"

namespace gameState
{
	void menu()
	{
        WINDOW* menuWin = newwin(8, 11, 5, 5);
        box(menuWin, 0, 0);
        keypad(menuWin, true);

        init_pair(1, COLOR_BLACK, COLOR_RED);

        std::string options[] = { "New Game", "Load Game", "Options", "Stats", "About", "Quit" };
        int selection{ 0 };
        int choice;

        while (true)
        {
            for (int i = 0; i < sizeof(options) / sizeof(options[0]); i++)
            {
                if (i == selection)
                {
                    wattron(menuWin, COLOR_PAIR(1));
                }
                mvwprintw(menuWin, i + 1, 1, options[i].c_str());
                wattroff(menuWin, COLOR_PAIR(1));
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

	void game()
	{

	}
}
