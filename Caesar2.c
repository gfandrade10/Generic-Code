#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef FREE
#define FREE(vec, len) do {        \
    for (int i = 0; i < len; i++)  \
        free(vec[i]);              \
    free(vec);                     \
    } while(0);
#endif

char shift(char input, int* sft)
{
    if (*sft > 26)
        *sft = *sft % 26;
    if (input >= 'a' && input <= 'z')
    {
        if (*sft > 'z' - input)
            input = 'a' - ('z' - input + 1) + *sft;
        else
        {
            input += *sft;
            if (input < 'a')
                input = 'z' - ('a' - input - 1);            
        }
    }
    else if (input >= 'A' && input <= 'Z')
    {
        if (*sft > 'Z' - input)
            input = 'A' - ('Z' - input + 1) + *sft;
        else
        {
            input += *sft;
            if (input < 'A')
                input = 'Z' - ('A' - input - 1);            
        }
    }
    return input;
}

char* prefix(char input, int* sft)
{
    char* pref = (char*) malloc(sizeof(char) * 3);
    pref[0] = tolower(input);
    pref[1] = tolower(shift(input, sft));
    pref[2] = '\0';
    return pref;
}

char** encode(char* strng, int sft, int* lg)
{
    int sz1 = (((int)strlen(strng)+2)%5 == 0)
        ? ((int)strlen(strng)+2)/5
        : ((int)strlen(strng)+2)/5 + 1;
    *lg = (sz1*4 == (int)strlen(strng)+2)
        ? 4 : 5;
    char **result = (char**) malloc((*lg)*sizeof(char*));
    for (int i = 0; i < (*lg); ++i)
        result[i] = (char*) malloc(sizeof(char*)*(sz1+3));

    int count = 0;
    for (int i = 0, j = 0; i < (int)strlen(strng), j < *lg; ++i)
    {
        if (i == 0)
        {
            char* tmp = prefix(strng[i], &sft);
            count = sprintf(result[j], "%s", tmp);
            free(tmp);
        }
        result[j][count] = shift(strng[i], &sft);
        count++;
        if (count == sz1)
        {
            result[j][count] = '\0';
            count = 0;
            j++;
        }
        if (i == (int)strlen(strng)-1 && j < *lg)
            result[j][count] = '\0';
    }
    return result;
}

char* decode(char** result, int sz)
{
    int sft  = (result[0][1] > result[0][0])
        ? -1 * (result[0][1] - result[0][0])
        : -1 * (('z' - result[0][0]) + (result[0][1] - 'a') + 1);
    char res [100000];

    int pos = 0;    
    for (int i = 0; i < sz; i++)
    {
        if (i == 0)
            pos += sprintf(res, "%s", result[i]+2);
        else
            pos += sprintf(res+pos, "%s", result[i]);
    }    
    res[pos] = '\0';
    char* decoded = (char*) malloc(sizeof(char) * (pos+1));
    sprintf(decoded, "%s", res);
    for (int i = 0; i < pos; i++)
        decoded[i] = shift(decoded[i], &sft);
    return decoded;
}

int main(int argc, char** argv)
{
    int lg = 0;
    int sft = 8;
    char* input = "The blue and the dim and the dark cloths Of night and light and the half-light\nGuiiiiiiii";
    char **res = encode(input, sft, &lg);
    char *decoded = decode(res, lg);

    printf("\nENCODED:\n");
    for (int i = 0; i < lg; ++i)
        printf("%s\n", res[i]);
    printf("\nDECODED:\n%s\n\n",decoded);
    free(decoded);
    FREE(res,lg);
    return 0;
}