#include <fmt/base.h>
#include <fmt/core.h>
#include <cctype>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

namespace SalesmanTravel
{
    static std::string travel(const std::string& data, const std::string& zipcode)
    {
        if(data.empty() || zipcode.empty()) { return ":/"; }
        if(zipcode.length() != 8) { return zipcode + ":/"; }

        using s_ptr = std::string::const_iterator;
        s_ptr line_starter = data.cbegin();
        s_ptr zip_code_start;
        s_ptr num_extractor;
        size_t zl = zipcode.length();
        size_t dl = data.length();
        std::string ans{};
        std::vector<std::string> numbers{};

        for(size_t i = 0; i < dl; ++i)
        {
            if(data[i] == ',' && i + 1 < dl) { line_starter = s_ptr(&data[i+1]); }

            if(i > 0 && data[i-1] == ' ')
            {
                if(data[i] == zipcode[0] && i + zl < dl)
                {
                    zip_code_start = s_ptr(&data[i]);
                    if(std::memcmp(zip_code_start.base(), zipcode.data(), zl) == 0)
                    {
                        num_extractor = line_starter;
                        while(::isdigit(*num_extractor)) { num_extractor++; }
                        numbers.emplace_back(line_starter, num_extractor);
                        line_starter = num_extractor + 1;

                        ans += std::string(line_starter, zip_code_start - 1) + ",";
                        if(i + zl + 1 == dl) { break; }
                        i += zl + 1;
                        line_starter = s_ptr(&data[i]);
                    }

                }
            }
        }

        if(!ans.empty()) { ans.pop_back(); }
        else { return zipcode + ":/"; }

        ans += "/";
        size_t num_len = numbers.size();
        for(size_t i = 0; i < num_len; ++i)
        {
            if(i < num_len - 1) { ans += numbers[i] + ","; }
            else { ans += numbers[i]; }
        }

        return zipcode + ":" + ans;
    }
};

int main()
{
    const std::string ad = 
        "123 Main Street St. Louisville OH 43071,432 Main Long Road St. Louisville OH 43071,786 High Street Pollocksville NY 56432,"
        "54 Holy Grail Street Niagara Town ZP 32908,3200 Main Rd. Bern AE 56210,1 Gordon St. Atlanta RE 13000,"
        "10 Pussy Cat Rd. Chicago EX 34342,10 Gordon St. Atlanta RE 13000,58 Gordon Road Atlanta RE 13000,"
        "22 Tokyo Av. Tedmondville SW 43098,674 Paris bd. Abbeville AA 45521,10 Surta Alley Goodtown GG 30654,"
        "45 Holy Grail Al. Niagara Town ZP 32908,320 Main Al. Bern AE 56210,14 Gordon Park Atlanta RE 13000,"
        "100 Pussy Cat Rd. Chicago EX 34342,2 Gordon St. Atlanta RE 13000,5 Gordon Road Atlanta RE 13000,"
        "2200 Tokyo Av. Tedmondville SW 43098,67 Paris St. Abbeville AA 45521,11 Surta Avenue Goodtown GG 30654,"
        "45 Holy Grail Al. Niagara Town ZP 32918,320 Main Al. Bern AE 56215,14 Gordon Park Atlanta RE 13200,"
        "100 Pussy Cat Rd. Chicago EX 34345,2 Gordon St. Atlanta RE 13222,5 Gordon Road Atlanta RE 13001,"
        "2200 Tokyo Av. Tedmondville SW 43198,67 Paris St. Abbeville AA 45522,11 Surta Avenue Goodville GG 30655,"
        "2222 Tokyo Av. Tedmondville SW 43198,670 Paris St. Abbeville AA 45522,114 Surta Avenue Goodville GG 30655,"
        "2 Holy Grail Street Niagara Town ZP 32908,3 Main Rd. Bern AE 56210,77 Gordon St. Atlanta RE 13000";

    fmt::println("{}\n", SalesmanTravel::travel(ad, "AA 45522"));
    return 0;
}
