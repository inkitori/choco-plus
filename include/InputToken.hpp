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
	OPERATOR,
	FUNCTION,
	LEFT_PAREN,
	RIGHT_PAREN,
	ADD,
	SUB,
	MUL,
	DIV
} MathEnum;

class MathToken
{
public:
	MathEnum type;
	double numericValue;
	int precedence;
	MathEnum op;

	static MathToken GetNumber(double number)
	{
		return MathToken{MathEnum::NUMBER, number, 0, MathEnum::NUMBER};
	}

	static MathToken GetAdd()
	{
		return MathToken{MathEnum::OPERATOR, 0, 0, MathEnum::ADD};
	}

	static MathToken GetSub()
	{
		return MathToken{MathEnum::OPERATOR, 0, 0, MathEnum::SUB};
	}

	static MathToken GetMul()
	{
		return MathToken{MathEnum::OPERATOR, 0, 0, MathEnum::MUL};
	}

	static MathToken GetDiv()
	{
		return MathToken{MathEnum::OPERATOR, 0, 0, MathEnum::DIV};
	}
};