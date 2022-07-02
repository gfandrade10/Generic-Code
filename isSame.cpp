#include <vector>
#include <iostream>
#include <algorithm>

class Same 
{
    using Vector = std::vector<int>;

    public:
    static bool comp(Vector& a, Vector& b) 
    { 
        for(auto e:a) std::cout << e << " ";
        std::cout << "  ||  ";
        for(auto e:b) std::cout << e << " "; std::cout << "\n\n";
        b.push_back(0);
        for(auto& e: a)
        {
            if(*std::find(b.begin(), b.end(), e*e) != 0)
                b.erase(std::find(b.begin(), b.end(), e*e));

            else if(*std::find(b.begin(), b.end(), std::abs(e)) != 0)
                b.erase(std::find(b.begin(), b.end(), std::abs(e)));
        }
        if(b.size() == 1) return true;
        else return false;
    }
};

int main (int argc, char* argv[])
{
    std::vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
    std::vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
    std::cout << Same::comp (a,b) << "\n\n";
    return 0;
}