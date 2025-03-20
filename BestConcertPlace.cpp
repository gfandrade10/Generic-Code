#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <exception>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>

#define PrintDanceFloorMACRO(X) {   \
    for(const auto& it: X)          \
        std::cout << it << "\n";    \
}

//defining scoreHolder data structure
struct scoreHolder 
{
    scoreHolder()
        : x(0), y(0), score(0.0f) {}

    scoreHolder(const scoreHolder& sc)
        : x(sc.x), y(sc.y), score(sc.score) {}

    scoreHolder(scoreHolder&& sc)
        : x(std::move(sc.x)), y(std::move(sc.y)), score(std::move(sc.score)) {}

    scoreHolder(size_t X, size_t Y, float SCORE)
        : x(X), y(Y), score(SCORE) {}

    ~scoreHolder() = default;
    
    scoreHolder& operator=(const scoreHolder& sc)
    {
        this->x = sc.x;
        this->y = sc.y;
        this->score = sc.score;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& output, const scoreHolder& sc)
    {
        output << sc.x << " " << sc.y << " " << sc.score;
        return output;
    }

    size_t x;
    size_t y;
    float score;
};
//end of scoreHolder

void PrintScoreHolderArray (const std::vector<std::pair<unsigned char, scoreHolder>>& input)
{
    std::ostringstream os;
    for(const auto& it: input)
    {
        os << "(" << it.second.y << ", " << it.second.x << ")" << " - score: " << it.second.score;
        if(it.first == '*')
            os << " (Moshpit!)";
        os << "\n";
    }
    std::cout << os.str();
}

std::vector<std::string> findMoshpits(const std::vector<std::string>& dance_floor)
{
    auto danceFloor(dance_floor);
    size_t xMax = dance_floor.begin()->length();
    size_t yMax = dance_floor.size();
    auto isValidPosition = [&](int x, int y) ->bool {
        return (x >= 0 && y >= 0 && x <= ((int)xMax - 1) && y <= ((int)yMax - 1));
    };

    for(size_t y = 0; y < yMax; y++)
    {
        for(size_t x = 0; x < xMax; ++x)
        {
            if(danceFloor[y][x] == ' ')
            {
                if(isValidPosition(x+1, y) && (danceFloor[y][x+1] == ' ')
                    && isValidPosition(x, y+1) && (danceFloor[y+1][x] == ' ')
                    && isValidPosition(x+1, y+1) && (danceFloor[y+1][x+1] == ' '))
                {
                    danceFloor[y][x]     = '*';
                    danceFloor[y][x+1]   = '*';
                    danceFloor[y+1][x]   = '*';
                    danceFloor[y+1][x+1] = '*';
                }
            }
        }
    }
    
    size_t counter = 1;
    while(counter != 0)
    {
        counter = 0;
        for(size_t y = 0; y < yMax; y++)
        {
            for(size_t x = 0; x < xMax; ++x)
            {
                if(danceFloor[y][x] == ' ')
                {
                    if(isValidPosition(x+1, y) && danceFloor[y][x+1] == '*')
                    {
                        danceFloor[y][x] = '*';
                        counter++;
                    }
                    else if(isValidPosition(x, y+1) && danceFloor[y+1][x] == '*')
                    {
                        danceFloor[y][x] = '*';
                        counter++;
                    }
                }
                else if(danceFloor[y][x] == '*')
                {
                    if(isValidPosition(x+1, y) && danceFloor[y][x+1] == ' ')
                    {
                        danceFloor[y][x+1] = '*';
                        counter++;
                    }
                    else if(isValidPosition(x, y+1) && danceFloor[y+1][x] == ' ')
                    {
                        danceFloor[y+1][x] = '*';
                        counter++;
                    }
                }
            }
        }
    }
    return danceFloor;
}

inline bool customSorter(const std::pair<unsigned char, scoreHolder>& p1,
                  const std::pair<unsigned char, scoreHolder>& p2) 
{
    if(p1.first == ' ' && p2.first == '*')
        return true;
    else if(p1.first == '*' && p2.first == ' ')
        return false;
    else if((p1.first == ' ' && p2.first == ' ') || (p1.first == '*' && p2.first == '*'))
        return p1.second.score > p2.second.score;
    else return false;
}


std::pair<size_t, size_t> best_place(const std::vector<std::string>& dance_floor)
{
    if(dance_floor.empty())
        return {};

    size_t xMax = dance_floor.begin()->length();
    size_t yMax = dance_floor.size();

    std::vector<std::pair<unsigned char, scoreHolder>> placeScores;
    placeScores.reserve(xMax * yMax);

    auto isValidPosition = [&](int x, int y) ->bool {
        return (x >= 0 && y >= 0 && x <= ((int)xMax - 1) && y <= ((int)yMax - 1));
    };

    std::vector<std::string> danceFloor = findMoshpits(dance_floor);
    for(size_t y = 0; y < yMax; ++y)
    {
        for (size_t x = 0; x < xMax; ++x)
        {
            if(danceFloor[y][x] == ' ' || danceFloor[y][x] == '*')
            {
                float score = yMax - y + 0.0f;
                if(isValidPosition(x, y - 1)) //front
                {
                    char tmp = danceFloor[y-1][x];
                    if(std::isalpha(tmp))
                    {
                        float expo = static_cast<size_t>(std::toupper(tmp) - 'A') + 1.0f;
                        score *= std::pow(0.99f, expo);
                    }
                    if(tmp >= 'A' && tmp <= 'Z')
                        score *= 0.8f;
                }
                
                if(isValidPosition(x, y + 1)) //behind
                {
                    char tmp = danceFloor[y+1][x];
                    if(tmp >= 'A' && tmp <= 'Z')
                        score *= 0.8f;
                }

                if(isValidPosition(x - 1, y)) //left
                {
                    char tmp = danceFloor[y][x-1];
                    if(tmp >= 'A' && tmp <= 'Z')
                        score *= 0.8f;
                }

                if(isValidPosition(x + 1, y)) //right
                {
                    char tmp = danceFloor[y][x+1];
                    if(tmp >= 'A' && tmp <= 'Z')
                        score *= 0.8f;
                }
                placeScores.push_back(std::make_pair(danceFloor[y][x], scoreHolder(x, y, score)));
            }
        }
    }
    
    PrintDanceFloorMACRO(dance_floor);
    std::sort(placeScores.begin(), placeScores.end(), customSorter);
    puts("");
    PrintScoreHolderArray(placeScores);
    return {placeScores[0].second.y, placeScores[0].second.x};
}

int main (int argc, char *argv[]) 
{
    try
    {
        std::vector<std::string> dance_floor = {"gbvKq  JfiM I", "q jecl   fvoX", "L  Foa   ygKT"};
        auto p = best_place(dance_floor);
        std::cout << "\n(" << p.first << ", " << p.second << ")\n";
        return 0;
    }
    catch(std::exception& e)
    {
        throw std::runtime_error(e.what());
    }
}
