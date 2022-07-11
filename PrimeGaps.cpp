#include <iostream>
#include <vector>
#include <utility>

class GapInPrimes
{
    using ll = long long;
    using llp = std::pair<ll,ll>;

    public:
    static llp gap(int g, ll m, ll n) 
    {
        if (m > 2 && g%2 != 0) return {0, 0};
        std::vector<ll> primes;
        bool flag;
      
        if (m > 2 && m%2 == 0) 
            ++m;
        ll c = 0;
        for (ll i = m; i <= n; i+=2)
        {
            flag = true;
            for (ll j = 3; j < i; j+=2)
            {   
                if (i % j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                primes.push_back(i);
                c++;
            }
            if (primes.size() > 1)
            {
                if (primes[c-1] - primes[c-2] == g)
                    return std::make_pair(primes[c-2], primes[c-1]);
            }
        }
        return {0, 0};
    }
};

int main (int argc, char* argv[])
{
    auto p = GapInPrimes::gap(6,350,450);
    std::cout << p.first << "  " << p.second << "\n\n";
    return 0;
}