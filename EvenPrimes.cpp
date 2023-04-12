#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

inline unsigned int EvenCounter(unsigned int input) noexcept
{
    auto str = std::to_string(input);
    unsigned int counter = 0;
    for (const auto &c: str)
    {
        if (c == '0' || c == '2' || c == '4' 
            || c == '6' || c == '8')
            counter++;
    }
    return counter;
}

inline bool* Primes(unsigned int n)
{
    bool *PrimeList = new bool[n];
    memset(PrimeList, true, n*sizeof(PrimeList[0]));
    for (unsigned int p = 2; p * p < n; p++)
    {
        if (PrimeList[p]) 
        {
            for (unsigned int i = p * p; i < n; i += p)
                PrimeList[i] = false;
        }
    }
    return PrimeList;
}

unsigned int EvenPrimes(unsigned int n) 
{   
    if (n == 0) 
        return 0;
    std::pair<unsigned int, unsigned int> Values = {0,0};
    bool *PrimeList = Primes(n);
    if (n%2 == 0) 
        n--;
    
    for (unsigned int i = n; i >= 2; i -= 2)
    {
        if (PrimeList[i])
        {
            auto tmp = EvenCounter(i);            
            if (tmp > Values.second)
            {
                Values.second = tmp;
                Values.first = i;
            }
        }
    }
    delete PrimeList;
    return Values.first;
}

int main(int argc, char* argv[])
{
    auto input = static_cast<unsigned int>(atoi(argv[1]));    
    std::printf("%d\n\n", EvenPrimes(input));
    return 0;
}