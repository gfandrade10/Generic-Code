#include <string>
#include <iostream>
#include <vector>
#include <cmath>

class CodeSqStrings
{
    using StrMatrix = std::vector<std::string>;

    public:
    static std::string code(const std::string &strng);
    static std::string decode(const std::string &strng);
};

std::string CodeSqStrings::code(const std::string &strng)
{
    size_t Size = std::ceil(std::sqrt(strng.length()));
    StrMatrix M1;
    std::string buffer;
    size_t count = 0;
    for(size_t i = 0; i < Size*Size; ++i)
    {
        if (i < strng.size())
            buffer.push_back(strng[i]);
        else
            buffer.push_back('\x0b');
        count++;
        if (count == Size)
        {
            count = 0;
            M1.emplace_back(buffer);
            buffer = "";
        }
    }
    for(size_t i = 0; i < Size; ++i)
    {
        for(size_t j = 0; j < Size; ++j)
            buffer.push_back(M1[Size - j - 1][i]);
        if (i < Size-1)
            buffer += "\n";
    }
    return buffer;
}

std::string CodeSqStrings::decode(const std::string &strng)
{
    size_t Size = 0;
    StrMatrix M1;
    std::string buffer;
    for (size_t i = 0; i < strng.length(); ++i)
    {
        if (strng[i] != '\n')
            buffer.push_back(strng[i]);
        if(strng[i] == '\n' || i == strng.length() - 1)
        {
            Size++;
            M1.emplace_back(buffer);
            buffer = "";
        }
    }
    for(size_t i = 0; i < Size; ++i)
    {
        for(size_t j = 0; j < Size; ++j)
            buffer.push_back(M1[j][Size-i-1]);
    }
    std::string res;
    for (const auto &e: buffer)
    {
        if (e != '\x0b')
            res.push_back(e);
    }
    return res;
}

int main (int argc, char* argv[])
{
    std::string input = "Hello world";
    std::string encoded = CodeSqStrings::code(input);
    std::cout << encoded << "\n\n";
    std::cout << CodeSqStrings::decode(encoded) << "\n\n";
    return 0;
}