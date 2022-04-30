#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>

#define PRINTVEC(x) do {        \
        for(const auto &e:x)    \
        std::cout << e << "  "; \
        std::cout << std::endl; \
        } while(0)

class Kata
{
public:
    static std::vector<int> sortArray(std::vector<int> array)
    {
        if(array.empty()) return {};
        std::vector<int>  Odds;
        std::vector<int*> pos;
        for (auto &e: array)
        {
            if(e%2 != 0)
            {
                Odds.push_back(e);
                pos.push_back(&e);    
            }
        }
        std::sort(Odds.begin(),Odds.end());
        for(size_t i = 0; i < Odds.size(); ++i)
            *(pos[i]) = Odds[i];
        
        return array;
    }
};

int main()
{
    std::vector<int> input = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::cout << "Input: ";
    PRINTVEC(input);
    std::cout << "Result: ";
    PRINTVEC(Kata::sortArray(input));
    std::cout << std::endl;
    return 0;
}