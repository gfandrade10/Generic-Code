#include <iostream>
#include <string>
#include <vector>

int solution(std::string roman) 
{
    std::vector<int> values;
    int result = 0;
    for (char& c:roman)
    {
        switch (c)
        {
            case 'I': { values.push_back(1);    break; }
            case 'V': { values.push_back(5);    break; }
            case 'X': { values.push_back(10);   break; }
            case 'L': { values.push_back(50);   break; }
            case 'C': { values.push_back(100);  break; }
            case 'D': { values.push_back(500);  break; }
            case 'M': { values.push_back(1000); break; }
        }
    }
    for(size_t i = 0; i < values.size(); i++)
    {
        if(i < values.size()-1 && values[i] >= values[i+1]) 
            result += values[i];
            
        else if (i < values.size()-1 && values[i] < values[i+1])
        {
            result += values[i+1] - values[i];
            i++;
        }
        else result += values[i];
    }
    return result;
}

int main(int argc, char** argv)
{
    std::string roman = "MMMDCCXLVIII";
    std::cout << "Roman Number: " << roman << std::endl;
    std::cout << "Decimal Number: " << solution(roman);
    std::cout << "\n\n";

    return 0;
}