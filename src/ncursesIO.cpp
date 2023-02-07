#include "ncursesIO.hpp"

#include <ncurses.h>

ncursesIO::ncursesIO()
{
	initscr();
}

ncursesIO::~ncursesIO()
{
	endwin();
	std::cout << "Cleaning up" << std::endl;
}

void ncursesIO::Poll()
{
	clear();

	move(10, 20);
	printw("Choco+");

	// refreshes the screen
	refresh();

	// pause the screen output
	getch();
}