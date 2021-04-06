#include <iostream>
#include <algorithm>
#include <map>
#include <functional>

int minRemovals(const std::string& str1, const std::string& str2) 
{
    std::string S1, S2;
    auto Sort = [&](std::string& S1, std::string& S2)->void
    {if(str1.length() <= str2.length()) {S1 = str1; S2 = str2;} else {S1 = str2; S2 = str1;}};

    Sort(S1,S2);
    std::map<char, int> Map1, Map2;
    int count = 0;
    for(int i=0; i<(int)S1.length(); i++)
    {
        if((bool)Map1.find(S1[i])->first)
            Map1[S1[i]]++;
        else 
            Map1.insert(std::pair<char,int>(S1[i],1));
    }
    for(int i=0; i<(int)S2.length(); i++)
    {
        if((bool)Map2.find(S2[i])->first)
            Map2[S2[i]]++;
        else 
            Map2.insert(std::pair<char,int>(S2[i],1));
    }
    for (const auto& m:Map1)
    {
        if((bool)Map1.find(Map2[m.first])->first)
            continue;
        Map2.insert(std::pair<char,int> (m.first, m.second));
    }      
    for (auto& m:Map2)
    {
        if((bool)Map1.find(m.first)->first)
            m.second -= Map1[m.first];
        count += abs(m.second);
    }
    return count;
}

int main(int argc, char const *argv[])
{
    std::cout << minRemovals("oooooo", "pedro") << std::endl;

    std::cin.get();
    return 0;
}
