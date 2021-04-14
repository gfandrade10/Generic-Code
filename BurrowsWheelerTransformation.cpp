#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

std::pair<std::string, int> encode(const std::string &s) 
{
    std::vector<std::string> vec;
    std::string res;
    size_t n = s.length();
    vec.push_back(s);
    for (size_t i = 0; i < n-1; i++)
    {
        std::string buffer = (vec[i])[n-1] + (vec[i]).substr(0,n-1);
        vec.push_back(buffer);
    }
    std::sort(vec.begin(), vec.end());
    int pos;
    for (size_t i = 0; i < n; i++)
    {
        res += (vec[i])[n-1];
        if(vec[i] == s) pos = i;
    }
    return std::pair<std::string, int> (res, pos);
}

std::string decode(const std::string &s, int n) 
{
    size_t N = s.length();
    std::vector<std::string> vec(N);
    for(size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
            vec[j] = s[j] + vec[j];
        std::sort(vec.begin(), vec.end());
    }
    return vec[n];
}

int main(int argc, char** argv)
{
    std::string S1 = "bananabar";
    std::pair<std::string, int> result = encode(S1);
    std::cout << result.first << "  " << result.second << std::endl;
    std::cout << decode(result.first, result.second) << std::endl;
    std::cin.get();
    return EXIT_SUCCESS;
}