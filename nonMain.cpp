#include <iostream>
#include <string.h>

#define LinearIndex(i,j,Col) (Col*i + j)

void FillMatrix(int* Matrix, int SIZE_MAT){
    for(int i=0; i<(SIZE_MAT); i++){
        for(int j=0; j<(SIZE_MAT); j++){
            Matrix[LinearIndex(i,j,SIZE_MAT)] = LinearIndex(i,j,SIZE_MAT) + 1;
        }
    }
}

void PrintMatrix(const int* Matrix, int SIZE_MAT)
{
    for(int i=0; i<(SIZE_MAT); i++){
        for(int j=0; j<(SIZE_MAT); j++){
            std::cout << Matrix[LinearIndex(i,j,SIZE_MAT)] << "\t";
        }
        std::cout << "\n";
    }
}

int main(int argc, char** argv)
{
    int SIZE_MAT = atoi(argv[1]);
    int* Matrix;
    Matrix = new int[SIZE_MAT*SIZE_MAT];
    FillMatrix(Matrix, SIZE_MAT);
    PrintMatrix(Matrix, SIZE_MAT);

    delete[] Matrix;
    std::cin.get();
    return 0;
}