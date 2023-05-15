#include <curses.h>
#include <iostream>
#include <string>

#include "logic.h"
#include "player.hpp"

int main()
{
    initscr();
    PDC_set_title("Pinelock");
    noecho();

    start_color();

    gameState::menu();

    getch();
    endwin();

    return 0;
}
