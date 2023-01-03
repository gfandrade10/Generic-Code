#include <iostream>
#include <regex>
#include <string>

using SI = std::string::const_iterator;

std::string rotate_left(std::string &&str, int n)
{
    int len = (int) str.length();
    if (len % n == 0 || len == n) 
        return std::move(str);
    auto tmp = str + str;
    if (len < n)
        return tmp.substr(n % len, len);
    else
        return tmp.substr(n, len);
}

std::string rotate_right(std::string &&str, int n)
{
    int len = (int) str.length();
    if (len % n == 0 || len == n) 
        return std::move(str);
    auto tmp = str + str;
    if (len < n)
        return tmp.substr(len - (n % len), len);
    else
        return tmp.substr(len - n, len);
}

std::string encode(int n, std::string str)
{
    int len = (int) str.length();
    for (int k = 0; k < n; k++)
    {
        std::vector<int> zeros;
        for (size_t i = 0; i < str.length(); ++i)
        {
            if (str[i] == ' ')
                zeros.push_back(i);
        }
        str = std::regex_replace(str, std::regex {R"((?:(?![\n\t]+)(\s))+)"}, "");
        str = rotate_right(std::move(str), n);    
        for (int i = 0, j = 0; i < len ; ++i)
        {
            if (i == zeros[j])
                str.insert(zeros[j++], " ");
        }
        std::regex rgx
            {R"(([_!@#\$%\^&()[\]{}+\-\*/=\"'<>,\.\?\:;A-Za-z0-9\n\t]+)|(?:(?![\n\t]+)(\s))+)"};
        std::regex_token_iterator<SI> it (str.begin(), str.end(), rgx), end;
        {
            std::string tmp, buf;
            for (; it != end; ++it)
            {
                buf = *it;
                tmp += rotate_right(std::move(buf), n);
            }
            str = tmp;
        }
    }
    return std::to_string(n) + " " + str;
}

std::string decode(std::string str)
{
    std::string num;
    int n, len = (int) str.length();
    for (const auto &e: str)
    {
        if (e != ' ')
            num.push_back(e);
        else break;
    }
    n = std::stoi(num);
    str = std::regex_replace(str, std::regex {R"(^[0-9]+(\s))"}, "");
    for (int k = 0; k < n; ++k)
    {
        std::vector<int> zeros;
        for (size_t i = 0; i < str.length(); ++i)
        {
            if (str[i] == ' ')
                zeros.push_back(i);
        }
        std::regex rgx
            {R"(([_!@#\$%\^&()[\]{}+\-\*/=\"'<>,\.\?\:;A-Za-z0-9\n\t]+)|(?:(?![\n\t]+)(\s))+)"};
        std::regex_token_iterator<SI> it (str.begin(), str.end(), rgx), end;
        {
            std::string tmp, buf;
            for (; it != end; ++it)
            {
                buf = *it;
                tmp += rotate_left(std::move(buf), n);
            }
            str = tmp;
        }
        str = std::regex_replace(str, std::regex {R"((?:(?![\n\t]+)(\s))+)"}, "");
        str = rotate_left(std::move(str), n);    
        for (int i = 0, j = 0; i < len ; ++i)
        {
            if (i == zeros[j])
                str.insert(zeros[j++], " ");
        } 
    }
    return str;
}

int main(int argc, char* argv[])
{
    std::string S1, S2, S3;
    S1 = "Oh, Fortuna, you capricious sprite!";
    S2 = encode(12, S1);
    S3 = decode(S2);
    std::cout << S1 << "\n" << S2 << "\n" << S3 << "\n\n";
    return 0;
}