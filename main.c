#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    SEMI, 
    OPEN_PAREN,
    CLOSE_PAREN, 
} TypeSeparator;

typedef enum {
    EXIT, //this refers to exit
} TypeKeyword;

typedef enum {
    INT,
} TypeLiteral; //there will be more types

typedef struct {
    TypeKeyword type;
} TokenKeyword;

typedef struct {
    TypeSeparator type;
} TokenSeparator;

typedef struct {
    TypeLiteral type;
    char * value;
} TokenLiteral;

TokenLiteral *generate_number(char current, FILE *file)
{
    TokenLiteral *token = malloc(sizeof(TokenLiteral));
    token->type = INT;
    char * value = malloc(sizeof(char) * 8);
    int value_index = 0;
    while(isdigit(current) && current != EOF)
    {
        if(!isdigit(current))
        {
            break;
        }
        
        value[value_index] =  current;
        value_index++;

        current = fgetc(file);
    }
    token->value = value;
    // free(value);
    return token;
}

TokenKeyword *generate_keyword(char current, FILE *file)
{
    TokenKeyword *token = malloc(sizeof(TokenKeyword));
    char *keyword = malloc(sizeof(char) * 8);
    int keyword_index = 0;
    while(isalpha(current) && current != EOF)
    {
        keyword[keyword_index] = current;
        current = fgetc(file);
    }
    
    char keyword_str[keyword_index];
    
    for(int i = 0; i < keyword_index; i++)
    {
        keyword_str[i] = keyword[i];
    }

    if(keyword_str == 'exit')
    {
        token->type = EXIT;
        return token;
    }
}

void lexer(FILE *file)
{
    char current = fgetc(file);

     while(current != EOF){
        if(current == ';')
        {
            printf("Found semicolon \n");
        }
        else if(current == '(')
        {
            printf("Found open paren \n");
        }
        else if(current == ')')
        {
            printf("Found close paren \n");
        }
        else if(isdigit(current))
        {
            TokenLiteral *testToken = generate_number(current, file);
            printf("Test token value %s\n", testToken->value);
        }
        else if(isalpha(current))
        {
            printf("Found character %c\n", current);
        }

        current = fgetc(file);

     }
}

int main()
{
    FILE *file;
    file = fopen("test.unn", "r");
    lexer(file);
    
}