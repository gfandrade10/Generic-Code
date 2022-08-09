#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <numeric>

#define PRINT_VPLL(X) do{                                 \
    for(auto &e:X)                                        \
        std::cout << e.first << "\t" << e.second << "\n"; \
    std::cout << std::endl;                               \
} while(0)

class SumSquaredDivisors
{
    using ll = long long;
    using vpll = std::vector<std::pair<ll,ll>>;
  
    public:
    static inline bool isSquare(ll num)
    {
        long double val = std::sqrt(num);
        return val == (ll) val;
    }

    static vpll listSquared(ll m, ll n)
    {
        vpll res;
        auto sqs = [](std::vector<ll> &v) -> void { for(auto &e:v) e *= e; };
        for(int i = m; i <= n; ++i)
        {
            std::vector<ll> divs{};
            for(int j = 1; j <= i/2; ++j)
                if(i%j == 0) divs.push_back(j);
            divs.push_back(i);
            sqs(divs);
            ll tmp = std::accumulate(divs.begin(), divs.end(),0);
            if(isSquare(tmp))
                res.push_back(std::make_pair(i,tmp));
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    auto res = SumSquaredDivisors::listSquared(atoi(argv[1]),atoi(argv[2]));
    PRINT_VPLL(res);
    return 0;
}