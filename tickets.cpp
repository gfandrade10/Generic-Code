#include <iostream>
#include <vector>
#include <map>

std::string tickets(const std::vector<int>& peopleInLine)
{
    std::map<size_t,size_t> bills;
    bills.insert(std::pair<size_t,size_t>(25,0));
    bills.insert(std::pair<size_t,size_t>(50,0));
    bills.insert(std::pair<size_t,size_t>(100,0));

    for(const auto& m:peopleInLine)
    {
        if (bills.find(m)->first)
            {bills[m]++;}

        if (m == 25)
            continue;

        else if (m == 50)
        {
            if(bills[25] > 0)
                bills[25]--;
            else
                return "NO";
        }
        else
        {
            if (bills[25] > 0 && bills[50] > 0)
            {
                bills[25]--;
                bills[50]--;
            }
            else if (bills[25] > 2)
                bills[25] -= 3;
            else
                return "NO";
        }        
    }
    return "YES";
}

int main(int argc, char const *argv[])
{
    std::cout << tickets({25, 25, 50}) << std::endl;
    std::cin.get();
    return 0;
}