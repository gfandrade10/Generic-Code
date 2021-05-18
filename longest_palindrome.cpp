#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

bool Pali(const string& input, size_t& size) noexcept
{
    bool flag = true;
    for(size_t i = 0; i < input.length()/2; i++)
    {
        if(input[i] == input[input.length()-i-1]) continue;
        else { flag = false; break; }
    }
    if(flag)
    {
        size = input.length();
        return true;
    }
    return false;
}

string longest_palindrome(const string& input)
{
    vector<string> allData;
    string res = "";
    size_t ref = 0, size = 0;
    if(Pali(input,size)) return input;
    allData.push_back(input.substr(0,1));
    
    for(size_t i = 0; i < input.length(); i++)
    {
        for(size_t j = i; j < input.length(); j++)
        {
            if (i != j && input[i] == input[j]) 
                allData.push_back(input.substr(i,j-i+1));
        }
    }

    for(auto& e:allData)
    {   
        if(e.length() > size && Pali(e,ref))
        {
            if(ref > size)
            {
                res = e;
                size = ref;
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    std::cout << longest_palindrome("66racecarxdahannah47") << "\n\n";
    return 0;
}
