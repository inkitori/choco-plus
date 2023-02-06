#include <iostream>
#include <string>

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
    std::string expressionBuffer = "^+/";

    Token tokenArray[MAX_STACK_SIZE];

    Token *tokens = bufferToList(expressionBuffer, tokenArray);
    printf("%d", tokens[0].type);
}

Token *bufferToList(std::string expression, Token *tokenArray)
{
    char *currentChar;

    int tokenIndex = 0;

    // TODO: check for input going above MAX_STACK_SIZE
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

namespace App
{
    void Run()
    {
    }
}