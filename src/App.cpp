#include <iostream>
#include "App.hpp"

#include "CalculatorApplication.hpp"

App::App(std::unique_ptr<IO> _io) : io(std::move(_io))
{
    // currentProcess = std::make_unique<CalculatorApplication>(io);
}

void App::Run()
{
    while (true)
    {
        InputEnum inputToken = io->PollInput();
        if (inputToken != InputEnum::NO_INPUT)
        {
            if (inputToken == InputEnum::ONE)
            {
                io->WriteString("1");
            }
        }

        // currentProcess->Update();
    }
}