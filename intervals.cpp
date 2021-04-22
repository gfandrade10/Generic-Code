#include <iostream>
#include <string>
#include <vector>

std::string range_extraction(const std::vector<int>& args) 
{
    int storage, counter = 0;
    bool flag = false;
    std::string result;
    for (size_t i = 1; i <= args.size(); ++i)
    {
        if(args[i] == (args[i-1] + 1))
        {
            if(!flag) storage = args[i-1];
            flag = true;
            counter++;
        }
        else
        {
            if(flag)
            {
                if(counter > 1)
                result += std::to_string(storage) + "-" + std::to_string(args[i-1]) + ",";
                else
                result += std::to_string(storage) + "," + std::to_string(args[i-1]) + ",";
                flag = false;
                counter = 0;
            }
           
            else result += std::to_string(args[i-1]) + ",";
        }
    }
    return result.substr(0, result.length() - 1);
}

int main(int argc, char** argv)
{
    std::vector<int> vec = {-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20,26,27,28,29,36};
    std::cout << range_extraction(vec) << std::endl;
    return EXIT_SUCCESS;
}