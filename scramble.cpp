#include <iostream>
#include <string>
#include <unordered_map>

bool scramble(const std::string& s1, const std::string& s2)
{
    std::unordered_map<char,size_t> mymap1 ,mymap2;
    for (const auto& c:s1) mymap1[c]++;
    for (const auto& c:s2) mymap2[c]++;
    for(const auto& m:mymap2)
    { if(m.second > mymap1[m.first] || mymap1[m.first] == 0) return false; }
    return true;
}

int main(int argc, char** argv)
{
    auto BoolPrint = [](const bool& flag)->void
    {if(flag) std::cout << "true"; else std::cout << "false";};

    BoolPrint(scramble("baaaaa", "aaabaa"));
    std::cout << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}