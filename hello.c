#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

char *LettersToNumbers(const char *input)
{
    int position = 0;
    char *res = (char*)malloc(3*strlen(input)*sizeof(char));
    for(int i=0; i<strlen(input); i++)
    {
        if(isalpha(input[i]) && i != strlen(input) - 1)
            position += sprintf(res + position, "%d ", (int)(toupper(input[i]) - '0' - 16));
        else if (isalpha(input[i]) && i == strlen(input) - 1) 
            position += sprintf(res + position, "%d", (int)(toupper(input[i]) - '0' - 16));
    }
    if (position == 0) res[0] = '\0';
    else if(res[position-1] == ' ') res[position-1] = '\0';
    else res[position] = '\0';
    return res;
}

int main(int argc, char **argv)
{
    char text[] = "250";
    char *numbers = LettersToNumbers(text);
    printf("%s.\n\n", numbers);
    free(numbers);
    return 0;
}