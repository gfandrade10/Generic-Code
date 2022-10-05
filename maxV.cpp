#include <iostream>
#include <vector>
#include <utility>

template <typename T>
constexpr void Eval ()
{ }

template <typename T>
constexpr void Eval (T &&arg, T &max)
{
    if (arg > max)
        max = arg;
}

template <typename T, T ...Values>
constexpr T vs() 
{
    T max = -5000000;
    int vec[] = {0, ((void) Eval(std::forward<T>(Values),max),0)...};
    return max;
};

int main (int argc, char *argv[])
{
    std::cout << vs<unsigned int, 346, 34, 21, 4294967295>() << "\n\n";
    return 0;
}