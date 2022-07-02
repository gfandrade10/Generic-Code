#include <iostream>
#include <vector>
#include <algorithm>

bool valid_braces(std::string braces) 
{
    if(braces.length() == 1) return false;
    std::vector<char> Open;
    using SI = std::string::iterator;
    for(auto& c:braces)
    {
        if (c == '(' || c == '[' || c == '{')
            Open.push_back(c);
        if(!Open.empty())
        {
            if (c == ')' && *(Open.end()-1) == '(')
                Open.pop_back();
            else if(c == ')' && std::find(Open.begin(), Open.end(),'(') == Open.end())
                return false;
            if (c == ']' && *(Open.end()-1) == '[')
                Open.pop_back();
            else if(c == ']' && std::find(Open.begin(), Open.end(),'[') == Open.end())
                return false;
            if (c == '}' && *(Open.end()-1) == '{')
                Open.pop_back();
            else if(c == '}' && std::find(Open.begin(), Open.end(),'{') == Open.end())
                return false;
        }
        else if ((SI)&c != braces.begin() && Open.empty() &&
        (c == ')' || c == ']' || c == '}'))
            return false;
    }
    if(Open.empty()) return true;
    else return false;
}

int main (int argc, char* argv[])
{
    std::string input = "([{}]){]";
    std::cout << input << "\n" << valid_braces(input) << "\n\n";
    return 0;
}