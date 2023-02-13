#pragma once

#include <iostream>
#include "InputToken.hpp"

class IO
{
public:
	virtual ~IO() {}
	virtual InputEnum PollInput()
	{
		return InputEnum::ERROR_INPUT;
	}

	virtual void ClearScreen() {}
	virtual void WriteChar(int c) {}
	virtual void WriteString(std::string str) {}
	virtual void MoveCursor(int x, int y) {}
};
