#define DEBUG

#ifndef DEBUG
#include <avr/io.h>
#include <util/delay.h>
#endif

#ifdef DEBUG
#include <stdio.h>
#endif

typedef enum TokenTypes
{
    PLUS,
    MINUS,
    MUL,
    DIV,
    POW,
    INT,
    FLOAT
} TokenTypes;

typedef struct Token
{

    int intValue;
    float floatValue;
} Token;

typedef struct TokenList
{
    Token value;

    struct TokenList *next;
} TokenList;

TokenList *bufferToList(char *expression);

int main()
{
    char *expressionBuffer = "5*4+3/2";
    bufferToList(expressionBuffer);
}

TokenList *bufferToList(char *expression)
{
    char *currentChar;
    for (currentChar = expression; *currentChar != '\0'; currentChar++)
    {
        switch (*currentChar)
        {
        case '+':
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        }
#ifdef DEBUG
        printf("%c", *currentChar);
#endif
    }
}