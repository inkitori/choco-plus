#include <iostream>
#include "App.hpp"

App::App(std::unique_ptr<IO> _io) : io(std::move(_io)) {}

void App::Run()
{
    while (true)
    {
        io->Poll();
    }
}