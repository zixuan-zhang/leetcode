/*******************************************************************************
 *  @File  : 053_maximum_subarray.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 19 Dec 2015 10:16:12 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /*
     * 使用动态规划的方法来解决这个问题。这个是比较典型的动态规划问题
     *
     */
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> _max(nums.size(), 0);
        _max[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            _max[i] = max(nums[i], _max[i-1]+nums[i]);
        }
        
        int res = _max[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (res < _max[i])
                res = _max[i];
        }
        return res;
    }
};


int main()
{

    return 0;
}
