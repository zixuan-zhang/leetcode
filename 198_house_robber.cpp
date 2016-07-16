/*******************************************************************************
 *  @File  : 198_house_robber.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 16 Jul 2016 04:44:04 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping you
 * from robbing each of them is that adjacent houses have security system connected
 * and it will automatically contact the police if two adjacent houses were
 * broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (0 == nums.size())
            return 0;
        if (1 == nums.size())
            return nums[0];
        if (2 == nums.size())
            return max(nums[0], nums[1]);

        int prev = nums[0];
        int last = max(nums[0], nums[1]);
        int current;

        for (int i = 2; i < nums.size(); ++i)
        {
            current = max(last, prev + nums[i]);
            prev = last;
            last = current;
        }

        return max(last, prev);
    }
};

int main()
{
    return 0;
}
