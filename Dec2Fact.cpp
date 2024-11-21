#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ranges>

class Dec2Fact
{
    public:
    static long long factorial(long long input);
    static std::string dec2FactString(long long nb);
    static long long factString2Dec(const std::string &str);
};

long long Dec2Fact::factorial(long long input)
{
    if(input == 0)
    {
        return 1;
    }
    else
    {
        return input * factorial(input - 1);
    }
}

std::string Dec2Fact::dec2FactString(long long nb)
{
    long long divisor = 1;
    std::string ans = "";

    while(nb != 0)
    {
        auto division = ::lldiv(nb, divisor++);
        nb = division.quot;
        char temp = division.rem + '0' <= '9' ? division.rem + '0' : 'A' + division.rem - 10;
        ans.push_back(temp);
    }
    std::ranges::reverse(ans);
    return ans;
}

long long Dec2Fact::factString2Dec(const std::string &str)
{
    long long len = (long long)str.length();
    long long res = 0;

    for(long long i = len - 1, j = 0; i >= 0; i--, j++)
    {
        long long temp = str[j] <= '9' ? str[j] - '0' : (long long)(str[j] - 'A') + 10;
        res += factorial(i) * temp;
    }
    return (long long)res;
}

bool CheckValidInput(int argc, char** argv, long long& input)
{
    if(argc == 2)
    {
        std::string sv(argv[1]);
        if(std::ranges::all_of(sv, ::isdigit))
        {
            input = std::stoll(sv);
            return true;
        }
        return false;
    }
    return false;
}

int main (int argc, char *argv[]) 
{
    long long input = 0;
    if(CheckValidInput(argc, argv, input))
    {
        std::string str = Dec2Fact::dec2FactString(input);
        std::cout << "Answer: " << str << "\n";
        std::cout << "Reverse: " << Dec2Fact::factString2Dec(str);
        std::cout << "\n";
        return 0;
    }
    else
    {
        std::cout << "Error, invalid input.\n";
        exit(EXIT_FAILURE);
    }
}
