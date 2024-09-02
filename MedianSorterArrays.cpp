#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <vector>

class Solution
{
    public:
    static double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        if(nums1.size() == 1 && nums2.size() == 1)
        {
            return static_cast<double>(nums1[0] + nums2[0])/2.0;
        }

        std::vector<int> res (nums1.size() + nums2.size());
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        size_t i = 0;
        size_t len = res.size();
        
        while(it1 != nums1.end() || it2 != nums2.end())
        {
            if(it1 == nums1.end())
            {
                res[i] = *it2;
                it2++;
            }
            else if(it2 == nums2.end())
            {
                res[i] = *it1;
                it1++;
            }
            else if(*it1 < *it2)
            {
                res[i] = *it1;
                it1++;
            }
            else 
            {
                res[i] = *it2;
                it2++;
            }

            if(i == len/2)
            {
                if(res.size() % 2 == 0)
                {
                    return static_cast<double>(res[i] + res[i - 1])/2.0;
                }
                else 
                {
                    return static_cast<double>(res[i]);
                }
            }

            i++;
        }
        return 0;
    }
};

int main()
{
    std::vector<int> nums1 = {1,2};
    std::vector<int> nums2 = {3,4};
    double ans = Solution::findMedianSortedArrays(nums1, nums2);
    std::ostringstream os;
    os << std::fixed;
    os << std::setprecision(4);
    os << "Ans: " << ans << "\n\n";
    std::cout << os.str();
}
