#include <cstdint>
#include <string>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <string_view>

[[nodiscard]] inline int64_t getNumber(std::string_view sv, int& counter, int sign, size_t& pos)
{
    std::string buffer = "";
    while(std::isdigit(sv[pos]))
    {
        buffer.push_back(sv[pos++]);
    }
    counter++;
    return std::stoll(buffer) * (int64_t)sign;
}

std::string quadratic_builder(std::string const& expression)
{
    std::cout << expression << "\n";
    int64_t a = 0, b = 0, c = 0, d = 0; //constants
    char var = 0;

    //regex pattern ->parenthesis
    std::regex rgx(R"(\([a-z0-9+-]+\))");
    std::sregex_token_iterator it(expression.begin(), expression.end(), rgx, 0);
    std::sregex_token_iterator end;

    //parsing
    int counter = 1;
    int token = 1;
    for(; it != end; ++it)
    {
        std::string temp(*it);
        size_t len = temp.length();
        int sign = 1;

        for(size_t i = 1; i < len - 1; ++i)
        {
            if(temp[i] == '-') sign = -1;
            if(temp[i] == '+') sign = 1;
            if(std::isdigit(temp[i]) && counter == 1)      { a = getNumber(temp, counter, sign, i); }
            else if(std::isdigit(temp[i]) && counter == 2) { b = getNumber(temp, counter, sign, i); }
            else if(std::isdigit(temp[i]) && counter == 3) { c = getNumber(temp, counter, sign, i); }
            else if(std::isdigit(temp[i]) && counter == 4) { d = getNumber(temp, counter, sign, i); }
            if(std::isalpha(temp[i]))
            {
                var = temp[i];
                if(token == 1 && a == 0) { a = sign; counter++; }
                else if(token == 2 && c == 0) { c = sign; counter++; }
            }
        }
        token++;
    }

    //result formatting
    std::ostringstream os;
    int64_t A = 0, B = 0, C = 0;
    
    A = a*c;
    B = a*d + b*c;
    C = b*d;

    if(A == 1) os << var << "^2";
    else if (A == -1) os << "-" << var << "^2";
    else if(A != 0) os << A << var << "^2";

    if(B > 0)
        os << "+";

    if(B == 1) os << var;
    else if (B == -1) os << "-" << var;
    else if(B != 0) os << B << var;

    if(C != 0)
    {
        if(C < 0) os << C;
        else os << "+" << C;
    }

    return os.str();
}

int main()
{
    std::string s = "(y-11)(55y+6)";
    auto exp = quadratic_builder(s);
    std::cout << exp << "\n";
}
