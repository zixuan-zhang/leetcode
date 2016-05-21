/*******************************************************************************
 *  @File  : 169_majority_element.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 21 May 2016 10:10:14 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 */

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int element = NULL;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (0 == count)
            {
                element = nums[i];
                count++;
            }
            else if (nums[i] == element)
                count++;
            else
                count--;
        }
        return element;
    }
};
