#pragma once
#include <curses.h>
#include <iostream>
#include <string>

struct option
{
	std::string name;
	void *(func);
};
