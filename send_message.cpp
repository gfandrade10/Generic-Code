#include <iostream>
#include <string>
#include <map>
#include <ctype.h>

//Primeiro digito é um identificador de botão para adicionar espaços
static std::map<char, std::string> values = {
    {'.',"_1"},{',',"_11"},{'?',"_111"},{'!',"_1111"},
	{'a',"12"},{'b',"122"},{'c',"1222"},
	{'d',"23"},{'e',"233"},{'f',"2333"},
	{'g',"34"},{'h',"344"},{'i',"3444"},
	{'j',"45"},{'k',"455"},{'l',"4555"},
	{'m',"56"},{'n',"566"},{'o',"5666"},
	{'p',"67"},{'q',"677"},{'r',"6777"},{'s',"67777"},
	{'t',"78"},{'u',"788"},{'v',"7888"},
	{'w',"89"},{'x',"899"},{'y',"8999"},{'z',"89999"},
	{'\'',"9*"},{'-',"9**"},{'+',"9***"},{'=',"9****"},
	{32,"00"} 
};

std::string send_message(const std::string& message)
{
    if (message.empty()) return "";
    std::string res = "";
    bool UpperFlag = true;
    bool LowerFlag = false;
    for (size_t i = 0; i < message.length(); ++i)
    {
        char c = message[i];
        if(isalpha(c) && (c >= 'A' && c <= 'Z'))
        {
            char j = tolower(c);
            std::string buffer = values[j];
            if (i > 0 && values[j][0] == values[ tolower(message[i-1]) ][0] )
                res += " ";
            if(!buffer.empty())
            {
                if (UpperFlag)
                {
                    if(res[res.length() - 1] == ' ') res.pop_back();
                    res += "#";
                }
                res += buffer.substr(1);
                UpperFlag = false;
            }
            LowerFlag = true;
        }
        else if (isdigit(c))
        {
            if(i > 0 && c == res[res.length() - 1])
                res += " ";
            res += std::to_string(c - '0');
            res += "-";
        }
        else if (c == '#' || c == '*')
        {
            if (i > 0 && res[res.length() - 1] == c)
                res += " ";
            res.push_back(c);
            res += "-";
        }
        else if (i > 0 
                && values[c][0] == values[message[i-1]][0]
                && res[res.length() - 1] != '#' 
        )
        { 
            res += " "; 
            if(!values[c].empty()) 
                res += values[c].substr(1);
        }
        else
        {
            if (isalpha(c) && LowerFlag)
            {
                if (res[res.length() - 1] == ' ') res.pop_back();
                res += "#";
                LowerFlag = false;
                UpperFlag = true;
            }
            std::string buffer = values[c];
            if(!buffer.empty()) 
                res += buffer.substr(1);
        }
    }
    return res;
}

int main(int argc, char* argv[])
{
    std::string input = "Doc, help";
    std::string result = send_message(input);
    std::cout << "Input: " << input << "\n";
    std::cout << "Result: " << result << "\n\n";
    return 0;
}