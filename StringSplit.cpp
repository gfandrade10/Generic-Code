#include <iostream>
#include <string>
#include <vector>

using std::string;
using VectorS = std::vector<string>;

VectorS solution(const string& s)
{
    if (s.length() == 0) return {};
    VectorS Solu;
    std::vector<char> buffer(2);
    for (size_t i = 0; i < s.length(); i+=2)
    {   
        if( s.length()%2 == 0 || (s.length()%2 != 0 && i < (s.length()-2)) )
        { 
            buffer[0] = s[i]; buffer[1] = s[i+1];
            Solu.push_back( string(buffer.begin(), buffer.end()) );
        }
        else
        {
            buffer[0] = s[i]; buffer[1] = '_';
            Solu.push_back( string(buffer.begin(), buffer.end()) );
        }
    }
    return Solu;
}

int main(int argc, char const *argv[])
{
    VectorS Solu = solution("Gui");
    for (const auto& e:Solu)
        std::cout << e << std::endl;
    std::cin.get();
    return 0;
}