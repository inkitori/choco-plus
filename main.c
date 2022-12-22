#define DEBUG

#ifndef DEBUG
#include <avr/io.h>
#include <util/delay.h>
#endif

#ifdef DEBUG
#include <stdio.h>
#endif

#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 128

typedef enum TokenType
{
    PLUS,
    MINUS,
    MUL,
    DIV,
    POW,
    INT,
    FLOAT
} TokenType;

typedef struct Token
{
    TokenType type;
    double value;
} Token;

Token *bufferToList(char *expression, Token *);

int main()
{
    char *expressionBuffer = "^+/";

    Token tokenArray[MAX_STACK_SIZE];

    Token *tokens = bufferToList(expressionBuffer, tokenArray);
    printf("%d", tokens[0].type);
}

Token *bufferToList(char *expression, Token *tokenArray)
{
    char *currentChar;

    int tokenIndex = 0;

    for (currentChar = expression; *currentChar != '\0'; currentChar++)
    {
        Token token;
        switch (*currentChar)
        {
        case '+':
            token.type = PLUS;
            tokenArray[tokenIndex] = token;
            tokenIndex++;
            break;
        case '-':
            token.type = MINUS;
            tokenArray[tokenIndex] = token;
            tokenIndex++;
            break;
        case '*':
            token.type = MUL;
            tokenArray[tokenIndex] = token;
            tokenIndex++;
            break;
        case '/':
            token.type = DIV;
            tokenArray[tokenIndex] = token;
            tokenIndex++;
            break;
        case '^':
            token.type = POW;
            tokenArray[tokenIndex] = token;
            tokenIndex++;
            break;
        default:
            // parse number
            break;
        }
    }

    return tokenArray;
}
