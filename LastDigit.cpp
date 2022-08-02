#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

int last_digit(const std::string &s1, const std::string &s2) 
{
    int num = s1[s1.length() - 1] - '0';

    if (s2 == "0")
        return 1;
    if (num == 0 || num == 1 || num == 5 || num == 6) 
        return num;
    if (s2.length() == 1)
    {
        auto tmp = std::to_string((int)std::pow(num, std::stoi(s2)));
        return tmp[tmp.length() - 1] - '0';
    }
        
    auto id = [](const int &s) -> int { 
    std::string t = std::to_string(s); return t[t.length() - 1] - '0'; };

    std::vector<int> list;
    int val = num;
    while(1)
    { 
        bool flag = true;
        int temp = list.size();
        int value = id(val);
        for (auto& e:list)
            if(e == value) flag = false;
        if (flag) list.push_back(value);
        if(temp == list.size()) break;
        val *= num;
    }

    int exp = std::stoi(s2.substr(s2.length()-2));
    if (exp % (int) list.size() == 0) return *(--list.end());
    auto it = list.begin();
    std::advance(it, (exp % (int) list.size()) - 1);
    return *it;
}

int main (int argc, char *argv[])
{
    std::cout << last_digit("7", "59") << "\n\n";
    return 0;
}