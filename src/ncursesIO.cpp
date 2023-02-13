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

InputEnum ncursesIO::PollInput()
{
	int ch = getch();

	switch (ch)
	{
	case '1':
		return InputEnum::ONE;
	case '2':
		return InputEnum::TWO;
	case '3':
		return InputEnum::THREE;
	case '4':
		return InputEnum::FOUR;
	case '5':
		return InputEnum::FIVE;
	case '6':
		return InputEnum::SIX;
	case '7':
		return InputEnum::SEVEN;
	case '8':
		return InputEnum::EIGHT;
	case '9':
		return InputEnum::NINE;
	case '0':
		return InputEnum::ZERO;
	case '\'':
		return InputEnum::ADD;
	case ',':
		return InputEnum::SUB;
	case '.':
		return InputEnum::MUL;
	case 'p':
		return InputEnum::DIV;
	case 'y':
		return InputEnum::NEG;
	case KEY_ENTER:
		return InputEnum::ENTER;
	case ERR:
		return InputEnum::NO_INPUT;
	default:
		return InputEnum::ERROR_INPUT;
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