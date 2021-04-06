#include <iostream>
#include <vector>

namespace SumFctions
{
    using ull = unsigned long long;

    ull perimeter(int n)
    {
        ull per = 0;
        std::vector<size_t> fibo;
        for (int i = 0; i < n+1; i++)
        {
            if (i < 2) fibo.push_back(1);
            else fibo.push_back(fibo[i-2] + fibo[i-1]);
            std::cout << fibo[i] << std::endl;
            per += fibo[i] * 4;
        }
        return per;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << SumFctions::perimeter(5) << std::endl;

    std::cin.get();
    return 0;
}