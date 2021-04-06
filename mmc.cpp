#include <iostream>
#include <vector>

namespace Fracts
{
    using Matrix = std::vector<std::vector<size_t> >;

    size_t MMC_2(size_t x, size_t y)
    {
        if(x == 0) return y; 
        if(y == 0) return x; 
        size_t r = 0, a, b; 
        a = (x > y) ? x : y;
        b = (x < y) ? x : y;
        r = b; 
        while(a % b != 0) 
        { 
            r = a % b; 
            a = b; 
            b = r; 
        } 
    return (x*y)/r; 
    }

    size_t MMC_N(std::vector<size_t> vec)
    {
        size_t N = vec.size(), j = 0;
        std::vector<size_t> vec2;
        if (N == 0) return 1;
        else if (N == 1) return vec[0];

        if (N>1) vec2.push_back(MMC_2(vec[0],vec[1]));
        for (int i=2; i<N; i++)
        {
            vec2.push_back(MMC_2(vec2[j],vec[i]));
            j++;
        }
        return vec2[j];
    }

    std::string convertFrac(const Matrix& lst)
    {
        std::vector<size_t> vec;
        for (size_t i=0; i<lst.size(); i++)
            vec.push_back((lst[i])[1]);

        size_t mmc = MMC_N(vec);

        std::string res;
        for (size_t i=0; i<lst.size(); i++)
            res += "(" + std::to_string(mmc/(lst[i])[1] * (lst[i])[0]) + "," + std::to_string(mmc) + ")";
        return res;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << Fracts::convertFrac({ {1, 2}, {1, 3}, {1, 4} }) << std::endl;
    std::cin.get();
    return 0;
}