#include <iostream>
#include <string>

std::string encrypt(std::string text, int n)
{
    size_t len = text.length();
    std::string buffer = text;

    while(n > 0)
    {
        size_t j = 0;
        for(size_t i = 1; i < len; i += 2)
            buffer[j++] = text[i];
        
        for(size_t i = 0; i < len; i += 2)
            buffer[j++] = text[i];

        text = buffer;
        n--;
    }
    return text;
}

std::string decrypt(std::string text, int n)
{
    size_t len = text.length();
    std::string buffer = text;
       
    while(n > 0)
    {
        size_t j = 0;
        for(size_t i = len/2; i < len; i++)
        {
            buffer[j++] = text[i];
            buffer[j++] = text[i - len/2];
        }        
        text = buffer;
        n--;
    }
    return text;
}

int main (int argc, char *argv[])
{
    std::string text = "This is a test!";
    std::string res = encrypt(text, 3);
    std::string final = decrypt(res, 3);
    std::cout << res << "\n";
    std::cout << final << "\n\n";
    return 0;
}
