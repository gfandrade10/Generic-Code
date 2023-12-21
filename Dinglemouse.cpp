#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <sstream>

static std::vector<std::tuple<const char*, int, bool>> RefMap = {
    {"one", 1, true}, {"two", 2, true}, {"three", 3, true},
    {"four", 4, true}, {"five", 5, true}, {"six", 6, true}, 
    {"seven", 7, true}, {"eight", 8, true}, {"nine", 9, true}, 
    {"ten", 10, true}, {"eleven", 11, true}, {"twelve", 12, true}, 
    {"thirteen", 13, true}, {"fourteen", 14, true}, {"fifteen", 15, true}, 
    {"sixteen", 16, true}, {"seventeen", 17, true}, {"eighteen", 18, true}, 
    {"nineteen", 19, true}, {"twenty", 20, true}, {"thirty", 30, true}, 
    {"forty", 40, true}, {"fifty", 50, true}, {"sixty", 60, true}, 
    {"seventy", 70, true}, {"eighty", 80, true}, {"ninety", 90, true}, 
    {"hundred", 100, false}, {"zero", 0, true}
};   

class Dinglemouse
{
    public:
    static std::string ParseInt(int number)
    {
        if (number == 100)
            return "one hundred";

        std::ostringstream os;      

        DontDoThis:
        for (const auto& it:RefMap)
        {
            if(std::get<1>(it) == number)
            {
                os << std::get<0>(it);
                return os.str();
            }
        }
        
        if(number > 19 && number <100)
        {
            auto str = std::to_string(number);  
            int n1 = 10 * static_cast<int>(str[0] - '0');
            int n2 = static_cast<int>(str[1] - '0');

            for(const auto& it:RefMap)
            {
                if(std::get<1>(it) == n1)
                {
                    os << std::get<0>(it) << " ";
                    break;
                }
            }

            for(const auto& it:RefMap)
            {
                if(std::get<1>(it) == n2)
                {
                    os << std::get<0>(it);
                    return os.str();
                }
            }
        }
        else
        {
            auto str = std::to_string(number);  
            int n3 = static_cast<int>(str[0] - '0');
            for(const auto& it:RefMap)
            {
                if(std::get<1>(it) == n3)
                {
                    os << std::get<0>(it) << " hundred ";
                    break;
                }
            }
            number = number - (n3 * 100);
            if (number != 0)
                goto DontDoThis;
        }
        return os.str();
    }

    static int ParseString(std::string number) 
    {
        std::vector<long> Result;
        long Res = 0, Ref = 0;
        int count = 0;
        char input[number.length()+1];
        std::memcpy(input, &number[0], number.length());
        input[number.length()] = '\0';
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

    static std::vector<int> sort(const std::vector<int> &array)
    {
        std::vector<std::string> Buffer(array.size());
        std::vector<int> Ans(array.size());
        for (int i = 0; i < (int)array.size(); ++i)
            Buffer[i] = ParseInt(array[i]);
        
        std::sort(Buffer.begin(), Buffer.end());
        for (int i = 0; i < (int)array.size(); ++i)
            Ans[i] = ParseString(Buffer[i]);

        return Ans;
    }
};

int main(int argc, char **argv)
{
    std::vector<int> v = {1, 2, 3, 4};
    auto v2 = Dinglemouse::sort(v);
    for (const auto& it : v2)
        std::cout << it << "  ";
    std::cout << "\n\n";
    return 0;
}