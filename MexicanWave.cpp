#include <iostream>
#include <vector>
#include <cctype>

std::vector<std::string> wave(std::string y)
{
    std::vector<std::string> res;

    for (size_t i = 0; i < y.length(); ++i)
    {
        std::string temp = y;
        if (isalpha(y[i]))
        {
            temp[i] = toupper(y[i]);
            res.push_back(temp);
        }
    }
    return res;
}

int main(int argc, char **argv)
{
    std::string input = "hello";
    for (auto& e:wave(input))
        std::cout << e << "\n";
    std::cout << std::endl;
    return 0;
}