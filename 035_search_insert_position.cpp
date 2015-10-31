/*******************************************************************************
 *  @File  : 035_search_insert_position.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月31日 星期六 18时08分18秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        if (0 == nums.size())
            return 0;
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (target > nums[left])
            return left + 1;
        else
            return left;
    }
};


int main()
{
    vector<int> nums;
    int ori[] = {1, 3, 5, 6};
    for (int i = 0; i < 4; ++i)
        nums.push_back(ori[i]);

    Solution s;
    cout<<s.searchInsert(nums, 0)<<endl;
    return 0;
}
