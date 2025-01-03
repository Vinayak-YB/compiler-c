#include <stdio.h>

int main()
{
    FILE *file;
    char buffer[0];

    file = fopen("test.unn", "r");

    fread(buffer, 1, 1, file);
    printf("%c\n", buffer);
    fclose(file);
}