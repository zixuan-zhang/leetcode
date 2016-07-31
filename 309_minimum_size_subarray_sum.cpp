/*******************************************************************************
 *  @File  : 309_minimum_size_subarray_sum.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 31 Jul 2016 05:26:48 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 *
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int _min = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = nums[0];
        while (end < nums.size() && start <= end)
        {
            if (sum >= s)
            {
                _min = min(_min, end - start + 1);
                sum -= nums[start++];
            }
            else
            {
                if (end == nums.size()-1)
                    break;
                sum += nums[++end];
            }
        }
        return _min == INT_MAX ? 0 : _min;
    }
};

int main()
{
    return 0;
}
