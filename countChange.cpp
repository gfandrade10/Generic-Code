#include <iostream>
#include <vector>

unsigned long long countChange(const unsigned int money, const std::vector<unsigned int>& coins) {
    std::vector<unsigned long long> ways(money + 1, 0);
    
    // Initialization
    ways[0] = 1;
    
    for (auto &coin : coins) {
        for (int i = 0; i <= (int)money; ++i) {
            if ((int)coin <= i) {
                ways[i] += ways[i - coin];
            }
        }
    } 
    return ways[money];
}

int main()
{
    std::cout << "Answers: " << countChange(100,{1,5,10,20,50}) << std::endl;
    return 0;
}