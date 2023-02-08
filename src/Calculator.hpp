#pragma once

#include <array>

#include "InputToken.hpp"

class Calculator
{
private:
	static const int MAX_INPUT_SIZE = 128;

public:
	static double ComputeInput(std::array<InputToken, MAX_INPUT_SIZE>);
};