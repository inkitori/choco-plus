#include "Calculator.hpp"

#include <stack>
#include <queue>

// shunting yard implementation
double Calculator::ComputeInput(std::array<MathToken, MAX_INPUT_SIZE> tokenInputs)
{
	std::stack<MathToken> operatorStack;
	std::queue<MathToken> outputQueue;

	for (MathToken token : tokenInputs)
	{
		if (token.type == MathEnum::NUMBER) {
			outputQueue.push(token);
		}
		else if (token.type == MathEnum::FUNCTION) {
			operatorStack.push(token);
		}
		else if (token.type == MathEnum::OPERATOR) {
			
		}

	}

	return 0;
}