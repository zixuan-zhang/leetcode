/*******************************************************************************
 *  @File  : 162_find_peak_element.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 22 May 2016 03:33:08 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 *
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int index = 0;
        int start = 0;
        int end = nums.size() - 1;
        while (start < end)
        {
            if (start == 0 && nums[start] > nums[start+1])
            {
                index = start;
                break;
            }
            if (end == nums.size() - 1 && nums[end] > nums[end-1])
            {
                index = end;
                break;
            }
            if (start != 0 && nums[start] > nums[start-1] && nums[start] > nums[start+1])
            {
                index = start;
                break;
            }
            if (end != nums.size() - 1 && nums[end] > nums[end-1] && nums[end] > nums[end+1])
            {
                index = end;
                break;
            }

            int mid = (start + end) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            {
                index = mid;
                break;
            }
            else if (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return index;
    }
};

int main()
{
    int array[] = {1, 2, 1, 3, 1, 4, 1};
    vector<int> nums;
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
        nums.push_back(array[i]);
    Solution s;
    int index = s.findPeakElement(nums);
    cout<<index<<endl;
    return 0;
}

