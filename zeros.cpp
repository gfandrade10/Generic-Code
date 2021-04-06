#include <iostream>
#include <vector>
#include <cmath>

long zeros(long n) 
{
    long sum = n;
    long counter = 0;
    while(sum)
    {   
        sum /= 5;
        counter += sum;
    }
    return counter;
}

int main(int argc, char const *argv[])
{
    std::cout << zeros(30) << std::endl;
    return 0;
}