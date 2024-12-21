#include <stdio.h>
#include <stdlib.h>

typedef enum {
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
} TokenTypeSeparator;

typedef enum {
    EXIT,
} TokenTypeKeyword;

typedef enum {
    INT,
} TokenTypeLiteral;

int main()
{
    printf("In main \n");
    return 0;
}