#include <iostream>
#include <string>

std::string cleanString(const std::string &s) 
{
    char text[s.length()];
    int back_counter = 0;
    for(int i = s.length()-1; i >= 0; i--)
    {
        if(s[i] != '#' && back_counter == 0)
            text[i] = s[i];
        else if (s[i] != '#' && back_counter > 0)
        {
            text[i] = '#';
            back_counter--;
        }
        else if (s[i] == '#')
        {
            back_counter++;
            text[i] = '#';
        }
    }
    char res[s.length()+1];
    int index = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(text[i] != '#')
            res[index++] = text[i];
    }
    res[index] = '\0';
    return std::string(res);
}

int main(int argc, char **argv)
{
    std::string text(argv[1]);
    std::cout << "Original input: " << text << "\n";
    std::cout << "Result: " << cleanString(text) << "\n\n";
    return 0;
}