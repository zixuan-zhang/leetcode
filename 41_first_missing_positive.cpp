/*******************************************************************************
 *  @File  : 41_first_missing_positive.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 26 May 2016 09:26:03 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * iven an unsorted integer array, find the first missing positive integer.
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * Your algorithm should run in O(n) time and uses constant space.
 *
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] >= 1 && nums[i] <= len)
            {
                if (nums[i] == i+1)
                    break;
                if (nums[nums[i]-1] == nums[i])
                    break;
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i+1 != nums[i])
                return i+1;
        }
        return len + 1;
    }
};

int main()
{
    int array[] = {1, 1};
    vector<int> nums;
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
        nums.push_back(array[i]);

    Solution s;
    int res = s.firstMissingPositive(nums);
    cout<<res<<endl;

    return 0;
}
