#include <iostream>
#include "App.hpp"

App::App(std::unique_ptr<IO> _io) : io(std::move(_io)) {}

void App::Run()
{
    io->WriteString("Welcome to Choco+");
    io->MoveCursor(0, 1);

    while (true)
    {
        InputToken inputToken = io->PollInput();
        if (inputToken != InputToken::NO_INPUT)
        {
            io->WriteChar('a');
        }
    }
}