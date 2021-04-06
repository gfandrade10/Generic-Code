#include <iostream>
#include <vector>

template <typename T>
void Swap(T& a, T& b){
    T buffer;
    buffer = a;
    a = b;
    b = buffer;
}

std::vector<std::string> leftRotations(std::string str) {
    std::vector<std::string> Result;
    Result.push_back(str);
    std::string buffer = str;
    for(int i=0; i<(int)(str.size()-1); i++){
        for(int j=(int)(str.size()-1); j>0; j--){
            Swap<char>(buffer[0], buffer[j]);
        }
        Result.push_back(buffer);
    }
	return Result;
}

std::vector<std::string> rightRotations(std::string str) {
    std::vector<std::string> Result;
    Result.push_back(str);
    std::string buffer = str;
    for(int i=0; i<(int)(str.size()-1); i++){
        for(int j=0; j<(int)(str.size()-1); j++){
            Swap<char>(buffer[(int)(str.size()-1)], buffer[j]);
        }
        Result.push_back(buffer);
    }
	return Result;
}

int main(){

    std::string input("abcde");     
    std::vector<std::string> LR = leftRotations(input);
    std::vector<std::string> RR = rightRotations(input);


    for(const auto& a:RR)
        std::cout << a << std::endl;

    std::cin.get();
    return 0;
}