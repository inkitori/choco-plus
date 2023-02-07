#pragma once

#include "IO.hpp"

class ncursesIO : public IO
{
public:
	ncursesIO();
	~ncursesIO() override;

	void Poll() override;
};