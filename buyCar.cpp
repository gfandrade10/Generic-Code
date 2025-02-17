#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

namespace BuyCar
{
    std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, float percentLossByMonth)
    {
        constexpr float percIncrease = 0.5f;
        int timeCount = 0;
        float netAmount = -1.0f;
        float factor = 1.0f;

        while(true)
        {
            if(netAmount >= 0)
                break;

            float currentPriceOld = 1.0f * startPriceOld * factor;
            float currentPriceNew = 1.0f * startPriceNew * factor;

            netAmount = currentPriceOld - currentPriceNew + (timeCount * savingperMonth);
            
            std::cout << std::fixed << std::setprecision(3);
            std::cout << "Month " << timeCount << ": " << netAmount  << " // " << factor << "\n";
            
            timeCount++;
            if(timeCount != 0 && timeCount % 2 == 0)                
                percentLossByMonth += percIncrease;

            factor *= (1 - percentLossByMonth/100.0f);
        }

        int integerNet = std::round(netAmount);
        return {timeCount - 1, integerNet};
    }
}

int main()
{
    auto arr = BuyCar::nbMonths(2000, 8000, 1000, 1.5);
    std::cout << "Result: {" << arr[0] << ", " << arr[1] << "}\n";
}
