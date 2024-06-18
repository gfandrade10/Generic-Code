#include <cstddef>
#include <exception>
#include <iostream>
#include <bitset>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

namespace custom_bitset
{
    #ifndef BITS
        #define BITS 6
    #endif

    const std::vector<std::pair<char, int>> char_list =
    {
        {'A', 0},  {'B', 1},  {'C', 2},  {'D', 3},  {'E', 4},
        {'F', 5},  {'G', 6},  {'H', 7},  {'I', 8},  {'J', 9},
        {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14},
        {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19},
        {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24},
        {'Z', 25}, {'a', 26}, {'b', 27}, {'c', 28}, {'d', 29},
        {'e', 30}, {'f', 31}, {'g', 32}, {'h', 33}, {'i', 34},
        {'j', 35}, {'k', 36}, {'l', 37}, {'m', 38}, {'n', 39},
        {'o', 40}, {'p', 41}, {'q', 42}, {'r', 43}, {'s', 44},
        {'t', 45}, {'u', 46}, {'v', 47}, {'w', 48}, {'x', 49},
        {'y', 50}, {'z', 51}, {'0', 52}, {'1', 53}, {'2', 54},
        {'3', 55}, {'4', 56}, {'5', 57}, {'6', 58}, {'7', 59},
        {'8', 60}, {'9', 61}, {' ', 62}, {'.', 63}
    };

    int find_int(char c)
    {
        try 
        {
            auto it = char_list.begin();
            for (; it != char_list.end(); ++it)
            {
                if(it->first == c)
                    return it->second;
            }
            throw std::exception();
        }
        catch(std::exception& e)
        {
            std::cerr << "Invalid character.\n\n";
            throw std::runtime_error(e.what());
        }
    }

    char find_char(int x)
    {
        try 
        {
            if (x > 63 || x < 0)
                throw std::exception();

            auto it = char_list.begin();
            for(; it != char_list.end(); it++)
            {
                if(it->second == x)
                    return it->first;
            }
            return  0;
        }
        catch(std::exception& e)
        {
            std::cerr << "Invalid integer.\n\n";
            throw std::runtime_error(e.what());
        }
    }

    std::vector<std::bitset<BITS>> to_bitset(const std::string& str)
    {
        size_t len = str.length();
        std::vector<std::bitset<BITS>> res(len);

        for (size_t i = 0; i < len; i++)
        {
            res[i] = std::bitset<BITS>(find_int(str[i]));
        }
        return res;
    }
    
    char bitset_to_char(const std::bitset<BITS>& bs)
    {
        int x = (int)bs.to_ulong();
        return find_char(x);        
    }

    void bitset_swap(std::bitset<BITS>& bs1, int i1, std::bitset<BITS>& bs2, int i2)
    {
        bool tmp = bs1[i1];
        bs1[i1] = bs2[i2];
        bs2[i2] = tmp;
    }

    void bitset_reverse(std::bitset<BITS>& bs)
    {
        size_t len = bs.size();
        for (size_t i = 0; i < len/2; i++)
        {
            bool tmp = bs[i];
            bs[i] = bs[len - i - 1];
            bs[len - i - 1] = tmp;
        }
    }

    inline size_t reverse_pos (size_t x) noexcept
    {
        return BITS - x;
    }
    
    void print_bitset(const std::bitset<BITS>& bs)
    {
        std::ostringstream os;
        os << bs;
        std::cout << os.str() << "\n";
    }
}

std::string encrypt(std::string text)
{
    #define POSX(x) custom_bitset::reverse_pos(x)
    auto bs = custom_bitset::to_bitset(text);
    size_t len = bs.size();

    for(size_t i = 0; i < len; i++)
    {
        if(i < len - 1)
        {
            size_t p1 = POSX(5);
            size_t p2 = POSX(1);
            custom_bitset::bitset_swap(bs[i], p1, bs[i+1], p2);
        }

        bs[i][POSX(2)].flip();
        bs[i][POSX(4)].flip();
        for(size_t j = 0; j < BITS/2; j++)
            custom_bitset::bitset_swap(bs[i], j, bs[i], j+BITS/2);

        for(size_t j = 1; j <= BITS; j+=2)
            custom_bitset::bitset_swap(bs[i], POSX(j), bs[i], POSX(j+1));

        custom_bitset::bitset_reverse(bs[i]);
        {
            size_t p1 = POSX(1);
            size_t p2 = POSX(3);
            custom_bitset::bitset_swap(bs[i], p1, bs[i], p2);
        }
    }

    std::string res;
    res.resize(len);
    for(size_t i = 0; i < len; i++)
        res[i] = custom_bitset::bitset_to_char(bs[i]);
        
    return res;
}
  
std::string decrypt(std::string encryptedText)
{
    #define POSX(x) custom_bitset::reverse_pos(x)
    auto bs = custom_bitset::to_bitset(encryptedText);
    size_t len = bs.size();

    for(size_t i = 0; i < len; i++)
    {
        {
            size_t p1 = POSX(1);
            size_t p2 = POSX(3);
            custom_bitset::bitset_swap(bs[i], p1, bs[i], p2);
        }

        custom_bitset::bitset_reverse(bs[i]);

        for(size_t j = 1; j <= BITS; j+=2)
            custom_bitset::bitset_swap(bs[i], POSX(j), bs[i], POSX(j+1));

        for(size_t j = 0; j < BITS/2; j++)
            custom_bitset::bitset_swap(bs[i], j, bs[i], j+BITS/2);
        
        bs[i][POSX(4)].flip();
        bs[i][POSX(2)].flip();

        if(i > 0)
        {
            size_t p1 = POSX(1);
            size_t p2 = POSX(5);
            custom_bitset::bitset_swap(bs[i], p1, bs[i-1], p2);
        }
    }

    std::string res;
    res.resize(len);
    for(size_t i = 0; i < len; i++)
        res[i] = custom_bitset::bitset_to_char(bs[i]);
        
    return res;
}

int main ()
{
    std::string str = "Hello this is a test.";
    std::string res = encrypt(str);
    std::string dec = decrypt(res);
    std::cout << str << "\n\n" << res << "\n\n" << dec << "\n\n";
}
