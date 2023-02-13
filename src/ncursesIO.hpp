#pragma once

#include "IO.hpp"

class ncursesIO : public IO
{
public:
	ncursesIO();
	~ncursesIO() override;

	InputEnum PollInput() override;
	void ClearScreen() override;
	void WriteChar(int c) override;
	void WriteString(std::string str) override;
	void MoveCursor(int x, int y) override;
};