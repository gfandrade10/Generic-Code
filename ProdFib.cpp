#include <iostream>
#include <vector>
#include <cmath>

typedef unsigned long long ull;
class ProdFib
{
    public:
    static std::vector<ull> FibGen(const ull &prod)
    {
        std::vector<ull> res = {0,1};
        for(ull i = 1; i < prod; ++i)
        {
            res.push_back(res[i-1] + res[i]);
            if (res[i] * res[i-1] > prod)
                break;
        }
        return res;
    }

    static std::vector<ull> productFib(ull prod)
    {
        ull temp = 0;
        std::vector<ull> fib = FibGen(prod);
        bool isFib = false;
        for (auto &e: fib)
        {
            if(isFib && prod%e == 0 && temp*e == prod)
                return {temp, e , 1};
            else 
                isFib = false;
            if (e != 0 && prod%e == 0) 
            { 
                temp = e;
                isFib = true;
            }
        }
        for (ull i = 1; i < fib.size()-1; ++i)
            if (fib[i]*fib[i+1] > prod)
                return {fib[i], fib[i+1], 0};
        return {};
    }
};

int main(int argc, char* argv[])
{
    ull input = (ull)atoi(argv[1]);
    for (auto &e: ProdFib::productFib(input))
        std::cout << e << "  ";
    std::cout << "\n\n";
    return 0;
}