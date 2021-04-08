#include <iostream>
#include <vector>
#include <string>
#include <bitset>

long long countOnes ( size_t left, size_t right )
{
    long long counter = 0;
    for(size_t i = left; i<= right; i++)
    {
        std::bitset<32> bs(i);
        for (size_t i=0; i<sizeof(bs); i++)
        {
            if(bs[i] == 1)
                counter++;
        }  
    }
	return counter;
}

int main(int argc, char const *argv[])
{
    std::cout << countOnes(1, 3758) << std::endl;
    std::cin.get();
    return 0;
}