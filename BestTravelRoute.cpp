#include <iostream>
#include <map>
#include <random>
#include <set>
#include <vector>

namespace BestTravel
{
    size_t Factorial(int x)
    {
        size_t fact = x;
        while(--x)
            fact *= x;
        return fact;
    }

    size_t Combination(int c, int size)
    {
        size_t comb = size;
        size_t iter = size;
        while(--iter > (size_t)(size - c))
            comb *= iter;
        
        return comb / Factorial(c);
    }

    int chooseBestSum(int t, int k, const std::vector<int> &ls)
    {
        size_t size = ls.size();
        int maxValue = Combination(k, size);
        std::map<std::set<int>, int> combinationSet;
        std::random_device rd;
        std::mt19937 seed(rd());
        std::uniform_int_distribution<> gen(0, size - 1);
       
        int counter = 0;
        while (combinationSet.size() < (size_t)maxValue)
        {
            std::set<int> tempSet;
            while(tempSet.size() < (size_t)k)
                tempSet.insert(gen(seed));

            int sum = 0;
            for(const auto& it: tempSet)
                sum += ls[it];
            
            if(combinationSet.find(tempSet) == combinationSet.end())
                combinationSet.insert({tempSet, sum});

            if(counter == (maxValue * maxValue))
                break;
            
            counter++;
        }

        auto maxSum = [t](const std::map<std::set<int>, int>& s) ->int {
            int sum = 0;
            for(const auto& it: s)
            {
                if(it.second > sum && it.second <= t)
                    sum = it.second;
            }
            return sum;
        };
        
        int returnSum = 0;
        if(!combinationSet.empty())
            returnSum = maxSum(combinationSet);
        
        if(returnSum != 0) return returnSum;
        else return -1;
    }
};

int main()
{
    const std::vector<int> list = {50, 55, 57, 58, 60};
    std::cout << BestTravel::chooseBestSum(163, 3, list) << std::endl;
    return 0;
}
