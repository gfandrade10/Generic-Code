#include <iostream>
#include <map>
#include <functional>

bool sameLetterPattern(std::string str1, std::string str2) 
{
    if(str1.length() != str2.length())
        return false;

    for(int i=1; i<(int)str1.length(); i++)
    {
        if (str1[i]-str1[i-1] == 0 && str2[i]-str2[i-1] != 0)
            return false;
        if (str1[i]-str1[i-1] != 0 &&  str2[i]-str2[i-1] == 0)
            return false;
    }
    std::map<char,int> m1, m2;
    int count = 1;
    int cMap1 = 0, cMap2 = 0;
    bool flag = false;

    for(int i=0; i<(int)str1.length(); i++)
    {
        if(m1.find(str1[i])->first)
            m1[str1[i]]++;
        else 
            m1.insert(std::pair<char,int> (str1[i], 1));
        
        if(m2.find(str2[i])->first)
            m2[str2[i]]++;
        else 
            m2.insert(std::pair<char,int> (str2[i], 1));

        if (i>0)
        {
            if( (int)abs((str1[i] - str1[i-1])) == (int)abs((str2[i] - str2[i-1])) )
                count++;
        }
    }
    if(count == (int)str1.length())
        flag = true;

    if(m1.size() == m2.size())
    {
        for(const auto& m:m1)
            cMap1 += m.second;
        for(const auto& m:m2)
            cMap2 += m.second;
        if (cMap1 == cMap2)
            flag = true;
    }
    return flag;
}

int main(int argc, char const *argv[])
{
    auto Print = [](const bool& flag){if(flag) std::cout << "TRUE" << std::endl;
    else std::cout << "FALSE" << std::endl;};
    Print(sameLetterPattern("GUILHERME", "IBCDEFGHI"));

    std::cin.get();
    return 0;
}
