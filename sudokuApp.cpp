#include <iostream>
#include <vector>
#include <map>

bool validSolution(unsigned int board[9][9])
{
    std::vector<std::vector<unsigned int>> blocks(9);
    for(unsigned int i = 0; i < 9; i++)
    {
        std::vector<unsigned int> buffer1, buffer2;
        for(unsigned int j = 0; j < 9; j++)
        {   
            unsigned int var = (i/3)*3 + j/3;
            blocks[var].push_back(board[i][j]);
            buffer1.push_back(board[i][j]);
            buffer2.push_back(board[j][i]);
            if(board[i][j] < 1 || board[i][j] > 9) return false;
        }   
        blocks.push_back(buffer1);
        blocks.push_back(buffer2);
    }

    for(auto& e:blocks)
    {
        std::map<unsigned int, unsigned int> Map = {};
        for(auto& v:e)
            Map[v]++;
        for(auto& m:Map)
            if(m.second > 1) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    unsigned int example1[9][9] = 
       {{8, 2, 6, 3, 4, 7, 5, 9, 1},
        {7, 3, 5, 8, 1, 9, 6, 4, 2},
        {1, 9, 4, 2, 6, 5, 8, 7, 3},
        {3, 1, 7, 5, 8, 4, 2, 6, 9},
        {6, 5, 9, 1, 7, 2, 4, 3, 8},
        {4, 8, 2, 9, 3, 6, 7, 1, 5},
        {9, 4, 8, 7, 5, 1, 3, 2, 6},
        {5, 6, 1, 4, 2, 3, 9, 8, 7},
        {2, 7, 3, 6, 9, 8, 1, 5, 4}};

    if(validSolution(example1)) std::cout << "TRUE\n";
    else std::cout << "FALSE\n";
    return 0;
}