#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

class RevRot
{
    using String = std::string;
    using SI = String::iterator;
    using uint = unsigned int;

    public:
    static String Rotate(String&& input)
    {
        input.push_back(input[0]);
        return input.substr(1);
    }

    static String Block(SI& it, uint len)
    {
        size_t val = 0;
        String res = "";
        for (uint i = 0; i < len; i++)
        {
            res.push_back(*it);
            val += (size_t)(*it - '0');
            it++;
        }
        if (val%2 == 0) std::reverse(res.begin(), res.end());
        else res = Rotate(std::move(res));
        return res;
    }

    static String revRot(const String& str, uint sz)
    {
        if (str.empty() || sz == 0 || str.length() < sz) return "";

        String res = "", temp;
        if (str.length() % sz != 0) 
            temp = str.substr(0, str.length() - str.length() % sz);
        else
            temp = str;

        SI it = temp.begin();
        do {
            res += Block(it, sz);
        } while (res.length() < temp.length());
        return res;
    }
};

int main(int argc, char *argv[])
{
    std::cout << RevRot::revRot("733049910872815764", 5);
    std::cout << "\n\n";
    return 0;
}