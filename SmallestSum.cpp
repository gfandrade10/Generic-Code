#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using ULL = unsigned long long;

std::pair<ULL,ULL> max_and_pos(vector<ULL> arr)
{
    ULL max = 0, max2 = 0;
    ULL *posMax;
    for(auto& e:arr)
        if (e > max) { max = e; posMax = &e; }

    for(auto& e:arr)
        if (e < max && e > max2) max2 = e;

    return std::make_pair(max - max2, posMax - &arr[0]);
}

ULL solution(const vector<ULL>& arr)
{
    if (arr.size() == 0) return 0;
    else if (arr.size() == 1) return arr[0];

    vector<ULL> buffer = arr;
    std::pair<ULL,ULL> p;
    size_t count = 1;
    while(count)
    {
        count = 0;
        for(auto& e:buffer)
        {
            if(e == 1) return arr.size();
            if(e != buffer[0]) count++;
        }
        if(count)
        {
            p = max_and_pos(buffer);
            buffer[p.second] = p.first; 
        }
        else break;
    }
    return buffer[0] * (ULL)buffer.size();
}

int main(int argc, char const *argv[])
{
    vector<ULL> arr = {6,6,3};
    std::cout << "Sum: " << solution(arr) << "\n\n";
    return 0;
}
