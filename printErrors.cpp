#include <iostream>
#include <string>

class Printer
{
public:
    static std::string printerError(const std::string &s);
};

std::string Printer::printerError(const std::string &s)
{
    std::string result;
    int counter = 0;
    for(int i=0; i<(int)s.length(); i++)
    {
        if (s[i] > 'm')
            counter++;
    }
    result += std::to_string(counter) + '/' + std::to_string(s.length());
    return result;
}

int main(int argc, char const *argv[])
{
    Printer obj;
    std::cout << obj.printerError("aaaxbbbbyyhwawiwjjjwwm") << std::endl;
    std::cin.get();
    return 0;
}