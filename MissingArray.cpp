#include <vector>
#include <algorithm>
#include <iostream>

template<class T>
int getLengthOfMissingArray(std::vector<std::vector<T>>& arrayOfArrays)
{
    if (arrayOfArrays.empty()) return 0;
    if (arrayOfArrays[0].empty()) return 0;
    auto cmp = [](std::vector<T> t1, std::vector<T> t2) -> bool
    { return t1.size() < t2.size(); };
    std::sort(arrayOfArrays.begin(), arrayOfArrays.end(), cmp);

    int res = 0;
    bool flag = false;
    for (size_t i = 1; i < arrayOfArrays.size(); ++i)
    {
        if(arrayOfArrays[i].empty()) return 0;
        if (arrayOfArrays[i].size() - arrayOfArrays[i - 1].size() > 1)
        {
            res = arrayOfArrays[i-1].size() + 1;
            flag = true;
        } 
    } 
    if (flag && arrayOfArrays.size() != 2) return res;
    else return 0;
}

int main(int argc, char* argv[])
{ 
    std::vector<std::vector<int>> testInput = { {1,2}, {4,5,1}, {1}, {5,6,7,8,9} };
    std::cout << getLengthOfMissingArray(testInput) << "\n\n";
    return 0;
}