#include "Calculator.hpp"

#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

#include <assert.h>

double Calculator::ComputeInput(std::vector<MathToken> tokenInputs)
{
	std::queue<MathToken> outputQueue = GeneratePostfix(tokenInputs);
	while (!outputQueue.empty())
	{
		MathToken token = outputQueue.front();
		if (token.type == MathEnum::NUMBER)
		{
			std::cout << std::to_string(token.numericValue) << std::endl;
		}
		else if (MathToken::IsOperator(token))
		{
			if (token.type == MathEnum::ADD)
			{
				std::cout << "add" << std::endl;
			}
			else if (token.type == MathEnum::SUB)
			{
				std::cout << "sub" << std::endl;
			}
			else if (token.type == MathEnum::MUL)
			{
				std::cout << "mul" << std::endl;
			}
			else if (token.type == MathEnum::DIV)
			{
				std::cout << "div" << std::endl;
			}
			else if (token.type == MathEnum::POW)
			{
				std::cout << "pow" << std::endl;
			}
			else
			{
				std::cout << "unknown op" << std::endl;
			}
		}
		else
		{
			std::cout << "what is this" << std::endl;
		}

		outputQueue.pop();
	}
	// return EvaluatePostfix(GeneratePostfix(tokenInputs));
	return 0;
}

std::queue<MathToken> Calculator::GeneratePostfix(std::vector<MathToken> tokenInputs)
{
	std::stack<MathToken> operatorStack;
	std::queue<MathToken> outputQueue;

	for (unsigned int i = 0; i < tokenInputs.size(); i++)
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
		else if (MathToken::IsOperator(token))
		{
			while (!operatorStack.empty() && operatorStack.top().type != MathEnum::LEFT_PAREN && operatorStack.top().precedence >= token.precedence)
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

			assert(operatorStack.top().type == MathEnum::LEFT_PAREN);
			operatorStack.pop();
		}
	}

	while (!operatorStack.empty())
	{
		assert(operatorStack.top().type != MathEnum::LEFT_PAREN);
		outputQueue.push(operatorStack.top());
		operatorStack.pop();
	}

	return outputQueue;
}

double Calculator::EvaluatePostfix(std::queue<MathToken> postfixQueue)
{
	std::stack<MathToken> postfixStack;

	while (!postfixQueue.empty())
	{
		MathToken token = postfixQueue.front();
		postfixQueue.pop();

		if (token.type == MathEnum::NUMBER)
		{
			postfixStack.push(token);
		}
		else if (MathToken::IsOperator(token))
		{
			MathToken leftOp = postfixStack.top();
			postfixStack.pop();

			MathToken rightOp = postfixStack.top();
			postfixStack.pop();

			if (token.type == MathEnum::ADD)
			{
				postfixStack.push(MathToken::GetNumber(leftOp.numericValue + rightOp.numericValue));
			}
			else if (token.type == MathEnum::SUB)
			{
				postfixStack.push(MathToken::GetNumber(leftOp.numericValue - rightOp.numericValue));
			}
			else if (token.type == MathEnum::MUL)
			{
				postfixStack.push(MathToken::GetNumber(leftOp.numericValue * rightOp.numericValue));
			}
			else if (token.type == MathEnum::DIV)
			{
				postfixStack.push(MathToken::GetNumber(leftOp.numericValue / rightOp.numericValue));
			}
			else if (token.type == MathEnum::POW)
			{
				postfixStack.push(MathToken::GetNumber(pow(leftOp.numericValue, rightOp.numericValue)));
			}
		}
	}

	return postfixStack.top().numericValue;
}