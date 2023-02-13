#include "Calculator.hpp"

#include <iostream>
#include <stack>
#include <queue>

#include <assert.h>

// shunting yard implementation
double Calculator::ComputeInput(std::array<MathToken, MAX_INPUT_SIZE> tokenInputs)
{
	std::stack<MathToken> operatorStack;
	std::queue<MathToken> outputQueue;

	for (unsigned int i = 0; i < 5; i++)
	{
		MathToken token = tokenInputs.at(i);
		if (token.type == MathEnum::NUMBER)
		{
			outputQueue.push(token);
		}
		else if (token.type == MathEnum::FUNCTION)
		{
			operatorStack.push(token);
		}
		else if (token.type == MathEnum::OPERATOR)
		{
			while (operatorStack.top().type != MathEnum::LEFT_PAREN && operatorStack.top().precedence >= token.precedence)
			{
				outputQueue.push(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.push(token);
		}
		else if (token.type == MathEnum::LEFT_PAREN)
		{
			operatorStack.push(token);
		}
		else if (token.type == MathEnum::RIGHT_PAREN)
		{
			while (operatorStack.top().type != MathEnum::LEFT_PAREN)
			{
				assert(!operatorStack.empty());
				outputQueue.push(operatorStack.top());
				operatorStack.pop();
			}
		}
	}

	while (!operatorStack.empty())
	{
		assert(operatorStack.top().type != MathEnum::LEFT_PAREN);
		outputQueue.push(operatorStack.top());
		operatorStack.pop();
	}

	while (!outputQueue.empty())
	{
		MathToken token = outputQueue.front();
		if (token.type == MathEnum::NUMBER)
		{
			std::cout << std::to_string(token.numericValue) << std::endl;
		}
		else if (token.type == MathEnum::OPERATOR)
		{
			if (token.op == MathEnum::ADD)
			{
				std::cout << "add" << std::endl;
			}
			else if (token.op == MathEnum::SUB)
			{
				std::cout << "sub" << std::endl;
			}
			else if (token.op == MathEnum::MUL)
			{
				std::cout << "mul" << std::endl;
			}
			else if (token.op == MathEnum::DIV)
			{
				std::cout << "div" << std::endl;
			}
		}
	}

	return 0;
}