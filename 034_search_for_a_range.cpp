/*******************************************************************************
 *  @File  : 034_search_for_a_range.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月31日 星期六 16时55分00秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a sorted array of integers, find the starting and ending position of
 * a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int find_boundary(vector<int>& nums, int target, int index, bool left)
    {
        int gap;
        if (left)
        {
            while (index - 1 >= 0 && nums[index] == target && nums[index-1] == target)
            {
                gap = 1;
                for (int i = 0; index - (gap<<i) >= 0 && nums[index-(gap<<i)] == target; ++i)
                {
                    index -= (gap << i);
                }
            }
        }
        else
        {
            while (index + 1 < nums.size() && nums[index] == target && nums[index+1] == target)
            {
                gap = 1;
                for (int i = 0; index+(gap<<i) < nums.size() && nums[index+(gap<<i)] == target; ++i)
                {
                    index += (gap << i);
                }
            }
        }
        return index;
    }
    vector<int> searchRangeUpdate(vector<int>& nums, int target)
    {
        vector<int> result(2, -1);
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int index;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                // bingo!!!
                // now, we search boundary~
                // generally, one interation is side by side. but we can speed up
                // searching by square each iteration. For example, the mid is 8
                // from mid to left, iteration is 8, 7(1), 5(2), 1(4).
                // from mid to right, iteration is 8, 9(1), 11(2), 15(4) till the end
                // this speed up method could reach O(log(n)) complecity
                index = find_boundary(nums, target, mid, true);
                result[0] = index;
                index = mid;
                index = find_boundary(nums, target, mid, false);
                result[1] = index;
                break;
            }
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> result(2, -1);
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                int index = mid;
                while (index - 1 >= 0 && nums[index] == target && nums[index-1] == target)
                    index--;
                result[0] = index;
                index = mid;
                while (index + 1 < nums.size() && nums[index] == target && nums[index+1] == target)
                    index++;
                result[1] = index;
                break;
            }
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    for (int i = 0; i < 1; ++i)
        nums.push_back(8);
    vector<int> result = s.searchRangeUpdate(nums, 8);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
