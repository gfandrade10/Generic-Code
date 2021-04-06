#include <iostream>
#include <algorithm>
#include <string.h>

std::string caesarCipher(std::string s, int k) 
{
    if (k>=26)
    {
        k = (k%26);
    }
	char buffer[s.length()];
    int let;
    for(int i=0; i<(int)s.length();i++)
        buffer[i] = s[i];

    for(int i=0; i<(int)s.length(); i++)
    {   if (buffer[i] >= 'A' && buffer[i] <='Z')
        {
            let = (int)buffer[i];
            let += k;
            if(let > (int)'Z')
                let = let - (int)'Z' + (int)'A' - 1;
            buffer[i] = (char)let;
        }
        else if (buffer[i] >= 'a' && buffer[i] <='z')
        {
            let = (int)buffer[i];
            let += k; 
            if(let > (int)'z')
                let = let - (int)'z' + (int)'a' - 1;
            buffer[i] = (char)let;
        }
    }
    return std::string(buffer, buffer + sizeof(buffer));
}

int main(int argc, char const *argv[])
{
    std::cout << caesarCipher("Apple.", 1) << std::endl;

    std::cin.get();
    return EXIT_SUCCESS;
}
//Xwyg pk Omqwna Kja eo w lklqhwn owuejc pdwp iawjo w lanokj dwo pk opwnp kran, oeiehwn pk: xwyg pk pda znwsejc xkwnz.