#include <iostream>
#include <string>
#include <algorithm>

using i64 = long long int;

class Kata
{
    public:
    static bool validate(i64 n);
};

bool Kata::validate(i64 n)
{
    std::string num = std::to_string(n);
    int len = static_cast<int>(num.length());
    int sum = 0;

    std::reverse(num.begin(), num.end());
    for (int i = 0; i < len; ++i)
    {
        if((i+1)%2 != 0)
        {
            sum += num[i] - '0';
        }
        else
        {
            int tmp = static_cast<int>(num[i] - '0') * 2;
            if (tmp > 9)
                tmp -= 9;
            sum += tmp;
        }
    }
    return sum % 10 == 0;
}

void PrintBool(bool input)
{
    if(input)
        std::cout << "TRUE\n\n";
    else
        std::cout << "FALSE\n\n";
}

int main (int argc, char *argv[])
{
    i64 input = std::stoull(argv[1]);
    PrintBool(Kata::validate(input));
    return 0;
}
















































