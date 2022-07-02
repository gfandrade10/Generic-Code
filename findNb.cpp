#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

class ASum
{
    using ll = long long;

    public:
    static ll findNb(ll&& m)
    {
        ll total = m+1, i;
        long double start = std::pow(m,0.28);
        i = (ll)start;
        while (total > m)
        {
            total = 0;
            for(ll j = i-1; j >= 0; --j)
             {
                total += (i-j)*(i-j)*(i-j);
                if(LLONG_MAX - total < LLONG_MAX/2)
                    { i-=1000; break; }
             }
            if (total == m) return i;
            --i;
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
    long long x = (long long) atoi(argv[1]);
    std::cout << x << "\n" << ASum::findNb(std::move(x)) << "\n\n";
    return 0;
}