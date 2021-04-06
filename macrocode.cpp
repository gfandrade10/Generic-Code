#include <iostream>
#include <vector>

#define Swap(x,y,T) {T var = x; x = y; y = var;}

#define PrintVec(x)                     \
{for(int i=0; i < (int)x.size(); i++)   \
std::cout << x[i] <<" ";                \
std::cout << std::endl; }

#define SquareVec(x)                    \
{for(int i=0; i < (int)x.size(); i++)   \
x[i] *= x[i]; }

int main(int argc, char const *argv[])
{
    std::string S1 = "Gui";
    std::string S2 = "Bela";
    std::vector<int> vec = {1,2,3,4,5};
    std::vector<char> vec2 = {'A', 'B', 'C', 'D', 'E', 'F'};
    std::vector<std::string> names = {"Bom", "dia", "a", "todos."};
    std::cout << "1: " << S1 << "\n2: " << S2 << "\n\n";
    Swap(S1, S2, std::string);
    std::cout << "1: " << S1 << "\n2: " << S2 << "\n\n";
    PrintVec(vec);
    PrintVec(vec2);
    PrintVec(names);
    SquareVec(vec);
    PrintVec(vec);
    std::cin.get();
    return 0;
}