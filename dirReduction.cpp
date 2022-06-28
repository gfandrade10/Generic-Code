#include <iostream>
#include <vector>

using VectorStr = std::vector<std::string>;
using VSit = VectorStr::iterator;

class DirReduction
{
    public:
    static void Reduce(VectorStr& res, VSit& iter)
    {
        bool flag = true;
        if (*iter == "NORTH" && !res.empty()) {
            for (auto it = (VSit)&res[res.size() - 1]; it >= res.begin(); --it)
                if (*it == "SOUTH")  { res.erase(it); flag = false; break; }
        }
        else if (*iter == "SOUTH" && !res.empty()) {
            for (auto it = (VSit)&res[res.size() - 1]; it >= res.begin(); --it)
                if (*it == "NORTH")  { res.erase(it); flag = false; break; }
        }
        else if (*iter == "EAST" && !res.empty()) {
            for (auto it = (VSit)&res[res.size() - 1]; it >= res.begin(); --it)
                if (*it == "WEST")  { res.erase(it); flag = false; break; }
        }
        else if (*iter == "WEST" && !res.empty()) {
            for (auto it = (VSit)&res[res.size() - 1]; it >= res.begin(); --it)
                if (*it == "EAST") { res.erase(it); flag = false; break; }
        }
        if(flag) res.push_back(*iter);
    }

    static VectorStr dirReduc(VectorStr& arr)
    {   
        if(arr.empty()) return {};
        VectorStr res = {};
        for(auto it = arr.begin(); it != arr.end(); ++it)
            Reduce(res,it);
        return res;
    }        
};

int main(int argc, char *argv[])
{
    VectorStr res = {"NORTH", "NORTH", "SOUTH", "EAST"};
    for(auto e: DirReduction::dirReduc(res))
        std::cout << e << "  ";
    std::cout << "\n\n";
    return 0;
}