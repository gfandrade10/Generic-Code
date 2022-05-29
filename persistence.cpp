#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;

int persistence(ll n)
{
    if (n < 10) return 0;
    bool flag = true;
    int count = 0;
    while (flag)
    {
        flag = false;
        ll val = 1;
        std::string nums = std::to_string(n);
        for (auto &&e: nums)
            val *= (ll)(e - '0');
        if(val > 9)
        {
           flag = true;
           n = val;
           count++;
        }
    }
    return count + 1;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    std:: cout << persistence(n) << "\n\n";
    return 0;
}