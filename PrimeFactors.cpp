#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <functional>

class PrimeDecomp
{
    public:
        static std::string factors(int lst);
        static std::vector<int>GetPrimes(int lst);
};

std::vector<int> PrimeDecomp::GetPrimes(int lst)
{  
    std::vector<int> result = {2,3};
    for(int i = 5; i < sqrt(lst)+1; i = i+2)
    {
        int count = 0;
        for(int j = 3; j < i; j = j+2)
            if(i%j == 0) count++;
        if(count == 0 && lst%i == 0) result.push_back(i);
    }
    result.push_back(lst);
    return result;
}

std::string PrimeDecomp::factors(int lst)
{
    int buffer = lst;
    std::map<int,int> MyMap;
    std::vector<int> _PRIMES = GetPrimes(lst);
    for (const auto &e: _PRIMES)
    {
        while(buffer%e == 0)
        {
            buffer = buffer/e;
            MyMap[e]++;
        }
    }
    buffer = lst;
    for (const auto &e:MyMap)
    {
        while(buffer%e.first == 0)
            buffer = buffer/e.first;
    }
    if(buffer != 1) MyMap[buffer]++;
    std::string res = "";
    for (const auto &e: MyMap)
    {
        res += "(";
        if (e.second > 1) 
            res += std::to_string(e.first) + "**" + std::to_string(e.second) + ")";
        else
            res += std::to_string(e.first) + ")";
    }
    return res;
}

int main (int argc, char **argv)
{
    int arg = atoi(argv[1]);
    std::string res = PrimeDecomp::factors(arg);
    std::cout << res << "\n\n";
    return 0;
}