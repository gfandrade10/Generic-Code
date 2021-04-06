#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#define NS 1000000000

std::random_device device;
std::mt19937_64 generator(device());

void Benchmark(std::vector<int>& Arr){
    auto t1 = std::chrono::system_clock::now();
    printf("C++ Random Vector - %dM numbers\n\n", NS/1000000);
    std::uniform_int_distribution<int> distribution(1,NS);
    for(int i=0; i<NS; i++){
        Arr.push_back(reinterpret_cast<int>(distribution(generator)));
    }
    std::sort(Arr.begin(), Arr.end());
    auto t2 = std::chrono::system_clock::now();
    float millis = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();           
    printf("Total time: %.2fs\n\nEnd\n", millis/1000);
    std::cin.get();
}

int main(){
    std::vector<int> Arr;
    Benchmark(Arr);
    return 0;
}




