#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<int> Vec;
typedef std::vector<int>::iterator VecIt;

inline int NextElement (const Vec& vec, int Jump, int LastPos)
{
    std::size_t num = vec.size();
    bool JumpFlag = false;
    for(int i = 0; i < Jump; ++i)
    {
        LastPos++;
        if (LastPos > num)
        {
            LastPos = 0;
            JumpFlag = true;
        }
        if (JumpFlag)
        {
            LastPos++;
            JumpFlag = false;
        }
    }
    if (LastPos!= 0) return LastPos - 1;
    else return 0;
}

inline Vec DeleteElement(Vec&& vec, Vec& mod, const VecIt& it)
{
    auto iter = vec.begin();
    Vec result;
    for(; iter != vec.end(); ++iter)
    {
        if(iter != it)
            result.push_back(*iter);
        else
            mod.push_back(*iter);
    }
    return result;
}

Vec josephus(Vec items, int k) 
{
    if (items.empty()) return {};
    Vec result;
    std::size_t fixed = items.size(); 
    VecIt it = items.begin();
    int pos = 0;
    for (std::size_t i = 0; i < fixed; ++i)
    {
        pos = NextElement(items,k,pos);
        it = (VecIt) &items[pos];
        items = DeleteElement(std::move(items), result, it);        
    }
    return result;
}

int main(int argc, char **argv) 
{
    Vec input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto& e: josephus(input, 15))
        std::cout << e << " ";
    std::cout << "\n\n";
    return 0;
}