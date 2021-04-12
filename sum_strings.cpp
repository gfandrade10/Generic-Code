#include <iostream>
#include <string>
#include <functional>
#include <cmath>

#define Swap(x,y,T) {T buf; buf = x; x = y; y = buf;}

std::string cutZeros(std::string& S)
{   
    size_t zeroC = 0;
    for(size_t i = 0; i < S.length(); ++i)
    {
        if(S[i] == '0') zeroC++;
        else break;
    }
    return S.substr(zeroC);
}

std::string sum_strings(const std::string& a, const std::string& b) 
{
    std::string A = a, B =b , result;
    A = cutZeros(A); B = cutZeros(B);    
    if(A.length() < B.length()) Swap(A,B,std::string);   

    if(A.length() == 0 && B.length() == 0) return "0";
    else if(B.length() == 0) return A;

    auto Num = [](char c)->int {return int(c-'0');};

    auto Reverse = [=](std::string& S)->void
    {int j = S.length()-1; for(size_t i = 0; i < S.length()/2; i++)
    {Swap(S[i],S[j],char); j--;}};

    Reverse(A); Reverse(B);
    int sum, carry = 0;

    for (size_t i = 0; i<A.length(); i++)
    {
        if(i<B.length()) sum += Num(A[i]) + Num(B[i]) + carry;
        else sum = Num(A[i]) + carry;
        if(sum > 9) {carry = 1; sum -= 10; }
        else carry = 0;
        result += std::to_string(sum);
        sum = 0;
        if(i == A.length() -1 && carry == 1) {result += std::to_string(1);}
    }
    Reverse(result);
    return result;
}

int main(int argc, char **argv)
{
    std::cout << sum_strings("00155", "25") << std::endl;
    std::cin.get();
    return 0;
}