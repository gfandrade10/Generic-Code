#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

bool is_pangram(const std::string& s) 
{
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    size_t counter = 0;

    for(const auto& it: s)
    {
        auto pos = std::find(alphabet.begin(), alphabet.end(), ::tolower(it));
        if(pos != alphabet.end())
            *pos = '-';
        
        counter = std::count_if(alphabet.begin(), alphabet.end(), [](char c) {return c == '-'; });
    }

    return (counter >= 26 ? true : false);
}

int main()
{
    const std::string s1 = "The quick, brown fox jumps over the lazy dog!",
                      s2 = "1bcdefghijklmnopqrstuvwxyz";

    auto printBool = [](bool var) ->void {
        std::cout << (var ? "TRUE" : "FALSE") << "\n";
    };

    printBool(is_pangram(s1));
    printBool(is_pangram(s2));
}
