/*******************************************************************************
 *  @File  : 136_single_number.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 24 Apr 2016 08:43:45 PM CST
 ******************************************************************************/

/*
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 *
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int num = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            num ^= nums[i];
        }
        return num;
    }

};

int main()
{
    int array[] = {1, 2, 1, 3, 3, 2, 7};
    vector<int> nums;
    for (auto num : array)
        nums.push_back(num);
    Solution s;
    int res = s.singleNumber(nums);
    cout<<res<<endl;
    
    return 0;
}
