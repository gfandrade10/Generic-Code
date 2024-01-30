#include <climits>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <map>
#include <sstream>

std::string find_routes (const std::vector<std::pair<std::string, std::string>> &routes) 
{
    if(routes.empty())
        return {};

    using PVec = std::vector<std::pair<std::string, std::string>>;
    using PVecIterator = std::vector<std::pair<std::string, std::string>>::const_iterator;  

    std::map<std::string, int> Airports{};
    for (const auto& e: routes)
        Airports[e.first]++;

    for (const auto& e: routes)
    {
        if (Airports[e.second])
            Airports[e.second]++;
    }

    auto tmp = Airports.begin();
    int min = INT_MAX;
    for(auto it = Airports.begin(); it != Airports.end(); ++it)
    {
        if (it->second < min && it->second > 0)
        {
            min = it->second;
            tmp = it;
        }
    }

    std::string CurrentValue = tmp->first;
    std::ostringstream os;
    os << CurrentValue << ", ";

    auto pairfind = [](const PVec& values, std::string s) ->PVecIterator{
        for(auto it = values.cbegin(); it != values.cend(); ++it)
        {
            if (s == it->first)
                return it;
        }
        return values.end();
    };

    while(true)
    {
        auto tmp = pairfind(routes, CurrentValue);
        if(tmp != routes.end())
        {
            CurrentValue = tmp->second;
            os << CurrentValue;             
        }
        else
            break;

        os << ", ";
    }
    std::string final = os.str();
    return final.substr(0, final.length() - 2);
}

int main (int argc, char *argv[])
{
    std::vector<std::pair<std::string, std::string>>  in = {{"MNL", "TAG"}, {"CEB", "TAC"}, {"TAG", "CEB"}, {"TAC", "BOR"}}; 
    std::string res = find_routes(in);
    std::cout << res << "\n\n";
    return 0;
}

