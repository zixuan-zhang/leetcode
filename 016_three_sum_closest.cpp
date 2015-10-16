/*******************************************************************************
 *  @File  : 016_three_sum_closest.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月15日 星期四 19时02分25秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 *  For example, given array S = {-1 2 1 -4}, and target = 1.
 *  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
public:


    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int min = INT_MAX;
        int result;
        int temp;
        for (int i = 0; i < nums.size(); ++i)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                temp = nums[i] + nums[left] + nums[right];
                if (min > abs(target - temp))
                {
                    result = temp;
                    min = abs(target - result);
                }
                if (temp == target)
                    return target;
                if (temp > target)
                {
                    while (--right > left && nums[right] == nums[right+1]);
                }
                else
                    while (++left < right && nums[left] == nums[left - 1]);
            }
        }
        return result;

    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(16);
    nums.push_back(32);
    nums.push_back(64);
    nums.push_back(128);
    int res = s.threeSumClosest(nums, 82);
    cout<<res<<endl;
}
