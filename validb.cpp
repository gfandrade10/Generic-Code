#include <iostream>
#include <map>

bool valid_braces(std::string braces) 
{
    bool flag = true;
    std::map<char,int> mymap;
    int ParCount = 0, ChavCount = 0, ColCount = 0;
    for (int i = 0; i < (int)braces.length(); i++)
    {
        switch (braces[i])
        {
            case '(': { ParCount++;  break; }
            case ')': { ParCount--;  break; }
            case '[': { ChavCount++; break; }
            case ']': { ChavCount--; break; }
            case '{': { ColCount++;  break; }
            case '}': { ColCount--;  break; }
        }
        if(ParCount < 0 || ChavCount < 0 || ColCount < 0) return false;
    }
    return flag;
}

int main()
{
    std::string mystring = "[(])";
    if(valid_braces(mystring)) std::cout << "TRUE\n\n";
    else std::cout << "FALSE\n\n";
    return 0;
}