#pragma once

#include <iostream>

class IO
{
public:
	virtual ~IO() {}
	virtual void Poll()
	{
		std::cout << "Shouldn't be getting called";
	}
};