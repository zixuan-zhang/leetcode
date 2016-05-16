/*******************************************************************************
 *  @File  : 153_find_minimum_in_rotate_sorted_array.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Mon 16 May 2016 08:27:19 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int start = 0;
        int mid = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            if (start == end)
                return nums[start];
            if (nums[start] < nums[end])
                return nums[start];
            mid = (start + end) / 2;
            if (mid == 0)
                start = mid + 1; 
            else if (nums[mid] < nums[mid-1])
                return nums[mid];
            else if (nums[mid] > nums[start])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
};

int main()
{
    return 0;
}
