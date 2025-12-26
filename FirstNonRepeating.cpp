#include <algorithm>
#include <cctype>
#include <optional>
#include <string>
#include <string_view>
#include <vector>
#include <fmt/core.h>
#include <fmt/base.h>

std::optional<char> FirstNonRepeating(std::string_view str)
{
    struct LetterCount
    {
        char letter{0};
        unsigned count{0};
    };

    std::vector<LetterCount> letters{};
    letters.reserve(26); //letters in the alphabet

    for(const auto& c: str) 
    {
        auto p = std::find_if(letters.begin(), letters.end(), 
            [c = c](LetterCount const& lc) -> bool 
                {return ::tolower(static_cast<unsigned char>(lc.letter)) == 
                    ::tolower(static_cast<unsigned char>(c)); });

        if(p != letters.end()) { p->count++; }
        else { letters.push_back(LetterCount{c, 1}); }
    }

    for(const auto lc: letters)
    {
        if(lc.count == 1)
            return lc.letter;
    }

    return std::nullopt;
}

int main()
{
    std::string s = "sTress";
    fmt::println("\nOriginal str: {}", s);
    auto ans = FirstNonRepeating(s);
    if(ans) { fmt::println("First non-repeating letter: {}\n", *ans); }
    else { fmt::println("First non-repeating letter: None"); }
}
