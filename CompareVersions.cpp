#include <iostream>
#include <string>
#include <vector>

bool compareVersions (std::string version1, std::string version2)
{
    if(version1.empty() || version2.empty())
        return false;

    size_t len1 = version1.length();
    size_t len2 = version2.length();
    
    std::vector<int> vals1;
    std::vector<int> vals2;

    std::string Buffer = "";
    for (size_t i = 0; i < len1; ++i)
    {
        if(version1[i] != '.' && i == len1 - 1)
        {
            Buffer.push_back(version1[i]);
            vals1.push_back(std::stoi(Buffer));
            Buffer.clear();
        }
        else if(version1[i] != '.')
        {
            Buffer.push_back(version1[i]);
        }
        else
        {
            vals1.push_back(std::stoi(Buffer));
            Buffer.clear();
        }
    }
    
    for (size_t i = 0; i < len2; ++i)
    {
        if(version2[i] != '.' && i == len2 - 1)
        {
            Buffer.push_back(version2[i]);
            vals2.push_back(std::stoi(Buffer));
            Buffer.clear();
        }
        else if(version2[i] != '.')
        {
            Buffer.push_back(version2[i]);
        }
        else
        {
            vals2.push_back(std::stoi(Buffer));
            Buffer.clear();
        }
    }

    size_t bigger = vals1.size() >= vals2.size()
        ? vals2.size()
        : vals1.size();

    int diff;
    for(size_t i = 0; i < bigger; ++i)
    {
        diff = vals1[i] - vals2[i];
        if (diff < 0)
            return false;
        else if (diff > 0)
            return true;
    }

    if (vals2.size() > vals1.size())
        return false;
    else
        return true;
}

void PrintBool (bool flag)
{
    if(flag)
        std::cout << "TRUE\n\n";
    else
        std::cout << "FALSE\n\n";
}

int main (int argc, char *argv[])
{
    PrintBool(compareVersions("10.4.6", "10.4"));
    return 0;
}
