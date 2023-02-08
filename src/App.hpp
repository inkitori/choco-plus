#pragma once

#include <memory>

#include "Application.hpp"
#include "IO.hpp"

class App
{
public:
	App(std::unique_ptr<IO> io);

	void Run();

private:
	std::unique_ptr<IO> io;
	Application currentProcess;
};