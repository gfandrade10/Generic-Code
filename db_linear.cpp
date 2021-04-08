#include <iostream>
#include <vector>
#include <map>

#ifndef YCalc
    #define YCalc(x) (2*x + 1)
#endif

#ifndef ZCalc
    #define ZCalc(x) (3*x + 1)
#endif

namespace DoubleLinear
{
    int dblLinear(int n)
    {
        int counter = 0;
        std::map<int,int> mymap;
        mymap.insert(std::pair<int,int>(1,1));                
        
        mymap[YCalc(1)]++;
        mymap[ZCalc(1)]++;
        
        for(auto& e:mymap)
        {
            mymap[YCalc(e.first)]++;
            mymap[ZCalc(e.first)]++;
            if (mymap.size() >= n+10) break;
        }
            
        for(const auto& e:mymap)
        {
            if(counter == n) return e.first;
            counter++;
        }
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    std:: cout << DoubleLinear::dblLinear(50) << std::endl;
    std::cin.get();
    return 0;
}