#pragma once

#include <iostream>
#include "InputToken.hpp"

class IO
{
public:
	virtual ~IO() {}
	virtual InputToken PollInput()
	{
		return InputToken::ERROR_INPUT;
	}

	virtual void ClearScreen() {}
	virtual void WriteChar(int c) {}
	virtual void WriteString(std::string str) {}
	virtual void MoveCursor(int x, int y) {}
};
