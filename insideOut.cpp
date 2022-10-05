#include <iostream>
#include <sstream>
#include <algorithm>

std::string strmodify (std::string&& input)
{
    if (input.length() < 4) return input;
    size_t V1 = input.length()/2 - 1, V2, j;
    input.length() % 2 == 0 ? V2 = V1+1 : V2 = V1+2;
    j = input.length() - 1;

    for (size_t i = 0; i < input.length()/2; ++i)
    {
        if (i > V1) break;
        std::swap(input[i], input[V1--]);
        std::swap(input[V2++], input[j--]);
    }
    return input;
}

std::string insideOut (std::string x)
{
    std::istringstream is(x);
    std::ostringstream os;
    std::string buffer;
    while (is >> buffer)
        os << strmodify(std::move(buffer)) << " ";    
    return os.str().substr(0, os.str().length() - 1);
}

int main(int argc, char* argv[])
{
    std::cout << insideOut("take bintang and a dance please");
    std::cout << "\n\n";
    return 0;
}