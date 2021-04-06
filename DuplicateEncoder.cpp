#include <iostream>
#include <vector>
#include <map>

std::string duplicate_encoder(const std::string& word)
{
    std::map<char,size_t> Mymap;
    std::vector<char> vec;
    for (char b:word)
    {
        char c = tolower(b);
        if(Mymap.find(c)->first) Mymap[c]++;
        else Mymap.insert(std::pair<char,int>(c,1));
    }
    for (char b:word)
    {
        char c = tolower(b);
        if (Mymap[c] == 1) vec.push_back('(');
        else vec.push_back(')');
    }
    return std::string(vec.begin(), vec.end());
}

int main(int argc, char const *argv[])
{
    std::cout << duplicate_encoder ("recede") << std::endl;
    std::cin.get();
    return 0;
}