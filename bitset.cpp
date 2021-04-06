#include <iostream>
#include <cmath>
#include <string.h>

std::string multiple_of_3_regex(std::string s)
{
    if (s.length() == 0) return "true";
    size_t sum = 0, res;
    size_t N = s.length() - 1;
    for(size_t i = N; i >= 0; --i)
    {
        if(s[i] != '0' && s[i] != '1') return "false";
        res = (size_t)pow(2,abs(N-i)) * (size_t)(s[i] - '0');
        sum += res;
        if (i == 0 && sum%3 == 0) 
        {
            std::cout << "Decimal number: " << sum << std::endl;
            return "true";
        }
    }
    return "false";
}

int main(int argc, char const *argv[])
{
    std::cout << multiple_of_3_regex("101111000110000101001110") << std::endl;
    std::cin.get();
    return 0;
}