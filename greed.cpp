#include <iostream>
#include <vector>
#include <unordered_map>

int score(const std::vector<int>& dice) 
{
    std::unordered_map<int, int> table;
    int result = 0;
    for (auto e:dice)
        table[e]++;

    for (const auto& e:table)
    {
        if (e.second > 2)
        {
            switch (e.first)
            {
                case 1:     { result += 1000 + (e.second-3)*100; break; }
                case 5:     { result += 500 + (e.second-3)*50; break; }
                default:    { result += 100*e.first; break; }
            }
        }
    }
    return result + table[1]*100 + table[5]*50;
}

int main(int argc, char const **argv)
{
    std::vector<int> input = {6,1,1,6,6};
    
    std::cout << "Input Values\n";
    for (auto& e : input) 
        std::cout << e << "\t";
    std::cout << "\n\nResult: " << score(input) << "\n\n";

    return EXIT_SUCCESS;
}