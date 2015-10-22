/*******************************************************************************
 *  @File  : 026_remove_duplicates_from_sorted_array.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月22日 星期四 10时01分33秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with
 * constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (0 == nums.size())
            return 0;
        int len = 0;
        int index = 1;
        while (index < nums.size())
        {
            if (nums[len] == nums[index])
                index ++;
            else
                nums[++len] = nums[index++];
        }
        return len + 1;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(6);

    Solution s;
    int len = s.removeDuplicates(nums);
    cout<<len<<endl;
    for (int i = 0; i < len; ++i)
        cout<<nums[i]<<" ";
    cout<<endl;

    return 0;
}
