#include <string>
#include <iostream>
#include <map>
#include <algorithm>

std::string missing_alphabets(const std::string &s) 
{
    std::string Ref = "abcdefghijklmnopqrstuvwxyz", Res;
    std::map<char,int> Values, Total;
    for (const auto &e: s)
        Values[e]++;
    using Pci = std::pair<char,int>;
    int NumAlphabet = std::max_element(Values.begin(), Values.end(),
        [](Pci a, Pci b) ->bool { return a.second < b.second; }) ->second;
    for (int j = 0; j < (int) Ref.length(); ++j)
            Total[Ref[j]] = NumAlphabet;
    for(auto &e: Total)
    {
        for (int i = 0; i < e.second - Values[e.first]; ++i)
            Res.push_back(e.first);
    }
    return Res;
}

int main(int argc, char *argv[])
{   
    std::string input = "codewarsz";
    std::cout << missing_alphabets (input);
    std::cout << "\n\n";
    return 0;
}