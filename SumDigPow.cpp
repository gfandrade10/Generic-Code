#include <vector>
#include <iostream>
#include <string>
#include <cmath>

std::vector<unsigned int> sumDigPow(unsigned int a, unsigned int b)
{
    std::vector<unsigned int> res;
    for (unsigned int i = a; i <= b; ++i)
    {
        if(i < 10)
            res.push_back(i);
        else
        {
            std::string tmp = std::to_string(i);
            unsigned int sum = 0;
            for (unsigned int j = 0; j < tmp.length(); ++j)
                sum += std::pow(static_cast<int>(tmp[j] - '0'), j+1);
            if (sum == i)
                res.push_back(i);
        }
    }
    return res;
}

template <typename T>
void PrintVector(const std::vector<T>& vec)
{
    for (const auto& v: vec)
        std::cout << v << "   ";
    std::cout << "\n\n";
}

int main (int argc, char *argv[])
{   
    auto vec = sumDigPow(1, 100);
    PrintVector(vec);
    return 0;
}
