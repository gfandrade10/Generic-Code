#include <iostream>
#include <algorithm>
#include <array>
#include <chrono>
#include <random>
#define Ns 6

typedef std::array<int,Ns> Array;
std::random_device device;
std::mt19937_64 generator(device());

void fill_vector(Array& Arr){
    int count;
    for (int i =0; i<Ns; i++){
            do{
                count = 0;
                std::uniform_int_distribution<int> distribution(1,60);
                Arr[i] = reinterpret_cast<int>(distribution(generator));
                if (i>0){
                    for (int k=0; k<i; k++){
                        if(Arr[i] == Arr[k]){
                            count++;
                        }
                    }
                }
            } while (Arr[i] == 0 || count != 0);
        }
     std::sort(Arr.begin(), Arr.end());
}

void print_vector(Array Arr){
    for (int i=0; i<Ns; i++){
        std::cout<<Arr[i]<<" ";
    }
    std::cout<<std::endl;
}

void second_vector(Array& Arr, Array& Arr2, long int& cycles){
    int count;
    for(int i=0; i<Ns; i++){
        Arr2[i] = Arr[i];
    }
    cycles = 0;
    
    do{
        cycles++;
        count = 0;
        fill_vector(Arr);
        for(int i=0; i<Ns; i++){
            if(Arr[i] == Arr2[i]){
                count++;
            }
        }
    } while(count != Ns);
    std::cout<<"\nTotal inner loops: "<<cycles;
    std::cout<<std::endl;
    print_vector(Arr);
} 

int main(){
    auto t1 = std::chrono::system_clock::now();
    std::cout<<"C++ Implementation\n";
    Array Arr, Arr2;
    long int cycles;
    
    fill_vector(Arr);
    print_vector(Arr);
    std::cout<<"\n";
    second_vector(Arr,Arr2,cycles);
    
    auto t2 = std::chrono::system_clock::now();
    long int millis = std::chrono::duration_cast<std::chrono::milliseconds>
        (t2-t1).count();
        
    std::cout<<"Total time: "<<millis<<" ms\n";
    std::cout<<"Loops per ms: "<<(int)cycles/millis;
    std::cout<<"\n\nEnd\n";
    
    return 0;
}