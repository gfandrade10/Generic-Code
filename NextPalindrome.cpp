#include <chrono>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

inline long NextPalindrome(long n)
{
    long Number = static_cast<long>(n);
    if (Number < 9) return Number + 1;
    if (Number % 10 == 9) return Number + 2;

    std::string NumStr = std::to_string(Number);
    size_t Length = NumStr.length();

    std::string LeftHalf = NumStr.substr(0, (Length + 1) / 2);
    std::string PalindromeCandidate = 
        LeftHalf + std::string(LeftHalf.rbegin() + (Length % 2), LeftHalf.rend());

    if (std::stoll(PalindromeCandidate) > Number) 
        return std::stoll(PalindromeCandidate);
    else 
    {
        LeftHalf = std::to_string(std::stoll(LeftHalf) + 1);
        return std::stoll(LeftHalf + std::string(LeftHalf.rbegin() + (Length % 2), LeftHalf.rend()));
    }
}

inline bool IsPalindrome(long n) noexcept
{
    std::string Buffer = std::to_string(n);
    size_t len = Buffer.length();
    for (size_t i = 0; i < len / 2; i++)
    {
        if (Buffer[i] != Buffer[len - i - 1])
            return false;
    }
    return true;
}

inline bool SquareSums(long Number) noexcept
{
    long Limit = static_cast<long>(std::sqrt(Number));
    long StartingPoint = 1;
    long Sum = 0;
    long i = 1;

    while (i <= Limit)
    {
        if (Sum == Number)
        {
            return true;
        }
        else if(Sum < Number)
        {
            Sum += i*i;
            i++;
        }
        else if(Sum > Number)
        {
            while(Sum > Number)
            {
                Sum -= StartingPoint * StartingPoint;
                StartingPoint++;
            }
            if (i == Limit && Sum < Number)
                i++;
        }
    }
    return false;
}

long values(long n)
{
    long Pal = 1;
    long Results = 1;
    while(Pal < n)
    {
        if(IsPalindrome(Pal))
        {
            if(SquareSums(Pal))
                Results++;
        }
        Pal = NextPalindrome(Pal);
    }
    return Results;
}

int main (int argc, char *argv[])
{
    long n = std::stol(std::string(argv[1]));
    std::ostringstream os;

    auto Start = std::chrono::steady_clock::now();
    long p = values(n);
    auto End = std::chrono::steady_clock::now();

    auto Diff = std::chrono::duration<float, std::milli>(End - Start);

    os << p << ", elapsed time: ";
    os << std::fixed;
    os << std::setprecision(4);
    os << Diff.count()/1000.0f;
    os << "s\n\n";
    std::cout << os.str();
    return 0;
}

