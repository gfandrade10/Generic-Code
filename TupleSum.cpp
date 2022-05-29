#include <iostream>
#include <vector>
#include <tuple>
#include <typeinfo>
#include <cctype>

void Sum(double& a, double b)
{ 
    if (!isalpha(b))
        a += b; 
}

void Sum(double& a, int b)
{ 
    if (!isalpha(b))
        a += b; 
}

template<typename T>
void Sum(double a, T var)
{ }

template <std::size_t i = 0, typename... Ts> 
void Tsum(const std::tuple<Ts...>& tpl, double& sum)
{
    Sum(sum, std::get<i>(tpl));
    if constexpr (i < sizeof...(Ts) - 1)
        Tsum<i+1>(tpl, sum);
}

template <typename... Ts> 
double tuple_sum(const std::tuple<Ts...>& tpl)
{
    double sum = 0;
    Tsum(tpl, sum);
    return sum;
}

int main(int argc, char* argv[])
{
    std::vector<int> VEC = {1,2,3};
    auto T = std::make_tuple(3.14, 42, 'a', "Hello", "World", VEC);
    std::cout << tuple_sum(T) << std::endl;
    return 0;
}