#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#define NS 6000

typedef unsigned long long UI;
typedef std::vector<int> IntVector; //int vector
typedef std::vector<IntVector> IntMatrix; //int matrix
typedef std::vector<UI> UIntVector; //unsigned long long vector

void printMatrix(IntMatrix Matrix){
    for (int i=0; i<NS; i++){
        for(int j=0; j<NS; j++){
           std::cout<<Matrix[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }
}

void fillMatrix(IntMatrix& Matrix, IntMatrix& Sorted){
    UIntVector buffer((UI)NS*NS);
    unsigned int counter = 0;
    for (int i=0; i<NS; i++){
        for(int j=0; j<NS; j++){
            do{
                Matrix[i][j] = rand()%10;
            }while(Matrix[i][j] == 0);
            buffer[counter] = Matrix[i][j];
            counter++;
        }
    }
    counter = 0;
    std::sort(buffer.begin(),buffer.end());
    for (int i=0; i<NS; i++){
        for(int j=0; j<NS; j++){
           Sorted[i][j] = buffer[counter];
           counter++;
        }
    }
}

int main(){
    srand(time(NULL));
    IntMatrix Matrix(NS,IntVector(NS));
    IntMatrix Sorted(NS,IntVector(NS));

    std::cout<<"Original Matrix\n";
    fillMatrix(Matrix,Sorted);
    //printMatrix(Matrix);

    std::cout<<"\nSorted Matrix\n";
    //printMatrix(Sorted);

    std::cout<<"\nEnd...\n\n";

    return 0;
}