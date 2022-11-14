#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <regex>

std::string histogram(std::vector<int> results)
{
    std::map<int,int> values = {{1,results[0]}, {2,results[1]}, {3,results[2]},
        {4,results[3]}, {5,results[4]}, {6,results[5]}};
    
    std::string res;
    auto Max = [](const std::pair <int,int> a, const std::pair <int,int> b) ->bool
        { return a.second < b.second; };
    int max = std::max_element(std::begin(values), std::end(values), Max)->second;

    if(!results.empty() && std::accumulate(results.begin(), results.end(), 0) != 0) 
    {
        for (int i = max; i >= 0 ; --i)
        {
            std::string buffer;
            for (int j = 1; j <= 6; ++j)
            {
                if (i > values[j]) 
                    buffer += " ";
                else if (values[j] == i && values[j]) 
                    buffer += std::to_string(values[j]);
                else if (values[j])
                    buffer += "#";
                else
                    buffer += " ";
                if (i == values[j] && values[j] >= 10) 
                    continue;        
                else
                    buffer += " ";
            }
            buffer = std::regex_replace(buffer, std::regex("(\\s+)$"), "");
            res += buffer + "\n";
        }
    }
    res += "-----------\n";
    res += "1 2 3 4 5 6\n";
    return res;
}

int main(int argc, char* argv[])
{
    std::vector<int> vec = {11, 6, 5, 11, 9, 8};
    std::cout << histogram(vec) << "\n\n";
    return 0;
}