#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

char *diamond (int n)
{
    if (n < 1 || n%2 == 0) return NULL;
    int pos = 0;
    int star = 1, zero = n/2;
    char *res = (char*)malloc( (n*n + 2) * sizeof(char) );
    while (star <= n)
    {
        for(int j=0; j < zero; ++j)
            pos += sprintf(res + pos," ");
        for(int j=1; j <= star; ++j)
            pos += sprintf(res + pos,"*");
        pos += sprintf(res + pos,"\n");
        star += 2;
        zero--;
    }
    star = n - 2;
    zero = 1;
    while (star > 0)
    {
        for(int j=0; j < zero; ++j)
            pos += sprintf(res + pos," ");
        for(int j=1; j <= star; ++j)
            pos += sprintf(res + pos,"*");
        pos += sprintf(res + pos,"\n");
        star -= 2;
        zero++;
    }
    res[pos] = '\0';
    return res;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    char *output = diamond(n);
    if (output) printf("%s\n\n",output);
    else printf("NULL!\n\n");
    free(output);
    return 0;
}