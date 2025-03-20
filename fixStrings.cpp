#include <cctype>
#include <iostream>
#include <regex>
#include <string>

std::string correct_it(std::string str) 
{
    std::regex rgx1("(\\s+)$|^(\\s+)|((\\s+\\.+)$)");
    std::regex rgx2("\\s+");
    std::regex rgx3("\\.(?=[a-zA-Z])|(\\s)(?=[A-Z])");
    std::regex rgx4("\\.+");

    str = std::regex_replace(str, rgx1, "");
    str = std::regex_replace(str, rgx2, " ");
    str = std::regex_replace(str, rgx3, ". ");
    str = std::regex_replace(str, rgx4, ".");

    *str.begin() = ::toupper(str.front());

    for(size_t i = 0; i < str.length(); ++i)
    {
        if(str[i] == '.' && i < str.length() - 1)
            str[i+2] = ::toupper(str[i+2]);
    }

    if(str.back() != '.')
        str.push_back('.');
    
    return str;
}

int main()
{
    std::string str = "   hello   stonks Miltred..hahaha";
    std::cout << str << "\n" << correct_it(str) << "\n";
}
