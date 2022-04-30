#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>

typedef std::vector<std::string> VECS;

class WhichAreIn
{
  public:
    static VECS inArray(VECS &array1, VECS &array2);
};

VECS WhichAreIn::inArray(VECS &array1, VECS &array2)
{
    VECS res = {};
    std::map<std::string,int> Map;
    for (const auto& e: array1)
    {
        std::string buffer = "(" + e + "\\(\\).*?)|" + "(" + e + ".*?)";
        std::regex rgx(buffer);
        std::smatch match;
        for (const auto& f: array2)
        {
            if (std::regex_search(f.begin(), f.end(), match, rgx))
                Map[match[0]]++;
        }
    }
    for (auto &e :Map) res.push_back(e.first);
    return res;
}

int main(int argc, char **argv)
{
    VECS arr1 = { "arp", "live", "strong" };;
    VECS arr2 = { "lively", "alive", "harp", "sharp", "armstrong" };    
    VECS res = WhichAreIn::inArray(arr1,arr2);
    for (const auto &e: res)
        if (!e.empty()) std::cout << e << "\t";
    std::cout << "\n\n";
    return 0;
}
