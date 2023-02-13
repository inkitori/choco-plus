#pragma once

#include <vector>
#include <queue>

#include "InputToken.hpp"

class Calculator
{
private:
	static const int MAX_INPUT_SIZE = 128;
	static std::queue<MathToken> GeneratePostfix(std::vector<MathToken> tokenInputs);
	static double EvaluatePostfix(std::queue<MathToken> postfixQueue);

public:
	static double ComputeInput(std::vector<MathToken>);
};