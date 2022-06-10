#include <iostream>
#include <string>
#include <regex>
#include <functional>
#include <vector>

bool Smile(std::string& str) 
{
    std::string Regex;
    Regex = "((:)|(;)|(:-)|(;-)|(:~)|(;~))(?=.*)((\\))|(D)|(]))";
    std::regex reg(Regex);
    std::smatch sm;
    return std::regex_search(str,sm,reg);
}

int countSmileys(std::vector<std::string> arr)
{
    auto SumSmiles = [](std::vector<std::string>&& args)->int
    { int count = 0; for (auto&& e: args) if(Smile(e)) count++; return count; };
    return SumSmiles(std::move(arr));
}

int main (int argc, char** argv)
{
    std::vector<std::string> args = {";)", ";~)", ":)", ":D", ":>", ":~D", ";~)"};
    std::cout << countSmileys(args) << "\n\n";
    return 0;
}