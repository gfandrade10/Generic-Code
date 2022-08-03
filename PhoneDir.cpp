#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <sstream>

class PhoneDir
{
    using VS = std::vector<std::string>;

    public:
    static VS BreakDown (const std::string &str)
    {
        VS res;
        char text[str.length() + 1];
        for (size_t i = 0; i < str.length(); i++)
            text[i] = str[i];
        text[str.length()] = '\0';
        char *p = strtok(text, "\n");
        while(p != NULL)
        {
            std::string buffer(p);
            res.push_back(buffer);
            p = strtok(NULL, "\n");
        }
        return res;
    }

    static std::string phone(const std::string& orgdr, std::string num)
    {
        VS data = BreakDown(orgdr); 
        std::string str1 = "(\\+" + num + ")";
        std::regex rg1(str1);
        std::smatch s1;
        int count = 0;
        std::string usage;
        for(auto &e: data)
        {
            if(std::regex_search(e, s1, rg1))
            {
                count++;
                usage = e;
            }
        }
        if (count == 0) return ("Error => Not found: " + num);
        if (count > 1) return ("Error => Too many people: " + num);
        std::regex rg2 ("((<).*?(>))");
        std::regex rg3 ("((\\+).*?([0-9]).*?(-).*?([0-9]).*?(-).*?([0-9]).*?(-).*?([0-9])*)");
        std::smatch s2;
        std::string res = "Phone => " + num;
        std::regex_search(usage, s2, rg2);
        res += ", Name => " + s2.str().substr(1,s2.str().length()-2);
        res += ", Address => ";
        usage = std::regex_replace(usage, rg2, ""); 
        usage = std::regex_replace(usage, rg3, "");
      
        char text[usage.length()+1];
        for(size_t i = 0; i < usage.length(); ++i)
            text[i] = usage[i];
        text[usage.length()] = '\0';
        char *p = strtok(text, " */_;$?,:");
        while (p != NULL)
        {
            std::string buffer (p);
            res += buffer + " ";
            p = strtok(NULL, " */_;$?,:");
        }
        return res.substr(0,res.length()-1);
    }
};

int main(int argc, char* argv[])
{
    std::string input = "/+1-541-754-3010 156 Alphand_St. <J Steeve>\n 133, Green, Rd. <E Kustur> NY-56423 ;+1-541-914-3010";
    std::string num = "1-541-914-3010";
    std::cout << PhoneDir::phone(input,num) << "\n\n";
    return 0;
}