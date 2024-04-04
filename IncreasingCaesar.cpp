#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>

class CaesarCipher
{
    public:
    CaesarCipher() = delete;

    static inline char ShiftFunc(char c, int& shift)
    {
        if(!std::isalpha(c))
            return c;

        shift %= 26;         
        if (shift == 0)
            return c;

        bool Case = (c >= 'a' && c <= 'z');
        c = toupper(c);

        if(c + shift > 'Z')
            c = 'A' + c + shift - 'Z' - 1;
        else if(c + shift < 'A')
            c = 'Z' - ('A' - (c + shift)) + 1;
        else
            c += shift;

        if(Case)
            return std::tolower(c);
        else
            return c;
    }

    static std::vector<std::string> movingShift(const std::string &s, int shift)
    {
        size_t len1, len2, count = 0;
        len1 = (int)std::ceil((s.length() + 0.0)/5);
        len2 = s.length() - 4*len1;
        std::vector<std::string> res(5);

        for(size_t i = 0; i < s.length(); ++i)
        {
            res[count].push_back(ShiftFunc(s[i], shift));
            if(res[count].length() == len1)
                count++;
            shift++;
        }
        return res;
    }

    static std::string demovingShift(std::vector<std::string> &s, int shift)
    {
        std::string res;
        for(const auto& it: s)
            res += it;
        
        size_t len = res.length();
        for(size_t i = 0; i < len; ++i)
        {
            int tmp = -1 * shift;
            res[i] = ShiftFunc(res[i], tmp);
            shift++;
        }
        return res;
    }
};

int main()
{
    std::string s = "I should have known that you would have a perfect answer for me!!!";
    auto vec = CaesarCipher::movingShift(s, 1);

    for(const auto& it: vec)
        std::cout << it << "\n";

    std::string dec = CaesarCipher::demovingShift(vec,1);
    std::cout << "\n" << dec << "\n\n";
    return 0;
}
