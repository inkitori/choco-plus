#include "Calculator.hpp"

#include <stack>
#include <queue>

// shunting yard implementation
double Calculator::ComputeInput(std::array<InputToken, MAX_INPUT_SIZE> tokenInputs)
{
	std::stack<InputToken> operatorStack;
	std::queue<InputToken> outputQueue;

	for (InputToken token : tokenInputs)
	{
	}

	return 0;
}