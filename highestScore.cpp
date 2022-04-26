#include <cstring>
#include <iostream>
#include <vector>

std::string highestScoringWord(const std::string &str)
{
    if (str.empty()) 
        return "";
    char text[str.size()+1];
    strcpy(text,str.c_str());
    char *token = NULL;
    token = strtok(text, " \t");
    std::string res = "";
    int max = -1;
    while (token != NULL)
    {
        int sum = 0;
        for (int i = 0; i < strlen(token); ++i)
            sum += (int)(token[i]) - 96;
        if (sum > max)
        {
            max = sum;
            res = std::string(token);
        }
        token = strtok(NULL, " \t");
    }
    return res;
}

int main(int argc, char *argv[])
{
    std::string input = "take two bintang and a dance please";
    std::cout << "INPUT: " << input << "\n";
    std::cout << "RESULT: " << highestScoringWord(input) << "\n\n";
    return 0;
}