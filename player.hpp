#pragma once
#include <curses.h>
#include <iostream>
#include <string>

enum class gender
{
	male,
	female
};

enum class profession
{
	Wizard,
	Rogue,
	Knight,
	Swordsman
};

enum class politicalAlignment
{
	lawful,
	neutral,
	chaotic
};

enum class moralAlignment
{
	morality,
	indifferent,
	malice
};

class Player
{
	public:
		std::string name;
		profession skill;
		gender gen;

		int level, exp, magic, gold;

		int x_pos, y_pos, z_pos;
		int x_col, y_col;

		WINDOW* curRoom;

		//functions
		Player(WINDOW* win, int y, int x, int z, std::string uName, profession uProfession, gender uGender);
		int movement();
};
