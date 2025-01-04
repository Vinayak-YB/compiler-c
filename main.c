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

TokenLiteral *generate_number(char *current, int *current_index)
{
    TokenLiteral *token = malloc(sizeof(TokenLiteral));
    token->type = INT;
    char *value = malloc(sizeof(char) * 8);
    int value_index = 0;

    // Parse digits
    while (isdigit(current[*current_index]) && current[*current_index] != '\0')
    {
        value[value_index] = current[*current_index];
        value_index++;
        (*current_index)++;  // Dereference and increment
    }

    value[value_index] = '\0'; // Null-terminate the string
    token->value = value;

    return token;
}

TokenKeyword *generate_keyword(char *current, int *current_index)
{
    TokenKeyword *token = malloc(sizeof(TokenKeyword));
    char *keyword = malloc(sizeof(char) * 8);
    int keyword_index = 0;

    // Parse alphabetic characters
    while (isalpha(current[*current_index]) && current[*current_index] != '\0')
    {
        keyword[keyword_index] = current[*current_index];
        keyword_index++;
        (*current_index)++;
    }

    keyword[keyword_index] = '\0'; // Null-terminate the string

    if (strcmp(keyword, "exit") == 0)
    {
        token->type = EXIT;
        printf("Token type: exit\n");
        free(keyword); // Free allocated memory for keyword
        return token;
    }

    free(keyword); // Free allocated memory if not matched
    return NULL;
}

void lexer(FILE *file)
{
    int length;
    char *buffer = 0;
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(sizeof(char) * length);
    fread(buffer, 1, length, file);
    fclose(file);
    buffer[length + 1] = '\0';

    char *current = malloc(sizeof(char) * length + 1);
    current = buffer;
    int current_index = 0;


     while(current[current_index] != '\0')
     {
        // printf("current : %c\n", current[current_index]);
        if(current[current_index] == ';')
        {
            printf("Found semicolon \n");
        }
        else if(current[current_index] == '(')
        {
            printf("Found open paren \n");
        }
        else if(current[current_index] == ')')
        {
            printf("Found close paren \n");
        }
        else if(isdigit(current[current_index]))
        {
            TokenLiteral *testToken = generate_number(current, &current_index);
            printf("Test token value %s\n", testToken->value);
        }
        else if(isalpha(current[current_index]))
        {
            TokenKeyword *testKeyword = generate_keyword(current, &current_index);
            printf("Found value %c\n", current[current_index]);
        }

        current_index++;

     }
}

int main()
{
    FILE *file;
    file = fopen("test.unn", "r");
    lexer(file);
    return 0;
    
}