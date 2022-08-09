#include <iostream>
#include <string>
#include <cmath>
#include <map>

std::string solution(int number)
{
    std::map<int,std::string> RefValues = {
        {1,"I"}, {2,"II"}, {3,"III"}, {4,"IV"}, {5,"V"},
        {6,"VI"}, {7,"VII"}, {8,"VIII"}, {9,"IX"}, {10,"X"},
        {20,"XX"}, {30,"XXX"}, {40,"XL"}, {50,"L"}, {60,"LX"},
        {70,"LXX"}, {80,"LXXX"}, {90,"XC"}, {100,"C"}, {200,"CC"},
        {300,"CCC"}, {400,"CD"}, {500,"D"}, {600,"DC"}, {700,"DCC"},
        {800,"DCCC"}, {900,"CM"}, {1000,"M"}, {2000,"MM"}, {3000,"MMM"}
    };
    if (number <= 10) return RefValues[number];

    std::string s, buffer = std::to_string(number);
    int j = 0;  
    for(int i = std::log10(number); i >=0; --i)
        s += RefValues[(buffer[j++] - '0') * std::pow(10,i)];
                   
    return s;
}

int main(int argc, char* argv[])
{
    int val = (int) atoi(argv[1]);
    std::cout << solution(val) << "\n\n";
    return 0;
}