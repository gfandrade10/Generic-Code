#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>

namespace ToSmallest
{
    using LL = long long;
    size_t num_size(const LL& n)
    {
        double x = log10(n);
        if(pow(10,x) == n) return size_t(x+1);
        else return (size_t)(ceil(x));
    }

    template<typename T>
    void swap(T& a, T&b)
    {
        T buffer;
        buffer = a; a = b; b = buffer;
    }

    size_t num(const char& c)
    {
        return (size_t)(c - '0');
    }

    std::vector<LL> smallest(const LL& n)
    {
        std::vector<LL> result;
        char S[num_size(n)];
        char aux[num_size(n)];
        size_t flag;
        itoa(n, S, 10); 
        itoa(n, aux, 10);
        std::sort(aux, aux + num_size(n));
        int iter_i = -1, iter_j = -1;
        LL max = 0; 
        LL min = 10;
        for(size_t i = 1; i < num_size(n); i++)
        {
            if(num(S[i]) == 0) iter_j = i;
            else break;
        }
        if(iter_j > 0)
        {
            swap<char>(S[0],S[iter_j]);
            return {atoi(S), 0 , iter_j};
        }
        if (num(S[0]) == num(aux[0])) flag = 1;
        else flag = 0;
        for (size_t i = flag; i < num_size(n); i++)
        {
            if(num(S[i]) > max){max = num(S[i]); iter_i = i;}
            if(num(S[i]) < min){min = num(S[i]); iter_j = i;}
        }
        if(iter_i < iter_j) swap<char>(S[iter_i], S[iter_j]);
        return {atoi(S), iter_i , iter_j};
    }
}

int main(int argc, char const *argv[])
{
    for(auto& e:ToSmallest::smallest(261235))
        std::cout << e << " ";
    std::cout << std::endl;
    std::cin.get();
    return 0;
}