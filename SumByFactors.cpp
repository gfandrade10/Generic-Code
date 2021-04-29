#include <iostream>
#include <string>
#include <vector>
#include <cmath>

namespace SumOfDivided
{
	#define MaxValue(vec,x,T) ({T val = -2147483648; for(const auto& e:vec) \
	{if(abs(e) > val) val = abs(e);} x = val;})

	std::vector<int> Primes (const int& n)
	{
		std::vector<int> primes;
		primes.push_back(2);
		int count;
		for (int i = 3; i <= n; i += 2)
		{
			count = 0;
			for (int j = 3; j < i; j += 2)
			{ if(i%j == 0) count++;	}
			if(count == 0) primes.push_back(i);
		}
		return primes;
	}

	std::string sumOfDivided(const std::vector<int>& lst)
	{
		auto Module = [](const int& a, const int& b)->std::string
		{return "(" + std::to_string(a) + " " + std::to_string(b) + ")";};

		std::string res = "";
		int max;
		MaxValue(lst, max, int);
		std::vector<int> primes = Primes(max);
		for(const auto& e:primes)
		{
			int sum = 0;
			for(const auto& i:lst)
			{ if (i%e == 0) sum += i; }
			if(sum) res += Module(e,sum);	
		}
		return res;
	}
}

int main()
{
	std::vector<int> vec = {107, 158, 204, 100, 118, 123, 126, 110, 116, 100};
	std::cout << SumOfDivided::sumOfDivided(vec) << std::endl;
	return 0;
}
