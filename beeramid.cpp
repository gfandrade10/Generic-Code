#include <iostream>
#include <vector>

int beeramid(int bonus, double price)
{
    if (price > (double)bonus || bonus <= 0)
        return 0;

    int stacks = 1, total = int((double)bonus/price);
    bool flag = false;
    for (int sum = 0; sum < total; stacks++)
    {
        sum += stacks * stacks;
        if (sum == total) 
            flag = true;
    }
    stacks--;
    if (!flag)
        return stacks - 1;
    else
        return stacks;
}

int main(int argc, char **argv)
{
    std::cout << beeramid(21, 1.5) << "\n\n";
    return 0;
}