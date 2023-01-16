#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string changeCase(const std::string &identifier, 
    const std::string &targetCase)
{
    std::vector<std::string> op;
    std::string s {identifier};
    bool id = true;
    int n = (int)identifier.size(), ref = 0;
    char key = '*';

    for (int i = 0; i < n; ++i)
    {
        if (id)
        {
            if (identifier[i] == '-')
            {
                key = '-';
                id = false;
            }
            if (identifier[i] == '_')
            {
                key = '_';
                id = false;
            }
            if (identifier[i] >= 'A' && identifier[i] <= 'Z')
                id = false;
        }
        if (key == '*' && !id)
        {
            if (identifier[i] >= 'A' && identifier[i] <= 'Z')
            {
                op.emplace_back(identifier.substr(ref, i - ref));                
                ref = i;
            }
            if (i == n-1 && op.size() > 0)
                op.emplace_back(identifier.substr(ref)); 
            if (identifier[i] == '-' || identifier[i] == '_') 
                return "";
        }
        else if (!id)
        {
            if (identifier[i] == key && i != ref)
            {
                s[i] = std::tolower(identifier[i]);
                op.emplace_back(s.substr(ref, i - ref));
                if (i < n-1)
                    ref = i + 1;
            }
            if (i == n-1 && op.size() > 0)
                op.emplace_back(s.substr(ref));    
            if ((key == '-' && identifier[i] == '_') ||
                (key == '_' && identifier[i] == '-') ||
                (identifier[i] >= 'A' && identifier[i] <= 'Z'))
                    return ""; 
        }           
    }
    if (id) return identifier;
    std::string res;
    if (targetCase == "snake")
    {
        if (key == '_') return identifier;
        for (auto &e: op)
            res += e + "_";
        return res.substr(0, res.length()-1);
    }
    else if (targetCase == "kebab")
    {
        if (key == '-') return identifier;
        for (auto &e: op)
            res += e + "-";
        return res.substr(0, res.length()-1);
    }
    else if (targetCase == "camel")
    {
        if (key == '*') return identifier;
        for (int i = 0; i < (int)op.size(); i++)
        {
            if (i == 0)
                op[i][0] = std::tolower(op[i][0]);
            else
                op[i][0] = std::toupper(op[i][0]);
            res += op[i];
        }
        return res;
    }
    return "";
}

int main(int argc, char *argv[])
{
    std::cout << changeCase("tlkgsfrKhiH", "snake") << "\n\n";
    return 0;
}