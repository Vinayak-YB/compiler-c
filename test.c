#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *file;
    char *buffer = 0;
    long length;

    file = fopen("test.unn", "r");
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(length + 1);
    fread(buffer, 1, length, file);
    
    fclose(file);
    buffer[length]= '\0';
    printf("%s\n", buffer);

    char *current = buffer;
    int current_index = 0;
    while(current[current_index] != '\0')
    {
        printf("%c\n", current[current_index]);
        current_index++;
    }
    return 0;
}