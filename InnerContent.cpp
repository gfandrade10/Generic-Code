#include <iostream>
#include <regex>
#include <algorithm>

std::string sortTheInnerContent (std::string words)
{
    using si = std::string::iterator;
    std::regex rgx ("(\\s)|(\\w+)");
    std::string res;
    std::regex_token_iterator<si> rend;
    std::regex_token_iterator<si> it (words.begin(), words.end(), rgx);
    auto func = [](char a, char b) ->bool { return a > b; };

    for (; it != rend; ++it)
    {
        std::string buffer = *it;
        if (buffer.length() > 3)
        {
            auto init = ++buffer.begin();
            auto end = (si) &buffer[buffer.length() - 1];
            std::sort (init, end, func);
        }
        res += buffer;
    }
    return res;
}

int main (int argc, char* argv[])
{
    std::string input = "this kata is easy";
    std::cout << sortTheInnerContent(input) << "\n\n";
    return 0;
}