#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::string uint32_to_ip(uint32_t ip)
{
    std::uint32_t ip1 = ip >> 24;
    std::uint32_t ip2 = (ip - (ip1 << 24)) >> 16;
    std::uint32_t ip3 = (ip - (ip1 << 24) - (ip2 << 16)) >> 8;
    std::uint32_t ip4 = ip - (ip1 << 24) - (ip2 << 16) - (ip3 << 8);

    std::string res = std::to_string(ip1) + "." + std::to_string(ip2) +
        "." + std::to_string(ip3) + "." + std::to_string(ip4);

    return res;
}

int main(int argc, char* argv[])
{
    std::size_t i = atoi(argv[1]);
    std::cout << uint32_to_ip(i) << "\n\n";
    return 0;
}