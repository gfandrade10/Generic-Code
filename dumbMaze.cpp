#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <ctime>

std::pair<int,int> move(std::pair<int,int> pair)
{
    int a = rand()%2;
    if (a) pair.second += pow(-1,rand()%2);
    else pair.first += pow(-1,rand()%2);
    return pair;
}

bool path_finder(const std::string& maze) 
{
    srand(time(NULL));
    size_t absolute = 0;
    std::string Maze = "";
    for (const auto& a:maze)
        { if(a == '.' || a == 'W') Maze += a; }
    int n = sqrt(Maze.length());
    char vec[n+2][n+2];

    for (int i = 0; i < n+2; i++)
    {
        for (int j = 0; j < n+2; j++)
        {
            if (i == 0 || j == 0 || i == n+1 || j == n+1)
                vec[i][j] = 'W';
            else
                vec[i][j] = Maze[(i-1)*n+(j-1)]; printf("%c ",vec[i][j]);
        } printf("\n");
    }
    
    std::pair<int,int> pos (1,1), buffer (1,1);
    while(1)
    {
        buffer = move(pos);
        if(vec[buffer.first][buffer.second] != 'W') pos = buffer;
        absolute++;
        if(pos.first == n && pos.second == n) return true;
        else if(absolute > 3000000) return false;
    }    
    return false;
}

int main(int argc, char* argv[])
{
    std::cout << path_finder(".W...\n.W.W.\n.W.W.\n.W.W.\n...W.") << std::endl;
    return EXIT_SUCCESS;
}