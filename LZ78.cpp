#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

std::string encoder(std::string const& data)
{
    std::vector<std::pair<unsigned int, std::string>> dictionary = {{0, ""}};
    unsigned int len = static_cast<unsigned int>(data.length());
    unsigned int index = 1;
    std::string temp;
    std::ostringstream os;

    auto findPair = [&]() {
        auto pred = [&](std::pair<unsigned int, std::string> const& p) { return p.second == temp; };
        auto it = std::find_if(dictionary.begin(), dictionary.end(), pred);
        return it;
    };
    
    for(unsigned int i = 0; i < len; ++i)
    {
        temp = "";
        temp.push_back(data[i]);
        unsigned int occurence = 0;
        auto it = findPair();

        for(; it != dictionary.end(); it = findPair())
        {
            if(i < len - 1) temp.push_back(data[i+1]);
            if(i >= len) break;
            occurence = it->first;
            i++;
        }

        os << occurence;
        if(!temp.empty())
        {
            if(!(i >= len - 1 && it != dictionary.end()))
                os << temp.back();
        }
        dictionary.emplace_back(index++, temp);
    }

    return os.str();
}

std::string decoder(std::string const& data)
{
    std::map<unsigned int, std::string> dictionary{{0, ""}};
    unsigned int counter = 1;
    size_t len = data.length();
    std::ostringstream os;
    
    for(size_t i = 0; i < len; )
    {
        if(std::isdigit(data[i]))
        {
            unsigned int j = 0;
            std::string numExtractor{};

            while(std::isdigit(data[i+j]))
            {
                numExtractor.push_back(data[i+j]);
                j++;
            }

            char letter = data[i+j];
            size_t index = std::stoul(numExtractor);

            if(i + j < len)
            {
                if(data[i] == '0')
                {
                    std::string temp{letter};
                    os << temp;
                    dictionary.insert(std::make_pair(counter++, std::move(temp)));
                }
                else 
                {
                    std::string temp = dictionary[index] + std::string{letter};
                    os << temp;
                    dictionary.insert(std::make_pair(counter++, std::move(temp)));
                }
            }
            else 
                os << dictionary[index];

            i = i+j;
        }
        else i++;
    }
    return os.str();
}

int main()
{
    std::string s = "ABCDDEFGABCDEDBBDEAAEDAEDCDABC";
    std::string encoded = encoder(s);
    std::cout << s << "\n" << encoded << "\n" << decoder(encoded) << std::endl;
    return 0;
}






