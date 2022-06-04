#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <random>
#include <algorithm>
#include <cmath>

inline bool coord (std::vector<bool>& vec, int x, int y, int& rows)
{ return vec[rows*x+y]; }

int path_finder(std::string maze) 
{
    int rows = 0, lines = 0, counter = 0;
    for(auto& e: maze)
    {
        if (e == '\n')
            break;
        rows++;
    }
    int temp = 0;
    for(auto it = maze.begin(); it != maze.end(); it++)
        if(*it == '\n') temp++;

    lines = (maze.length()-temp) / rows;
    std::vector<bool> Path;
    for(std::size_t i = 0; i < maze.length(); i++)
    {
        if(maze[i] == '.')
            Path.push_back(1);
        else if (maze[i] == 'W')
            Path.push_back(0);
    }
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::vector<int> PathCounters = {};
    bool xpos = 0, ypos = 0, xneg = 0, yneg = 0;

    for(int i = 0; i < 1000; i++)
    {
        std::uniform_int_distribution<> dist(0,1);
        int x = 0, y = 0;

        for (int j = 0; j < lines*rows; j++)
        {
            if (xpos && x < lines - 1 && coord(Path,x+1,y,rows)) 
                { x++; counter ++; goto Assign; }
            else xpos = false;

            if (ypos && y < rows - 1 && coord(Path,x,y+1,rows)) 
                { y++; counter ++; goto Assign; }
            else ypos = false;
         
            if (xneg && x > 0 && coord(Path,x-1,y,rows)) 
                { x--; counter ++; goto Assign; }
            else xneg = false;

            if (yneg && y > 0 && coord(Path,x,y-1,rows)) 
                { y--; counter ++; goto Assign; }
            else yneg = false;

            Assign:
            if (x < lines - 1 && coord(Path,x+1,y,rows) && 
                y < rows - 1 && coord(Path,x,y+1,rows))
            { 
                xpos = dist(gen);
                ypos = dist(gen);
            }
            else if(x > 0 && coord(Path,x-1,y,rows) &&
                    y > 0 && coord(Path,x,y-1,rows))
            { 
                xneg = dist(gen);
                yneg = dist(gen);
            }
            if(x > 0 && coord(Path,x-1,y,rows) &&
                    y < rows -1 && coord(Path,x,y+1,rows))
            { 
                xneg = dist(gen);
                ypos = dist(gen);
            }
            else if(x < lines -1 && coord(Path,x+1,y,rows) &&
                    y > 0 && coord(Path,x,y-1,rows))
            { 
                xpos = dist(gen);
                yneg = dist(gen);
            }
            if(!yneg && y < rows - 1 && coord(Path,x,y+1,rows)) ypos = true;
            else if(!xpos && x > 0 && coord(Path,x-1,y,rows)) xneg = true;
            else if(!ypos && y > 0 && coord(Path,x,y-1,rows)) yneg = true;
            else if(!xneg && x < lines - 1 && coord(Path,x+1,y,rows)) xpos = true;
            if (x == lines-1 && y == rows-1)
            {
                PathCounters.push_back(counter);
                counter = 0;
                break;
            }
        }    
    }
    if(!PathCounters.empty()) 
        return *std::min_element(PathCounters.begin(), PathCounters.end());
    else 
        return -1;
}

int main(int argc, char **argv)
{
    std::string input = "..W..\n.....\n.W...\n.....\n.W.W.";
    std::cout << input << "\n" << path_finder(input) << "\n\n";
    return 0;
}