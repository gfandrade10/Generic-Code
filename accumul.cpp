#include <iostream>
#include <vector>
#include <string>

class Accumul
{
public:
    static std::string accum(const std::string &s);
};

std::string Accumul::accum(const std::string &s)
{
    std::vector<char> vec;
    for(size_t i=0 ; i<s.length(); i++)
    {
        for (size_t j=0; j<(i+1); j++)
        {
            if (j==0) vec.push_back(std::toupper((char)s[i]));
            else vec.push_back(std::tolower((char)s[i]));
        }
        vec.push_back('-');
    }
    return std::string(vec.begin(), vec.end()-1);
}

int main(int argc, char const *argv[])
{
    std::cout << Accumul::accum("abcdeZ") << std::endl;
    std::cin.get();
    return 0;
}