#include <iostream>
#include <vector>
#include <string>
#include <functional>

int setDate(std::vector<size_t>& date, int buffer)
{
    if(buffer >= 31536000)
    {
        date[3] += buffer / 31536000; 
        buffer = buffer % 31536000;
    }
    else if(buffer >= 86400 && buffer < 31536000)
    {
        date[2] += buffer / 86400; 
        buffer = buffer % 86400;
    }
    else if(buffer >= 3600 && buffer < 86400)
    {
        date[1] += buffer / 3600;
        buffer = buffer % 3600;
    }
    else if (buffer >= 60 && buffer < 3600)
    {
        date[0] += buffer / 60;
        buffer = buffer % 60;
    }
    else return buffer;
    return buffer;
}

std::string format_duration(int seconds) 
{
    if (seconds == 0) return "now";
    std::vector<size_t> date = {0,0,0,0};
    int buffer = seconds, counter = 0;
    std::string result = "";

    while(buffer > 60)
        buffer = setDate(date,buffer);

    for (const auto& a:date)
        { if (a > 0) counter++; }
    
    auto Update = [&](int s)->void
    { if(buffer == 0 && counter == 2 && date[s] > 0) { result += " and "; counter--; }
    else if (counter >= 2 && date[s] > 0) { result += ", "; counter--; }};
    
    if (date[3] == 1) result += "1 year";
    else if(date[3] > 1) result += std::to_string(date[3]) + " year";
    Update(3);

    if (date[2] == 1) result += "1 day";
    else if(date[2] > 1) result += std::to_string(date[2]) + " days";
    Update(2);

    if (date[1] == 1) result += "1 hour";
    else if(date[1] > 1) result += std::to_string(date[1]) + " hours";
    Update(1);

    if (date[0] == 1) result += "1 minute";
    else if(date[0] > 1) result += std::to_string(date[0]) + " minutes";
    if (counter == 1 && buffer > 0) result += " and ";
    
    if (buffer == 1) result += "1 second";
    else if (buffer > 1) result += std::to_string(buffer) + " seconds";

    return result;
}

int main(int argc, char** argv)
{
    std::cout << format_duration(120) << std::endl;
    return EXIT_SUCCESS;
}