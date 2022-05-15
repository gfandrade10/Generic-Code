#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int *tokenize(const char *str)
{
    char buffer[strlen(str) + 1];
    strcpy(buffer, str);
    char *t = strtok(buffer, ".");
    int *res = (int*)malloc(4*sizeof(int));
    int i = 0;
    while (t != NULL)
    {
        res[i++] = atoi(t);
        t = strtok(NULL, ".");
    }
    return res;
}

uint32_t ips_between(const char *start, const char *end)
{
    int *ip1 = tokenize(start);
    int *ip2 = tokenize(end);
    uint32_t diff = 0;
    for(int i = 3; i >= 0; --i)
        diff += ip2[i]*pow(256,3-i) - ip1[i]*pow(256,3-i);
    free(ip1);
    free(ip2);
    return diff;
}

int main (int argc, char *argv[])
{
    char ip1[] = "10.0.0.0";
    char ip2[] = "10.1.0.50";
    uint32_t beefy = ips_between(ip1, ip2);
    printf("IP1 = %s\nIP2 = %s\nDiference = %i\n\n",ip1,ip2,beefy);
    return 0;
}