#include <iostream>
#include <vector>
#include <string>
#include <functional>

class MaxDiffLength
{
public:
    static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2);
};

int MaxDiffLength::mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2)
{
    if(a1.size() == 0 || a2.size() == 0)
        return -1;
    else if( (a1.size() == 1 && a1[0] == "") || (a2.size() == 1 && a2[0] == "") )
      return -1;

    int max1 = -1; int max2 = -1;
    int min1 = 1000000; int min2 = 1000000;

    auto MinMax = [](const std::vector<std::string>& Vec, int& max, int& min)->void
    {for (const auto& m:Vec) {if((int)m.length()>max) max = (int)m.length(); 
    if((int)m.length()<min) min = (int)m.length();}};

    MinMax(a1, max1, min1);
    MinMax(a2, max2, min2);

    if(abs(max1-min2) > abs(max2-min1))
        return abs(max1-min2);
    else
        return abs(max2-min1);
}

int main()
{
    std::vector<std::string> s1, s2;

    s1 = {"hoqq", "bbllkw", "oox", "1", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"};
    s2 = {"cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"};
    std::cout << MaxDiffLength::mxdiflg(s1,s2) << std::endl;

    s1 = {"g"};
    s2 = {"3"};
    std::cout << MaxDiffLength::mxdiflg(s1,s2) << std::endl;

    std::cin.get();
    return 0;
}