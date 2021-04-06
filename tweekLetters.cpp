#include <iostream>
#include <vector>
#include <functional>

std::string tweakLetters(std::string s, std::vector<int> arr) 
{
	char buffer[s.length()];
    for(int i=0; i< (int)arr.size(); i++)
    {
        buffer[i] = s[i];
        if(buffer[i] == 'a' && arr[i] == -1)
            buffer[i] = 'z';
        else if (buffer[i] == 'z' && arr[i] == 1)
            buffer[i] = 'a';
        else
            buffer[i] += arr[i];
    }
    return std::string(buffer, buffer + sizeof(buffer));
}

int main(int argc, char const *argv[])
{
    std::cout << tweakLetters("abc", {-1, -1, -1}) << std::endl;

    std::cin.get();
    return 0;
}
