#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

std::string reverseOdd(std::string str) {
    std::stringstream SStr(str);
	std::string buffer;
    std::string result;

    while(SStr >> buffer)
    {
        if(buffer.length()%2 != 0)
            std::reverse(buffer.begin(), buffer.end());

        result += buffer + " ";
    }
    result.erase(result.length()-1, result.length());
    return result;
}

int main()
{
    std::string words = "Odd odd odd odd odd odd odd odd odd odd odd";
    std::cout << reverseOdd(words) << std::endl;

    std::cin.get();
    return 0;
}