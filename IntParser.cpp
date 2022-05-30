#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <algorithm>
#include <utility>

typedef std::vector< std::tuple<const char*, int, bool> > TupleVector;

static TupleVector RefMap = {
    {"one", 1, true}, {"two", 2, true}, {"three", 3, true},
    {"four", 4, true}, {"five", 5, true}, {"six", 6, true}, 
    {"seven", 7, true}, {"eight", 8, true}, {"nine", 9, true}, 
    {"ten", 10, true}, {"eleven", 11, true}, {"twelve", 12, true}, 
    {"thirteen", 13, true}, {"fourteen", 14, true}, {"fifteen", 15, true}, 
    {"sixteen", 16, true}, {"seventeen", 17, true}, {"eighteen", 18, true}, 
    {"nineteen", 19, true}, {"twenty", 20, true}, {"thirty", 30, true}, 
    {"forty", 40, true}, {"fifty", 50, true}, {"sixty", 60, true}, 
    {"seventy", 70, true}, {"eighty", 80, true}, {"ninety", 90, true}, 
    {"hundred", 100, false}, {"thousand", 1000, false}, 
    {"million", 1000000, false}, {"zero", 0, true}
};  

long parse_int(std::string number) 
{
    std::vector<long> Result;
    long Res = 0, Ref = 0;
    int count = 0;
    char input[number.length()+1];
    for(std::size_t i = 0; i < number.length(); i++)
        input[i] = number[i];
    char* Token = strtok(input, " -");
    while(Token != NULL)
    {
        for(auto& e: RefMap)
        {
            if (!strcmp(Token,std::get<0>(e)))
            {
                if(std::get<2>(e))
                    Res += std::get<1>(e);
                else if (!Ref)
                {
                    Res *= std::get<1>(e);
                    Ref = std::get<1>(e);
                    Result.push_back(Res);
                    Res = 0;
                    count++;
                }
                else if (std::get<1>(e) > Ref)
                {
                    Result[count-1] = (Result[count-1] + Res) * std::get<1>(e);
                    Res = 0;
                    Ref = std::get<1>(e);
                }
                else
                {
                    Res *= std::get<1>(e);
                    Ref = std::get<1>(e);
                    Result.push_back(Res);
                    Res = 0;
                    count++;
                }
                break;
            }
        }
        Token = strtok(NULL, " -");
    }
    for(auto& e:Result)
        Res += e;
    return Res;
}

int main(int argc, char** argv)
{
    std::string Input = "three hundred seventy six million nine hundred";
    std::cout << parse_int(Input) << "\n\n";
    return 0;
}