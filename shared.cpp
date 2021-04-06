#include <vector>
#include <iostream>
#include <string.h>
#include <string>

std::string findNemo(std::string sentence) 
{
    char buffer[sentence.length()];
    for (int i=0; i<(int)sentence.length(); i++)
    {
        buffer[i] = sentence[i];
    }
    bool flag = true;
	char *ptr = strtok(buffer, " ");
    int count = 1;
    while(ptr != NULL)
    {
        std::string buf(ptr);
        if (buf == "Nemo")
        {
            flag = false;
            break;
        }
        count++;  
        ptr = strtok(NULL, " ");
    }
    if(flag)
    {
        return "I can't find Nemo :(";
    }
    return ("I found Nemo at " + std::to_string(count) + "!");
}

int main()
{
    std::string name = "I am finding Nemo !";
    std::cout << findNemo(name) << std::endl;

    std::cing.get();
    return 0;
}