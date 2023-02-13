#pragma once

#include <string>

typedef enum class InputEnum
{
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	NEG,
	ADD,
	SUB,
	MUL,
	DIV,
	ENTER,
	CLEAR,
	NO_INPUT,
	ERROR_INPUT
} InputEnum;

typedef struct InputToken
{
	InputEnum inputEnum;
	std::string stringRepresentation;
} InputToken;

typedef enum class MathEnum
{
	NUMBER,
	FUNCTION,
	LEFT_PAREN,
	RIGHT_PAREN,
	ADD,
	SUB,
	MUL,
	DIV,
	POW
} MathEnum;

class MathToken
{
public:
	MathEnum type;
	double numericValue;
	int precedence;

	static MathToken GetNumber(double number)
	{
		return MathToken{MathEnum::NUMBER, number, 0};
	}

	static MathToken GetAdd()
	{
		return MathToken{MathEnum::ADD, 0, 0};
	}

	static MathToken GetSub()
	{
		return MathToken{MathEnum::SUB, 0, 0};
	}

	static MathToken GetMul()
	{
		return MathToken{MathEnum::MUL, 0, 1};
	}

	static MathToken GetDiv()
	{
		return MathToken{MathEnum::DIV, 0, 1};
	}

	static MathToken GetPow()
	{
		return MathToken{MathEnum::POW, 0, 2};
	}

	static MathToken GetLeftParen()
	{
		return MathToken{MathEnum::LEFT_PAREN, 0, 0};
	}

	static MathToken GetRightParen()
	{
		return MathToken{MathEnum::RIGHT_PAREN, 0, 0};
	}

	static bool IsOperator(MathToken token)
	{
		return token.type == MathEnum::ADD || token.type == MathEnum::SUB || token.type == MathEnum::MUL || token.type == MathEnum::DIV || token.type == MathEnum::POW;
	}
};