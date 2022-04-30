#include <iostream>
#include <string>
#include <vector>

std::string likes(const std::vector<std::string> &names)
{
    int s = names.size();
    switch(s)
    {
        case 0:
            return "no one likes this";
        case 1:
            return names[0] + " likes this";
        case 2:
            return names[0] + " and " + names[1] + " like this";
        case 3:
            return names[0] + ", " + names[1] + " and " + names[2] + " like this";
        default:     
            return names[0] + ", " + names[1] + " and " + std::to_string(s-2) + " others like this";
    }
    return "";
}

int main(int argc, char* argv[])
{
    std::vector<std::string> input = {"Gui", "SSL", "Mark", "Max", "Toney", "GG"};
    std::cout << "Input: ";
    for (const auto &e:input)
        std::cout << e << " ";
    std::cout << "\n";
    std::cout << "Result: " << likes(input) << "\n\n";
    return 0;
}