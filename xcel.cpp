#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <cmath>
#define SIZE 3

template <typename T>
T Random(){
    T value = (T)sqrt(rand()%10001);
    return value;
}

template <typename T>
void FillMatrix(std::vector<std::vector<int>>* input)
{
    for(int i=0; i<SIZE; i++)
    {            
        std::vector<T> buffer;
        for(int j=0; j<SIZE; j++)

            buffer.push_back(Random<T>());
        input->push_back(buffer);
    }
}

template <typename T>
void PrintMatrix(const std::vector<std::vector<int>>& input)
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
            std::cout << input[i][j] <<"\t";
        std::cout << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    std::vector<std::vector<int>>* matrix = new std::vector<std::vector<int>>;

    FillMatrix<int>(matrix);
    std::cout << "Matrix:\n\n";
    PrintMatrix<int>(*matrix);
    std::cout << std::endl;
    delete (matrix);

    std::cin.get();
    return 0;
}