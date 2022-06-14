#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::string String;
typedef std::string::iterator Siter;
typedef long long ll;

namespace ToSmallest
{
    String Swap (const String& input, Siter insert, Siter place)
    {
        String tmp = "";
        for (auto it = input.begin(); it != input.end(); ++it)
        {
            if (it == place)
                tmp.push_back(*insert);
            if (it != insert)
                tmp.push_back(*it);
        }
        return tmp;
    }

    std::vector<ll> smallest(ll n)
    {
        String str = std::to_string(n), buffer(str);
        auto it = std::min_element(str.begin(),str.end());
        auto tmp = str.begin();
        while(it == tmp)
        {
            tmp++;
            it = std::min_element(tmp,str.end());
        }
        auto ZeroFinder = str.begin()+1;
        while (*ZeroFinder == '0')
        {
            ZeroFinder++; 
            buffer = Swap(str,str.begin(),ZeroFinder);
            tmp = ZeroFinder-1;
        }
        for (auto iter = it; iter != str.end(); ++iter)
        {   
            if (*iter <= *it)
                it = iter;
        }
        if (std::stoll(Swap(str,it,tmp)) < std::stoll(buffer))
            buffer = Swap(str,it,tmp);
        else
            return {std::stoll(buffer), 0 ,tmp-str.begin()};

        ll value = std::stoll(str);
        auto pos = it;
        for(auto it2 = str.begin(); it2 != str.end(); ++it2)
        {
            ll calc = std::stoll(Swap(str,str.begin(),it2));
            if(calc < value)
            { value = calc; pos = it2; }         
        }
        if(value <= std::stoll(buffer))
            return {value, 0, pos - str.begin()};

        ll distance = tmp - str.begin();
        for (ll i = tmp - str.begin(); i >= 0; i--)
        {
            if (buffer[i] == *tmp)
            { distance = (ll)i; }
        }
        auto iter = it;
        while(*iter == *it)
            iter--;

        return {std::stoll(buffer), iter-str.begin()+1, distance};
    }
};

int main(int argc, char* argv[])
{
    ll num = 239687;
    std::vector<ll> res = ToSmallest::smallest(num);
    for (auto& e: res)
        std::cout << e << "  ";
    std::cout << "\n\n";
    return 0;
}