#include <map>
#include <iostream>
#include <cstring>

static std::map<std::string, std::string> MyMap = {
    {".-", "A"}, {"-...","B"}, {"-.-.","C"}, {"-..","D"},
    {".", "E"}, { "..-.","F"}, {"--.","G"}, {"....","H"},
    {"..", "I"}, {".---","J"}, {"-.-","K"}, {".-..","L"},
    {"--", "M"},   {"-.","N"}, {"---","O"}, {".--.","P"},
    {"--.-", "Q"},   {".-.","R"}, {"...","S"}, {"-","T"},
    {"..-", "U"},{"...-","V"}, {".--","W"}, {"-..-","X"},
    {"-.--", "Y"}, {"--..","Z"}, {"X"," "}, {"-.-.--", "!"},
    {".-.-.-", "."}, {"...---...", "SOS"}
};

char *StrToChar(const std::string& morseCode) 
{
    char *code = new char[morseCode.length()+1];
    std::size_t j = 0;
    bool extraZeros = true;
    for (std::size_t i = 0; i < morseCode.length(); ++i)
    {
        if (extraZeros && morseCode[i] == ' ')
            continue;
        else
            extraZeros = false;
        if (!extraZeros && i > 0 && i < morseCode.length()-1 
        && morseCode[i-1] == ' ' && morseCode[i+1] == ' ' && 
        morseCode[i] == ' ')
        {
            code[j] = 'X';
            ++j;
        }
        else
        {
            code[j] = morseCode[i];
            ++j;
        }   
    }
    code[j] = '\0';
    return code;
}

std::string decodeMorse(std::string morseCode) 
{
    if (morseCode.empty()) return "";

    char *code = StrToChar (morseCode);
    char *p = strtok(code, " ");
    std::string res = "";

    while(p != NULL)
    {
       if (p != NULL)
            res += MyMap[p];
        p = strtok(NULL, " ");
    }
    delete[] code;
    return res;
}

int main(int argc, char* argv[])
{
    std::string input = ".... . -.--   .--- ..- -.. .";
    std::cout << decodeMorse(input) << "\n\n";
    return 0;
}