#include <cstddef>
#include <iostream>
#include <stack>
#include <string>
#include <string_view>
#include <vector>

std::string remove_parenthesis(std::string_view sv)
{
    if(sv.empty()) return "";

    std::vector<std::string_view> words{};
    std::stack<const char*> cutting_points{};
    size_t len = sv.length();
    const char* pstart = &sv[0];

    for(size_t i = 0; i < len; ++i)
    {
        if(sv[i] == '(')
            cutting_points.push(&sv[i]);

        if(sv[i] == ')' && !cutting_points.empty()) 
        {
            auto temp = cutting_points.top();
            cutting_points.pop();

            if(i > 0 && cutting_points.empty())
            {
                words.emplace_back(pstart, temp);
                if (i + 1 < len)
                    pstart = &sv[i+1];

                if(i == len - 1)
                    break;
            }

            if(i == len - 1)
            {
                if(cutting_points.empty())
                    words.emplace_back(pstart, &sv[i]+1);
                else
                    words.emplace_back(pstart,cutting_points.top()+1);
            }
        }

        else if(i == len - 1)
        {
            if(cutting_points.empty())
                words.emplace_back(pstart, &sv[i]+1);
            else
                words.emplace_back(pstart,cutting_points.top()+1);
        }
    }

    std::string ans{};
    ans.reserve(sv.size());
    for(const auto& s: words)
        ans += s;

    return ans;
}

int main () 
{
    std::string s = "a)b(c)d";
    std::string res = remove_parenthesis(s);

    std::cout << s << "\n" << res << "\n\n";
    return 0;
}
