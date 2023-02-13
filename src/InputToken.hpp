#pragma once

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
} InputToken;

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
	RIGHT_PAREN
} MathEnum;

typedef struct MathToken
{
	MathEnum type;
	int numericValue;
} MathToken;