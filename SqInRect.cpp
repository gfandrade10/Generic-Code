#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

class SqInRect
{
    public:
    static std::vector<int> sqInRect(int len, int wid)
    {
        if (len == wid)
            return {};

        std::array<int,2> Rectangle = {len, wid};
        std::sort(Rectangle.begin(), Rectangle.end());

        std::vector<int> Ans;
        while(Rectangle[0] > 0)
        {
            Ans.push_back(Rectangle[0]);
            Rectangle[1] -= Rectangle[0];
            std::sort(Rectangle.begin(), Rectangle.end());
        }
        return Ans;
    }
};

int main(int argc, char const *argv[])
{
    auto vec = SqInRect::sqInRect(5, 3);
    for(const auto& e: vec)
        std::cout << e << "  ";
    std::cout << "\n\n";
    return 0;
}
