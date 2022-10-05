#include <iostream>
#include <algorithm>
#include <utility>

std::string add(std::string a, std::string b) 
{
    std::string res = "", c = "";
    int carry = 0;
    if (a.length() > b.length())
        std::swap(a, b);
    std::reverse(a.begin(), a.end());
    for (size_t i = 0; i < b.length(); ++i)
    {
        if (i < a.length()) c.push_back(a[i]);
        else c.push_back('0');
    }
    std::reverse(c.begin(), c.end());

    for(size_t i = 0; i < b.length(); ++i)
    {
        int index = b.length() - i - 1;
        int tmp = (c[index] - '0') + (b[index] - '0') + carry;
        if(tmp >= 10)
        {
            carry = 1;
            res.push_back(tmp - 10 + '0');
        }
        else
        {
            carry = 0;
            res.push_back(tmp + '0');
        }
    }
    if (carry == 1)
        res.push_back(1 + '0');
    std::reverse(res.begin(), res.end());
    return res;
}

int main (int argc, char* argv[])
{
    std::string res = add("99", "2");
    std::cout << res << "\n\n";
    return 0;
}