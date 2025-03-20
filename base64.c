#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct char_pos {
    uint64_t pos;
    bool valid;
} char_pos_t;

char_pos_t find_position(char c)
{
    const char* b64_array = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    for(uint64_t i = 0; i < 64; ++i)
    {
        if(c == b64_array[i])
            return (char_pos_t){i, true};
    }
    return (char_pos_t){0, false};
}

uint64_t custom_power(uint64_t expo)
{
    if (expo == 0) return 1;
    uint64_t res = 1;
    for (uint64_t i = 0; i < expo; ++i)
        res <<= 6;
    return res;
}

char* reverse_str(const char* str)
{
    uint64_t len = strlen(str);
    char* res = (char*)malloc(len+1);

    for(uint64_t i = 0; i < len; ++i)
    {
        res[i] = str[len - i - 1];
    }

    res[len] = '\0';
    return res;
}

uint64_t base64_to_base10(const char *base64) 
{
    uint64_t len = strlen(base64);
    uint64_t val = 0;

    if(len == 0)
        return 0;

    if(len == 1)
        return find_position(base64[0]).pos;
    
    char* str64 = reverse_str(base64);
    for(uint64_t i = 0; i < len; ++i)
    {
        uint64_t temp = find_position(str64[i]).pos;
        val += temp * custom_power(i);
    }

    free(str64);
    return val;
}

bool check_valid_input(int argc, char** argv)
{
    if(argc == 2)
    {
        uint64_t len = strlen(argv[1]);
        for(uint64_t i = 0; i < len; ++i)
        {
            if(!find_position(argv[1][i]).valid)
                return false;
        }
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    if(check_valid_input(argc, argv))
    {
        uint64_t res = base64_to_base10(argv[1]);
        printf("Base64 input: %s\nResult: %llu\n", argv[1], res);
        return 0;
    }
    printf("ERROR: invalid input\n");
    exit(EXIT_FAILURE);
}
