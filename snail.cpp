#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

typedef std::vector<std::vector<int>> matrix;

std::vector<int> snail(const matrix& snail_map) 
{
    std::size_t n = snail_map[0].size();
    if (n == 0) return {};
    else if (snail_map.size() != n) return {};

    std::vector<int> res;
    bool xflag = true, yflag = true, fcycle = true;
    int xb = 0, yb = 0;
    std::size_t i = 0, j = 0, ct = 0;

    while(ct < n*n)
    {
        // right -->
        if (xflag && yflag)
        {
            if (!fcycle) j++;
            if (ct < n*n) res.push_back(snail_map[i][j]);
            if(fcycle) j++;
            ct++;
        }
        if (xflag && j == n - 1 - xb)
        {
            xflag = false;
        }

        // down V
        if (!xflag && yflag)
        {
            if(fcycle)
            {
                fcycle = false;
                if (ct < n*n) res.push_back(snail_map[i][j]);
                ct++;
            }
            i++;
            if (ct < n*n) res.push_back(snail_map[i][j]);
            ct++;
        }
        if (yflag && i == n - 1 - yb)
        {
            yflag = false;
            yb++;
        }

        // left <--
        if (!xflag && !yflag)
        {
            j--;
            if (ct < n*n) res.push_back(snail_map[i][j]);
            ct++;
        }
        if (!xflag && j == 0 + xb)
        {
            xflag = true;
            xb++;
        }

        // up ^
        if (xflag && !yflag)
        {
            i--;
            if (ct < n*n) res.push_back(snail_map[i][j]);
            ct++;
        }
        if (!yflag && i == 0 + yb)
        {
            yflag = true;
        }
    }
    return res;
}

int main(int argc, char **argv)
{
    matrix v = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
    for (auto e: snail(v))
        std::cout << e << "  ";
    std::cout << "\n\n";
    return 0;
}