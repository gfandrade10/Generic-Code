#include <iostream>
#include <string>
#include <vector>

class LongestConsec
{
    public:
        static std::string longestConsec(std::vector<std::string> &strarr, int k);
};

std::string LongestConsec::longestConsec(std::vector<std::string> &strarr, int k)
{
    if (strarr.size() < k) return "";
    int n = strarr.size();
    std::vector<int> Sizes(n);
    for (int i = 0; i < n; ++i) 
        Sizes[i] = strarr[i].length();
    int Max = 0;
    int pos = 0;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < i+k; j++)
            if (j < n) sum += Sizes[j];      
        if (sum > Max) 
        {
            Max = sum;
            pos = i;
        }
    }
    std::string res = "";
    for (int i = pos; i < pos+k; ++i)
        res += strarr[i];
    return res;    
}

int main (int argc, char **argv)
{
    std::vector<std::string> strarr = {"zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"};
    std::cout << LongestConsec::longestConsec(strarr,8) << "\n\n";
    return 0;
}