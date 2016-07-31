/*******************************************************************************
 *  @File  : 213_house_robber_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 30 Jul 2016 10:29:29 PM CST
 ******************************************************************************/


/*
 * Question:
 *
 * After robbing those houses on that street, the thief has found himself a new
 * place for his thievery so that he will not get too much attention. This time,
 * all houses at this place are arranged in a circle. That means the first house
 * is the neighbor of the last one. Meanwhile, the security system for these
 * houses remain the same as for those in the previous street.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int _rob(vector<int>& nums)
    {
        int prev = nums[0];
        int last = max(nums[0], nums[1]);
        int current;

        for (int i = 2; i < nums.size()-1; ++i)
        {
            current = max(last, prev + nums[i]);
            prev = last;
            last = current;
        }

        return max(last, prev);
    }

    int rob(vector<int>& nums)
    {
        if (0 == nums.size())
            return 0;
        if (1 == nums.size())
            return nums[0];
        if (2 == nums.size())
            return max(nums[0], nums[1]);

        int num1 = _rob(nums);
        reverse(nums.begin(), nums.end());
        int num2 = _rob(nums);
        return max(num1, num2);
    }
};

int main()
{
    return 0;
}
