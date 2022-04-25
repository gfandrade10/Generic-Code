#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>

char *encode(const char *str)
{
    if (strlen(str) == 0) return NULL;
    char res[strlen(str)*2];
    char buffer1, buffer2;
    buffer2 = str[1];
    buffer1 = str[strlen(str)-1];
    int pos = sprintf(res,"%d",(int)(str[0]));
    if (strlen(str) > 1) res[pos] = buffer1;
    for(int i = 2; i < strlen(str); i++)
    {
        pos++;
        if (i != strlen(str)-1) res[pos] = str[i];
        else res[pos] = buffer2;        
    } 
    res[pos+1] = '\0';
    char *text = (char*)malloc((pos+1)*sizeof(char));
    sprintf(text,"%s",res);
    return text;
}

char *encrypt_this(const char *str)
{
    if (strlen(str) == 0) return NULL;
    char copy[strlen(str)+1];
    strcpy(copy, str);
    char *token = strtok(copy, " \t");
    char *res = (char*)malloc(2 * strlen(str) * sizeof(char));
    int i = 0;
    while (token != NULL)
    {  
        char *tmp = encode(token);
        i += sprintf(res+i,"%s",tmp);
        token = strtok(NULL," \t");
        if (token != NULL) i += sprintf(res+i," ");
        free(tmp);
    }
    res[i] = '\0';
    return res;
}

int main(int argc, char **argv)
{
    char text[] = "s guii aaaa";
    char *res = encrypt_this(text);
    printf("Input: %s\nResult: %s\n\n", text, res);
    free(res);
    return 0;
}