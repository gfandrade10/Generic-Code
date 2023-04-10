#include <string>
#include <iostream>
#include <cmath>

std::string incrementString(const std::string &str)
{
    if (str.empty())
        return "1";
    std::string::const_iterator it = str.end();
    while(isdigit(*(--it)))
        continue;
    it++;
    if (it != str.end())
    {
        std::string num = str.substr(it-str.begin());
        size_t N = std::stoul(num)+1;
        bool all_zeroes = (N-1 == 0);
        if (*it == '0')
        {
            while(*(++it) == '0' && it != str.end())
                continue;
            --it;
            if (all_zeroes)
                return str.substr(0, it-str.begin()) + "1";
            num = str.substr(it-str.begin());
            bool flag = ((size_t)log10(N)) + 1 == num.length();
            if(!flag)
                ++it;
        } 
        return str.substr(0, it-str.begin()) + std::to_string(N);
    }    
    else
        return str + "1";
}

int main(int argc, char *argv[])
{
    std::string input (argv[1]);
    std::cout << incrementString(input) << "\n\n";
    return 0;
}