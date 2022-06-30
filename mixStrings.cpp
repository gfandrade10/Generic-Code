#include <iostream>
#include <map>
#include <cctype>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

class Mix
{   
    using String = std::string;
    using PairVector = std::vector<std::pair<char,std::size_t>>;
    using Pair = std::pair<char,std::size_t>;
    using PVit = PairVector::iterator;

    public:
    static inline void Insert (PairVector& Letters, char input)
    {
        if(isalpha(input) && input >= 'a')
        {
            bool adder = true;
            for (auto it = Letters.begin(); it != Letters.end(); ++it)
            {
                if (it->first == input)
                {
                    (it->second)++;
                    adder = false;
                }
            }
            if (adder) Letters.push_back({input, 1});
        }
    }

    static inline String Expand(Pair& p1)
    {
        char res[p1.second+1];
        for(std::size_t i = 0; i < p1.second; ++i)
            res[i] = p1.first;
        res[p1.second] = '\0';
        return String(res);
    }

    static String mix(const String &s1, const String &s2)
    {
        PairVector V1, V2;    
        for(auto e:s1) Insert (V1,e);
        for(auto e:s2) Insert (V2,e);

        String res = "";
        for(auto it = V1.begin(); it != V1.end(); it++)
        {
            for(auto it2 = V2.begin(); it2 != V2.end(); ++it2)
            {
                if(it->first == it2->first && it->second > it2->second)
                    { V2.erase(it2); break; }
                else if (it->first == it2->first && it->second < it2->second)
                    { it->second = 1; break; }
            }
        }
        std::map<std::string, std::size_t> Values;
        for(auto& e: V1) 
            if(e.second > 1) Values[std::to_string(1) + ":" + Expand(e)];
        for(auto& e: V2) 
            if(e.second > 1) Values[std::to_string(2) + ":" + Expand(e)];

        using PS = std::pair<std::string,std::string>;
        std::vector<PS> final;

        auto comp = [](PS s1, PS s2) -> bool
        { if(s1.second.length() == s2.second.length() && s1.first == s2.first)
            return s1.second < s2.second;
        else if (s1.second.length() == s2.second.length()) return s1.first < s2.first;
        else return s1.second.length() > s2.second.length(); };

        for (auto& e: Values) final.push_back({e.first.substr(0,1), e.first.substr(1)});
        for (auto &e: final)
        {
            using psi = std::vector<PS>::iterator;
            for(auto it = std::next((psi)&e); it != final.end(); it++)
            {
                if (e.second == it->second)
                {
                    e.first = '=';
                    it->first = '?'; it->second = "";
                }
            }
        }
        std::sort(final.begin(), final.end(), comp);
        for(auto& e: final)
            if(!e.second.empty())
                res += e.first + e.second + "/";

        return res.substr(0, res.length() - 1);
    }
};

int main(int argc, char *argv[])
{
    std::string res = Mix::mix("looping is fun but dangerous", "less dangerous than coding");
    std::cout << res << "\n\n";
    return 0;
}