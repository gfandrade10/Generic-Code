#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

std::string to_camel_case(std::string text) 
{
    if (text.empty()) return "";
    char phrase[text.length() + 1];
    for(std::size_t i = 0; i < text.length(); i++)
        phrase[i] = text[i];
    phrase[text.length()] = '\0';

    char *p = strtok(phrase, "_- ");
    std::string res (p);
    while (p != NULL)
    {
        p = strtok(NULL, "_- ");
        if (p != NULL)
        {
            std::string buffer(p);
            buffer[0] = toupper(buffer[0]);
            res += buffer;
        }
    }
    return res;
}

int main(int argc, char** argv)
{
    std::string input = "hello brothers_hahah-This_lul";
    std::cout << to_camel_case(input) << "\n\n";
    return 0;
}
