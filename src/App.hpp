#pragma once

#include "IO.hpp"
#include <memory>

class App
{
public:
	App(std::unique_ptr<IO> io);

	void Run();

private:
	std::unique_ptr<IO> io;
};