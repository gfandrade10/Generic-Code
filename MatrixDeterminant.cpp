#include <iostream>
#include <vector>

using ll = long long;
using Matrix = std::vector<std::vector<ll>>;

inline ll determinant (Matrix m)
{
    ll n = m.size();
    for (auto &e: m)
        if ((ll)e.size() != n) 
            throw std::runtime_error(std::string("Failed, matrix is not square."));
    
    if (n == 1)
        return (m[0][0]);

    else if (n == 2)
        return (m[0][0] * m[1][1] - m[1][0] * m[0][1]);

    Matrix Minor (n-1, std::vector<ll>((n-1)));
    ll row_minor, column_minor, row, column;
    ll firstrow_columnindex = 0;
    ll sum = 0;

    for(; firstrow_columnindex < n; firstrow_columnindex++) 
    {
        row_minor = 0;
        for(row = 1; row < n; row++) 
        {
            column_minor = 0;
            for(column = 0; column < n; column++) 
            {
                if (column == firstrow_columnindex)
                    continue;
                else
                    Minor[row_minor][column_minor] = m[row][column];
                column_minor++;
            }
            row_minor++;
        }
        if (firstrow_columnindex % 2 == 0)
            sum += m[0][firstrow_columnindex] * determinant(Minor);
        else
            sum -= m[0][firstrow_columnindex] * determinant(Minor);
    }
    return sum;
}

int main (int argc, char **argv)
{
    Matrix M = {{2, 5, 3}, {1, -2, -1}, {1, 3, -2}};
    std::cout << determinant(M) << "\n\n";
    return 0;
}