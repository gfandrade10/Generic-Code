#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

typedef std::unordered_map<std::string, double> stringdblmap;
class Tour
{
    public:
    static int tour(std::vector<std::string> &arrFriends, 
    std::vector<std::vector<std::string>> &ftwns, 
    std::unordered_map<std::string, double> &h);
};

int Tour::tour(std::vector<std::string> &arrFriends, 
    std::vector<std::vector<std::string>> &ftwns, 
    std::unordered_map<std::string, double> &h)
{   
    std::vector<double> distances;
    std::vector<std::string> path;
    auto pathfinder = [&](const std::string &vs) ->void
    {
        for (const auto& e: ftwns)
        {
            if (vs == e[0])
            {
                path.push_back(e[1]);
                return;
            }
        }
    };

    for (const auto &e: arrFriends)
        pathfinder(e);

    distances.push_back(h[path[0]]);

    for (size_t i = 1; i < path.size(); ++i)
    {
        int c1 = h[path[i-1]] * h[path[i-1]];
        int c2 = h[path[i]] * h[path[i]];
        distances.push_back(std::sqrt(std::abs(c2 - c1)));
    }

    distances.push_back(h[path[path.size() - 1]]);

    double sum = 0;
    for (const auto &e: distances)
        sum += e;
        
    return static_cast<int>(sum);
}

int main(int argc, char* argv[])
{
    std::vector<std::string> friends1 = { "A1", "A2", "A3", "A4" };
    std::vector<std::vector<std::string>> fTowns1 = { {"A1", "X1"}, {"A2", "X2"}, {"A3", "X3"}, {"A4", "X4"} };
    std::unordered_map<std::string, double> distTable1 = { {"X1", 100.0}, {"X2", 200.0}, {"X3", 250.0}, {"X4", 300.0} };
    int val = Tour::tour(friends1, fTowns1, distTable1);
    std::cout << val << "\n\n";
    return 0;
}