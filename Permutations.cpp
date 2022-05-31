#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <cmath>

std::string Clear(const std::string& s, const std::size_t& pos) 
{
    std::string res;
    for(std::size_t i = 0; i < s.length(); ++i)
        if(i != pos) 
            res.push_back(s[i]);
    return res;
}

std::vector<std::string> permutations(const std::string& s) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::size_t MaxCount = 100000;
    std::map<std::string, std::size_t> Results;
    
    for (std::size_t i = 0; i < MaxCount; ++i)
    {
        std::string aux(s), buffer;
        for (std::size_t j = 0; j < s.length(); ++j)
        {
            std::uniform_int_distribution<> dist(0, aux.length()-1);
            std::size_t temp = dist(gen);
            buffer.push_back(aux[temp]);
            aux = Clear(aux, temp);
        }
        Results[buffer]++;
    }
    std::vector<std::string> Ret;
    for (auto& e: Results)
            Ret.push_back(e.first);

    return Ret;
}

int main(int argc, char* argv[])
{
    std::string input(argv[1]);
    for (auto& e: permutations(input))
        std::cout << e << "\n";
    std::cout << std::endl;
    return 0;
}