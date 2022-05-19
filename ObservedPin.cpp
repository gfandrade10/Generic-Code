#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <map>
#include <cmath>

static std::map<int,std::vector<int>> RefMap = {
    {1,{1,2,4}},
    {2,{1,2,3,5}},
    {3,{2,3,6}},
    {4,{1,4,5,7}},
    {5,{2,4,5,6,8}},
    {6,{3,5,6,9}},
    {7,{4,7,8}},
    {8,{0,5,7,8,9}},
    {9,{6,8,9}},
    {0,{0,8}},
};

std::vector<std::string> get_pins(std::string observed) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::map<std::string,int> MyMap;
    size_t range = 2000 | 2*(size_t)pow(10, observed.length()-1);

    for(size_t j = 0; j < range; ++j)
    {
        std::string res = "";
        for(size_t i = 0; i < observed.length(); ++i)
        {
            size_t pos = (int)(observed[i] - '0');        
            std::uniform_int_distribution<> dist(0, RefMap[pos].size()-1);
            std::string buffer = std::to_string( RefMap[pos][dist(gen)] );
            res += buffer;
        }
        MyMap[res]++;
    }

    std::vector<std::string> result;
    for (auto&& e: MyMap)
        result.push_back(e.first);

    return result;
}

int main (int argc, char* argv[])
{
    std::string input(argv[1]);
    std::vector<std::string> res = get_pins(input);
    for(auto&& e: res)
        std::cout << e << "  ";
    std::cout << "\n\n";
    return 0;
}