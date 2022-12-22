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
    int intValue;
    float floatValue;
} Token;

Token *bufferToList(char *expression);

int main()
{
    char *expressionBuffer = "^+/";
    Token *tokens = bufferToList(expressionBuffer);
    printf("%d", tokens[0].type);
}

Token *bufferToList(char *expression)
{
    char *currentChar;

    Token *tokenArray = (Token *)malloc(sizeof(Token) * strlen(expression));
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
        }
    }

#ifdef DEBUG
    printf("%c", *currentChar);
#endif
    return tokenArray;
}
