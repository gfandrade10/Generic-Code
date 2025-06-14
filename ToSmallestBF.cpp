#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace ToSmallest
{
    using i64 = long long;

    struct reorderedNumber
    {
        i64 sNumber = 0;
        i64 firstIndex = 0;
        i64 secondIndex = 0;
    };
    
    static std::vector<i64> smallest(i64 n)
    {
        std::cout << "NUMBER: " << n << "\n";
        using sIt = std::string::iterator;
        
        if(n < 10)
            return {n, 0, 0};

        std::vector<reorderedNumber> possibleResults;
        std::string numberSequence {std::to_string(n)};
        i64 len = static_cast<i64>(numberSequence.length());
        {
            std::string secondCopy {numberSequence};
            if(!std::prev_permutation(secondCopy.begin(), secondCopy.end()))
                return {n, 0, 0};
        }

        auto customInsert = [&](i64 fromPos, i64 toPos) ->void 
        {
            char c = numberSequence[fromPos];
            std::string temp {numberSequence};
            sIt eraser = sIt(&temp[fromPos]);
            temp.erase(eraser);
            temp = temp.substr(0, toPos) + c + temp.substr(toPos);
            i64 buffer = std::stoll(temp);
            if(buffer < n) 
                possibleResults.push_back({buffer, fromPos, toPos});
        };

        for(i64 i = 0; i < len; i++)
        {
            for(i64 j = 0; j < len; j++)
            {
                if(j != i)
                    customInsert(j,i);
            }
        }

        auto predicate = [](reorderedNumber const& a, reorderedNumber const& b) ->bool {
            if(a.sNumber != b.sNumber) return a.sNumber < b.sNumber;
            else if(a.firstIndex != b.firstIndex) return a.firstIndex < b.firstIndex;
            else return a.secondIndex < b.secondIndex;
        };

        std::sort(possibleResults.begin(), possibleResults.end(), predicate);
        auto v = possibleResults.front();
        return {v.sNumber, v.firstIndex, v.secondIndex};
    }
}

int main(int argc, char* argv[])
{
    using namespace ToSmallest;

    if(argc == 2)
    {
        try
        {
            i64 num = std::stoll(argv[1]);
            std::vector<i64> v = smallest(num);
            
            for(auto it = v.cbegin(); it != v.cend(); ++it)
                std::cout << *it << ((it != v.cend() - 1) ? ", " : "");

            std::cout << std::endl;
        }
        catch(std::exception& e)
        {
            std::cerr << "Invalid string arguments\n";
        }
    }
    return 0;
}
