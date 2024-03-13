#include <iostream>
#include <vector>

class Kata
{
    public:
    static std::vector<int> foldArray(std::vector<int> array, int runs)
    {
        if (runs == 0)
            return array;
        
        int finalLen;
        int len = static_cast<int>(array.size());
        while(runs)
        {
            int foldingPoint = len/2;
            for(int i = 0; i < foldingPoint; i++)
                array[i] = array[i] + array[len - i - 1];

            if(len%2 == 0)
                len = foldingPoint;
            else
                len = foldingPoint + 1;

            if(runs == 1)
                finalLen = len;

            runs--;
        }
        array.resize(finalLen);
        return array;
    }
};

int main (int argc, char *argv[])
{
    std::vector<int> v = {1,2,3,4,5};
    int runs = 2;
    auto res = Kata::foldArray(v, runs);

    for(const auto& e: res)
        std::cout << e << "  ";

    std::cout << "\n\n";
    return 0;
}
