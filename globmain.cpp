#include <iostream>
#include <string.h>
#include <ctime>
#include <vector>

static size_t globalvec;

template<typename T>
void PrintVec(const std::vector<T>& vec)
{
    for (auto& a:vec)
        std::cout << a << "\t";
    std::cout << "\n"; 
}

template<typename T>
size_t factorial(size_t n)
{
    if (n == 1) return n;
    return n*factorial<T>(n-1);
}

void fillRandom(std::vector<size_t>& myvec)
{
    srand(time(NULL));
    for (size_t i = 0; i < globalvec; ++i)
        myvec[i] = rand()%51;
}

int main(int argc, char const *argv[])
{
    globalvec = atoi(argv[1]);
    std::vector<size_t> myvec (globalvec);
    fillRandom(myvec);
    PrintVec(myvec);
    std::cout << "\nFactorial of " << globalvec;
    std::cout <<": " << factorial<size_t>(globalvec) << std::endl;
    std::cin.get();
    return 0;
}
