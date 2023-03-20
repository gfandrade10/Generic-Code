#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define LIST_SIZE 28

typedef struct pair {
    const unsigned num;
    const char *name;
} pair;

const pair List[LIST_SIZE] = {
    {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"},
    {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"},
    {9, "nine"}, {10, "ten"}, {11, "eleven"}, {12, "twelve"},
    {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"},
    {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"},
    {30, "thirty"}, {40, "forty"}, {50, "fifty"}, {60, "sixty"},
    {70, "seventy"}, {80, "eighty"}, {90, "ninety"}, {0, "zero"}
};

char *pair_find(unsigned n)
{
    for(int i = 0; i < LIST_SIZE; ++i)
    {
        if (n == List[i].num)
        {
            unsigned tmp = (unsigned)strlen(List[i].name);
            char *ret = (char*) malloc((tmp+1)*sizeof(char));
            sprintf(ret,"%s", List[i].name);
            return ret;
        }
    }
    return NULL;
}

char *number_to_words(unsigned n, char *num_string)
{
    if (n <= 20)
    {
        char *p = pair_find(n);
        sprintf(num_string,"%s", p);
        free(p);
        return num_string;
    }    
    unsigned num = (unsigned)log10(n) + 1;
    char digits[num+1];
    sprintf(digits, "%u", n);    
  
    unsigned pos = 0;
    unsigned k;
    bool thousand_flag = false;
    if (num > 3)
    {
        k = num - 3;
        thousand_flag = true;
    }
    else
        k = num;
    for (unsigned i = 0; i < num; i++)
    {
        if (digits[i] != '0')
        {
            if (k - 1 == 2)
            {
                char *c = pair_find((unsigned)(digits[i]-'0'));
                pos += sprintf(num_string + pos, "%s hundred ", c);
                free(c);
            }
            else if (k-1 == 1 && digits[i] == '1')
            {
                unsigned tmp = (digits[i]-'0')*10 + (digits[i+1] - '0');
                char *c = pair_find(tmp);
                pos += sprintf(num_string + pos, "%s ", c);
                free(c);
                ++i;
                k--;
            }
            else if (k-1 == 1 && digits[i+1] != '0')
            {   
                char *c = pair_find(10*(digits[i]-'0'));
                pos += sprintf(num_string + pos, "%s-", c);
                free(c);
            }
            else if (k-1 == 1 && digits[i+1] == '0')
            {   
                char *c = pair_find(10*(digits[i]-'0'));
                pos += sprintf(num_string + pos, "%s ", c);
                free(c);
            }
            else
            {            
                char *c = pair_find(digits[i]-'0');
                pos += sprintf(num_string + pos, "%s ", c);
                free(c);
            }
        }
        k--;
        if (k == 0)
        {
            k = 3;
            if (thousand_flag)
            {
                pos += sprintf(num_string + pos, "%s", "thousand ");
                thousand_flag = false;
            }
        }
    }
    size_t s = strlen(num_string);
    if (num_string[s-1] == ' ' || num_string[s-1] == '-')
        num_string[s-1] = '\0';
    return num_string;
}

int main (int argc, char* argv[])
{
    unsigned n = (unsigned)atoi(argv[1]);
    char input[1000];
    printf ("%s\n\n", number_to_words(n, input));
    return 0;
}