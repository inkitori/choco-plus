#include "ncursesIO.hpp"

#include <ncurses.h>

ncursesIO::ncursesIO()
{
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
}

ncursesIO::~ncursesIO()
{
	endwin();
}

InputToken ncursesIO::PollInput()
{
	int ch = getch();

	switch (ch)
	{
	case '1':
		return InputToken::ONE;
	case '2':
		return InputToken::TWO;
	case '3':
		return InputToken::THREE;
	case '4':
		return InputToken::FOUR;
	case '5':
		return InputToken::FIVE;
	case '6':
		return InputToken::SIX;
	case '7':
		return InputToken::SEVEN;
	case '8':
		return InputToken::EIGHT;
	case '9':
		return InputToken::NINE;
	case '0':
		return InputToken::ZERO;
	case '\'':
		return InputToken::ADD;
	case ',':
		return InputToken::SUB;
	case '.':
		return InputToken::MUL;
	case 'p':
		return InputToken::DIV;
	case 'y':
		return InputToken::NEG;
	case ERR:
		return InputToken::NO_INPUT;
	default:
		return InputToken::ERROR_INPUT;
	}
}

void ncursesIO::ClearScreen()
{
	clear();

	refresh();
}

void ncursesIO::MoveCursor(int x, int y)
{
	// more intuitive to pass as x, y
	move(y, x);
}

void ncursesIO::WriteChar(int c)
{
	addch(unsigned(c));

	refresh();
}

void ncursesIO::WriteString(std::string str)
{
	printw(str.c_str());

	refresh();
}