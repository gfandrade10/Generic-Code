#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cctype>

int solve(const std::string& eq)
{
    std::istringstream is(eq);
    std::string token = "";
    bool flag = false, xPos = false;
    int xsign = 1, sig = 1;
    int left = 0, right = 0;
    while (is >> token)
    {
        if (token == "-") sig = -1;
        if (token == "+") sig = 1;
        if (token == "x") xsign = sig;
        if (token == "=") 
        {
            flag = true; 
            sig = 1; 
        }
        if(!flag)
            if (token != "x" && token != "+" && token != "-" && token != "=") 
                left += sig * std::stoi(token);
        if (flag)
        {
            if (token == "x") 
                xPos = true;
            if (token != "x" && token != "+" && token != "-" && token != "=") 
                right += sig * std::stoi(token);
        }
    }
    if (!xPos) return (right - left) * xsign; 
    else return (left - right) * xsign;
}

int main(int argc, char* argv[])
{
    std::string input = "x + 18 - 6 = 10 - 25";
    std::cout << "Input: " << input << "\n";
    std::cout << "Output: " << solve(input) << "\n\n";
    return 0;
}