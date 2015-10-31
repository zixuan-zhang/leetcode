/*******************************************************************************
 *  @File  : 033_search_in_rotated_sorted_array.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月31日 星期六 16时00分25秒
 ******************************************************************************/

/*
 * Question:
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int rotated_search(vector<int> array, int left, int right, int target)
    {
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (array[mid] == target)
                return mid;
            if (array[mid] >= array[left])
            {
                //左面全部小于mid，右面有大有小
                if (array[mid] < target)
                    left = mid + 1;
                else
                {
                    if (array[left] <= target)
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
            }
            else
            {
                //左面有大有小，右面全部大于mid
                if (array[mid] > target)
                    right = mid - 1;
                else
                {
                    if (array[left] <= target)
                        right  = mid - 1;
                    else
                        left = mid + 1;
                }
            }
        }
        return -1;
    }

    /*
     *
     * 二分查找的一个变形
     *
     */
    int search(vector<int>& nums, int target)
    {
        return rotated_search(nums, 0, nums.size() - 1, target);
    }
};

int main()
{
    Solution s;

    int array[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    vector<int> nums;
    for (int i = 0; i < 0; ++i)
    {
        nums.push_back(array[i]);
    }
    for (int i = 0; i < 0; ++i)
    {
        int index = s.search(nums, array[i]);
        cout<<index<<endl;
    }
    cout<<s.search(nums, 33);
    return 0;
}
