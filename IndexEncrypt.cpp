#include <cctype>
#include <cstddef>
#include <iostream>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <utility>

class Kata
{
    public:
    inline bool checkValidInput(std::string const& s) const;
    void errorHandling(std::string const& s) const;
    char switchCase(char c) const;
    char mirrorChar(char c) const;

    std::string encrypt(std::string text) const;
    std::string decrypt(std::string encryptedText) const;

    private:
    static constexpr size_t Size = 77;
    const std::map<char, size_t> Sequence = 
    {
        { 'A',  0 }, { 'B',  1 }, { 'C',  2 }, { 'D',  3 },
        { 'E',  4 }, { 'F',  5 }, { 'G',  6 }, { 'H',  7 },
        { 'I',  8 }, { 'J',  9 }, { 'K', 10 }, { 'L', 11 },
        { 'M', 12 }, { 'N', 13 }, { 'O', 14 }, { 'P', 15 },
        { 'Q', 16 }, { 'R', 17 }, { 'S', 18 }, { 'T', 19 },
        { 'U', 20 }, { 'V', 21 }, { 'W', 22 }, { 'X', 23 },
        { 'Y', 24 }, { 'Z', 25 },

        { 'a', 26 }, { 'b', 27 }, { 'c', 28 }, { 'd', 29 },
        { 'e', 30 }, { 'f', 31 }, { 'g', 32 }, { 'h', 33 },
        { 'i', 34 }, { 'j', 35 }, { 'k', 36 }, { 'l', 37 },
        { 'm', 38 }, { 'n', 39 }, { 'o', 40 }, { 'p', 41 },
        { 'q', 42 }, { 'r', 43 }, { 's', 44 }, { 't', 45 },
        { 'u', 46 }, { 'v', 47 }, { 'w', 48 }, { 'x', 49 },
        { 'y', 50 }, { 'z', 51 },

        { '0', 52 }, { '1', 53 }, { '2', 54 }, { '3', 55 },
        { '4', 56 }, { '5', 57 }, { '6', 58 }, { '7', 59 },
        { '8', 60 }, { '9', 61 },

        { '.', 62 }, { ',', 63 }, { ':', 64 }, { ';', 65 },
        { '-', 66 }, { '?', 67 }, { '!', 68 }, { ' ', 69 },

        { '\'', 70 }, { '(', 71 }, { ')', 72 }, { '$', 73 },
        { '%', 74 }, { '&', 75 }, { '\"', 76 }
    };
};

inline bool Kata::checkValidInput(std::string const& s) const
{
    for(auto const& c: s)
    {
        if(Sequence.find(c) == Sequence.end())
            return false;
    }
    return true;
}

void Kata::errorHandling(std::string const& s) const
{
    if(!checkValidInput(s))
        throw std::runtime_error("Invalid Input");
}

char Kata::switchCase(char c) const
{
    if(::isalpha(c))
    {
        if(c >= 'A' && c <= 'Z') return std::tolower(c);
        else return std::toupper(c);
    }
    else return c;
}

char Kata::mirrorChar(char c) const
{
    std::map<char, size_t>::const_iterator it = Sequence.find(c);
    size_t diff = Size - it->second - 1;
    
    auto Predicate = [=](std::pair<char, size_t> const& p) { return p.second == diff; };
    auto Ans = std::find_if(Sequence.begin(), Sequence.end(), Predicate);
    return Ans->first;
}

std::string Kata::encrypt(std::string text) const
{
    errorHandling(text);
    size_t len = text.length();

    for(size_t i = 1; i < len; i += 2)
        text[i] = switchCase(text[i]);

    std::string sCopy(text);
    for(size_t i = 1; i < len; ++i)
    {
        size_t Idx = Sequence.find(sCopy[i-1])->second - Sequence.find(sCopy[i])->second;
        Idx = (Idx + Size) % Size;

        char temp = std::find_if(Sequence.begin(), Sequence.end(), 
            [=](std::pair<char, size_t> const& p) { return p.second == Idx; })->first;
        
        text[i] = temp;
    }
    
    text[0] = mirrorChar(text[0]);
    return text;
}

std::string Kata::decrypt(std::string encryptedText) const
{
    errorHandling(encryptedText);
    encryptedText[0] = mirrorChar(encryptedText[0]);

    size_t len = encryptedText.length();
    for(size_t i = 1; i < len; ++i)
    {
        size_t Idx = Size - Sequence.find(encryptedText[i])->second + Sequence.find(encryptedText[i-1])->second;
        Idx = Idx % Size;

        char temp = std::find_if(Sequence.begin(), Sequence.end(), 
            [=](std::pair<char, size_t> const& p) { return p.second == Idx; })->first;
        
        encryptedText[i] = temp;
    }

    for(size_t i = 1; i < len; i += 2)
        encryptedText[i] = switchCase(encryptedText[i]);
    
    return encryptedText;
}

int main()
{
    Kata functor;
    std::string text = "This is a test!";
    std::string res = functor.encrypt(text);
    std::cout << text << "\n" << res << "\n" << functor.decrypt(res) << "\n";
}
