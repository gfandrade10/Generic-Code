#include <iostream>
#include <utility>
#include <vector>
#include <exception>

typedef std::size_t i32;

std::pair<i32, i32> two_sum(const std::vector<int>& numbers, int Target)
{
    try
    {
        if(numbers.empty())
            throw std::exception();

        i32 sum = 0;
        i32 target = (i32) Target;
        i32 len = numbers.size();

        for(i32 i = 0; i < len; ++i)
        {
            sum = (i32)numbers[i];                
            for (i32 j = 0; j < len; ++j)
            {
               if(j != i) 
                {
                    if(sum + (i32)numbers[j] == target)
                        return {i, j};
                }
            }
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "error, empty input!\n\n";
        return {};
    }
    return {0, 0};
}

int main (int argc, char *argv[])
{
    std::vector<int> v = {1234, 5678, 9012}; 
    int target = 14690;
    auto ans = two_sum(v, target);
    std::cout << "Pair: {" << ans.first << ", " << ans.second << "}\n\n";
    return 0;
}
