#include <iostream>
#include <vector>
#include <chrono>
#include <string.h>
#define TRUE 1

typedef std::vector<int> VectorInt;

void FindPrimes(VectorInt& vec, int NS){
    int i = 1;
    int j = 1;
    int count;
    int k;
    while(j<=NS){
        count = 0;
        for(k=1; k<=i; k++){
            if(i%k == 0)
                ++count;
        }
        if(count <= 2){
            vec.push_back(i);
            j++;
        }
        i++;
    }
}

void PrintPrimes(VectorInt vec, int NS){
    for(int i=0; i<NS; i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(int argc, char** argv)
{
    int NS = 10000;
    auto t1 = std::chrono::system_clock::now();
    std::cout<<"C++ Prime Numbers\n\n";
    std::cout<<"First "<<NS<<" prime numbers:\n";
    VectorInt MyVec;
    FindPrimes(MyVec, NS);
    //PrintPrimes(MyVec, NS);
    
    auto t2 = std::chrono::system_clock::now();
    long int millis = std::chrono::duration_cast<std::chrono::milliseconds>
        (t2-t1).count();
    
    std::cout<<"\nTotal time: "<<millis<<" ms\n\nEnd\n";

    system("pause");
    return 0;
}