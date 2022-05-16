#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int search_substr(const char *full_text, const char *search_text, bool allow_overlap) 
{
    size_t ltex = strlen(full_text), lser = strlen(search_text);
    if(ltex == 0 || lser == 0) 
        return 0;
    unsigned int count;
    int res = 0;
    for(size_t i = 0; i < ltex; ++i)
    {
        count = 0;
        for(size_t j = 0; j < lser; ++j)
            if(search_text[j] == full_text[i+j] && (i+j) < ltex)
                count++;
        if (count == lser)
            res++;
        if(!allow_overlap && count == lser)
            i += lser-1;
    }
    return res;
}

int main(int argc, char **argv)
{
    printf ("Repeat: %i\n\n",search_substr("abcabcabc", "abc", 0));
    return 0;
}