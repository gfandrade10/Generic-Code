#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> solveEq(int eq[3][4])
{
    float mat [3][3];
    float Equal [3];
    float buff[3][3];
    float Inv[3][3];
    for(int i = 0; i <3; i++)
    {
        for(int j = 0; j < 3; j++)
            mat[i][j] = eq[i][j];
        Equal[i] = eq[i][3];
    }

    long det = 0;
    for(size_t i = 0; i <3; ++i)
        det += (mat[0][i]*(mat[1][(i+1)%3]*mat[2][(i+2)%3] - mat[1][(i+2)%3]*mat[2][(i+1)%3]));
    if(det == 0) throw std::runtime_error("No real solutions\n");
    
    float res[3];
    std::vector<int> result;
    for(int i = 0; i <3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            buff[i][j] = ((mat[(i+1)%3][(j+1)%3] * mat[(i+2)%3][(j+2)%3]) -
            (mat[(i+1)%3][(j+2)%3]*mat[(i+2)%3][(j+1)%3]))/det;
        }
    }
    for(int i = 0; i <3; i++)
    {
        for(int j = 0; j < 3; j++)
            Inv[j][i] = buff[i][j];
    }
    for(int i = 0; i <3; i++)
    {
        res[i] = 0;
        for(int j = 0; j < 3; j++)
            res[i] += Inv[i][j] * Equal[j];
        result.push_back(round(res[i]));
    }
    return result;
}

int main()
{
    std::vector<int> solution;
    int eq[3][4] = {{2, 1, 3, 10}, {-3, -2, 7, 5}, {3, 3, -4, 7}};
    solution = solveEq(eq);
    for(size_t i = 0; i<3; ++i)
        std::cout << "X[" << i+1 << "]: " << solution[i] << std::endl;
    std::cin.get();
    return 0;
}