#include <iostream>
#include <string>
#include <cctype>

std::string rot13(const std::string& str)
{
    if (str.empty())
        return "";

    std::string s (str);
    int len = static_cast<int>(str.length());

    for (int i = 0; i < len; ++i)
    {
        if(std::isupper(s[i]))
        {
            char tmp = s[i] >= 'N'
                ? 'A' + s[i] - 'N'
                : s[i] + 13;
            s[i] = tmp;
        }
        else if(std::islower(s[i]))
        {
            char tmp = s[i] >= 'n'
                ? 'a' + s[i] - 'n'
                : s[i] + 13;
            s[i] = tmp;
        }
        else
            continue;
    }
    return s;
}

int main (int argc, char *argv[])
{
    std::string str = "EBG13 rknzcyr.";
    auto str2 = rot13(str);
    std::cout << str << "\n" << str2 << "\n\n";
    return 0;
}
