/*******************************************************************************
 *  @File  : 055_jump_game.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月19日 星期六 15时57分18秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array of non-negative integers, you are initially positioned at
 * the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:

    /*
     * 使用动态规划的方法，并且中间有个tricky，就是要利用好上一个的状态。
     */
    bool canJump(vector<int>& nums)
    {
        int size = nums.size();
        vector<bool> can_jump(size, true);

        for (int i = size - 2; i >= 0; --i)
        {
            if (0 == nums[i])
                can_jump[i] = false;
            else if (nums[i] - 1 <= nums[i+1])
            {
                can_jump[i] = can_jump[i+1];
            }
            else
            {
                if (can_jump[i+1])
                    can_jump[i] = true;
                else
                {
                    // 这种情况下才有必要取遍历后面的
                    bool result = false;
                    int start = (i + 1 + nums[i+1] + 1);
                    int end = min(size, i+nums[i]);
                    for (int j = start; j <= end; ++j)
                    {
                        result |= can_jump[j];
                        if (result)
                            break;
                    }
                    can_jump[i] = result;
                }
            }
        }
        return can_jump[0];
    }

    bool method2(vector<int>& nums)
    {
        vector<int> left(nums.size());
        left[0] = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            left[i] = max(left[i-1], nums[i-1]) - 1;
            if (left[i] < 0)
                return false;
        }
        return left[nums.size()-1] >= 0;
    }
};

int main()
{
    int jumps[] = {2, 3, 1, 1, 4};
    //int jumps[] = {3, 2, 1, 0, 4};
    int count = 5;
    vector<int> nums(count);
    for (int i = 0; i < count; ++i)
        nums[i] = jumps[i];

    Solution s;
    bool result = s.canJump(nums);
    bool result2 = s.method2(nums);
    cout<<result<<endl;
    cout<<result2<<endl;
    

    return 0;
}
