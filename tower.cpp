#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> towerBuilder(unsigned nFloors) 
{
    if(nFloors == 0) return {};
    if(nFloors == 1) return {"*"};
    unsigned max = 2*nFloors - 1;
    unsigned i, j;
    std::string buffer;
    std::vector<std::string> res;

    for(unsigned i = 0; i < max; ++i)
        buffer.push_back(' ');

    for(i = max/2, j = max/2; i >= 0 && j < buffer.length(); --i, ++j)
    {
        buffer[j] = '*';
        buffer[i] = '*';
        res.push_back(buffer);       
    }
    return res;
}

int main (int argc, char **argv)
{
    unsigned n = (unsigned) atoi(argv[1]);
    for (auto &e: towerBuilder(n))
        std::cout << e << "\n";
    std::cout << std::endl;
    return 0;
}