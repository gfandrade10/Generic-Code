#include <vector>
#include <iostream>
#include <functional>

using matrix = std::vector<std::vector<int>>;
matrix create_spiral(int n)
{
    int mat[n][n];
    matrix result;
    std::vector<int> myvec(n*n);
    int i = 0, j = 0, s = 0, INDEX = 0;
    int k = 0;
    
    auto SIndex = [&]()->void
    {INDEX++; if(s == 0 && INDEX == 3) {s++; INDEX = 0;} 
    else if(INDEX == 4) {s++; INDEX = 0;} if(n%2 == 0 && s >= n/2) s--;};

    while(k < (n*n))
    {
        while(j < (n-s))
        {
            if(k == (n*n)) break;
            myvec[k] = k+1;
            mat[i][j] = myvec[k];
            j++; k++;
        }
        j--; i++;
        SIndex();
        while(i < (n-s))
        {
            if(k == (n*n)) break;
            myvec[k] = k+1;
            mat[i][j] = myvec[k];
            i++; k++;
        }
        i--; j--;
        SIndex();
        while(j > (s-1))
        {
            if(k == (n*n)) break;
            myvec[k] = k+1;
            mat[i][j] = myvec[k];
            j--; k++;
        }
        j++; i--;
        SIndex();
        while(i > (s-1))
        {
            if(k == (n*n)) break;
            myvec[k] = k+1;
            mat[i][j] = myvec[k];
            i--; k++; 
        }
        i++; j++;
        SIndex();
    }
    for (i = 0; i < n; i++)
    {
        std::vector<int> buffer;
        for (j = 0; j < n ; j++)
            buffer.push_back(mat[i][j]);
        result.push_back(buffer);
    }
    return result;
}

void print_matrix(const matrix& mat)
{
    for (size_t i = 0; i < mat.size(); ++i)
    {
        for(const auto& m:mat[i])
            std::cout << m << "\t";
        std::cout << std::endl;
    }
}

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    print_matrix(create_spiral(n));
    std::cin.get();
    return EXIT_SUCCESS;
}