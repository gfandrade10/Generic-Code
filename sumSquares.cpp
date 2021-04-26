#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int sum_of_squares(int n)
{   
    if (n < 4) return n;
    std::vector<int> vec, ans;
	int count, sum, i = 1;
	while(1)
	{
        if( (i*i) > n ) break;
		vec.push_back(i*i);
		++i;		
	}
    i = vec.size() - 1;

    auto Sum = [&](int s)->int
    {sum = 0; count = 0; while (sum != n)
    { if(vec[s] + sum <= n) {sum += vec[s]; count++;}
    else s--;} return count;};

    int aux = 0;
    if(n < 10)
    {
        for(int j = i; j >= 1; j--)
        {
            ans.push_back(Sum(j));
            if(ans[aux] == 1 || ans[aux] == 2) break;
            aux++;
        }
    }
    else
    {
        for(int j = i; j >= 2; j--)
        {
            ans.push_back(Sum(j));
            if(ans[aux] == 1 || ans[aux] == 2) break;
            aux++;
        }
    }
    return *std::min_element(ans.begin(), ans.end());
}

int main()
{
    std::cout << sum_of_squares(15000) << std::endl;
	return 0;
}