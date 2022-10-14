#include <iostream>
#include <regex>

std::string solve(std::string s)
{
    using si = std::string::iterator;
    std::regex rgx ("((\\d)|([a-z]+))");
    std::regex_token_iterator<si> it (s.begin(), s.end(), rgx);
    std::regex_token_iterator<si> end;
    std::vector<std::string> values;
    std::string res;

    for(; it != end; ++it)
        if(!(it->str()).empty())
            values.push_back(*it);
    std::reverse(values.begin(), values.end());

    for(auto &e: values)
    {
        if(!std::isdigit(e[0]))
        {
            std::reverse(e.begin(), e.end());
            res += e;
        }
        auto tmp = res;
        if(std::isdigit(e[0]))
        {   
            for (int i = 0; i < std::stoi(e)-1; ++i)
                res += tmp;
        }
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main(int argc, char *argv[])
{
    std::string input = "3(b(2(c)))";
    std::cout << solve(input) << "\n\n";
    return 0;
}