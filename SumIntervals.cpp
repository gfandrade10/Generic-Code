#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

int sum_intervals(std::vector<std::pair<int, int>> intervals) 
{
    std::unordered_map<int,int> mymap;
    for(const auto& e:intervals)
    {
        for(int i = e.first; i < e.second; ++i)
            mymap[i]++;
    }
    return (int)mymap.size();
}

int main()
{
    std:: cout << sum_intervals({{1, 5}, {6, 10}}) << std::endl;
    std::cin.get();
    return 0;
}