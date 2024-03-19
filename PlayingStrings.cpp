#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

namespace PlayingOnStrings
{
    inline char SwapCase(char c) noexcept
    {
        if(std::isalpha(c))
        {
            if(c >= 'a')
                return std::toupper(c);
            else
                return std::tolower(c);
        }
        else
            return c;
    }

    std::unordered_map<char, size_t> KeyMapping(const std::string& str)
    {   
        std::unordered_map<char, size_t> res;
        for(const auto& e: str)
            res[std::tolower(e)]++;
        return res;
    }

    std::string WorkingOnStrings(const std::string &a, const std::string &b)
    {
        auto MapA = KeyMapping(a);
        auto MapB = KeyMapping(b);

        std::string NewA{a};
        std::string NewB{b};

        for(auto& e: NewA)
        {
            char tmp = std::tolower(e);
            if(MapB[tmp] && MapB[tmp] % 2 != 0)
                e = SwapCase(e);
        }

        for(auto& e: NewB)
        {
            char tmp = std::tolower(e);
            if(MapA[tmp] && MapA[tmp] % 2 != 0)
                e = SwapCase(e);
        }
        return NewA + NewB;
    }
}

int main (int argc, char *argv[])
{
    std::string a = "abc";
    std::string b = "cde";
    std::string c = PlayingOnStrings::WorkingOnStrings(a,b);
    std::cout << c << "\n\n";
    return 0;
}
