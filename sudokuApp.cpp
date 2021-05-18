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
       {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 
        {2, 3, 1, 5, 6, 4, 8, 9, 7}, 
        {3, 1, 2, 6, 4, 5, 9, 7, 8}, 
        {4, 5, 6, 7, 8, 9, 1, 2, 3}, 
        {5, 6, 4, 8, 9, 7, 2, 3, 1}, 
        {6, 4, 5, 9, 7, 8, 3, 1, 2}, 
        {7, 8, 9, 1, 2, 3, 4, 5, 6}, 
        {8, 9, 7, 2, 3, 1, 5, 6, 4}, 
        {9, 7, 8, 3, 1, 2, 6, 4, 5}};

    if(validSolution(example1)) std::cout << "TRUE\n";
    else std::cout << "FALSE\n";
    return 0;
}