#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

//without using std::next_permutation
long long nextBigger (long long n) 
{
    using si = std::string::iterator;
    std::string manip = std::to_string(n);

    if (manip.length() == 1)
        return -1;
        
    si p1, p2;
    long long j = 1, i = manip.length()-j, dist = LLONG_MIN;
    bool flag = false;

    while (i >= 0)
    {
        char ref = manip[manip.length()-j]; 
        if (manip[i] < ref && (si) &manip[i] - manip.begin() > dist)
        {
            p1 = (si) &manip[manip.length()-j];
            p2 = (si) &manip[i];
            dist = p2 - manip.begin();
            flag = true;
        }
        if (i == 0)
        {
            ++j;
            i = manip.length()-j;
        }
        --i;
    }

    if (flag)
    {
        auto func = [](char &a, char &b) ->bool { return a < b; };
        std::swap(manip[p1-manip.begin()], manip[p2-manip.begin()]);
        std::sort(++p2, manip.end(), func);
    }
    
    long long res = std::stoll(manip);  
    return (res == n) ? -1 : res;
}

int main (int argc, char **argv)
{
    long long input = atoll(argv[1]);
    std::cout << nextBigger(input) << "\n\n";
    return 0;
}