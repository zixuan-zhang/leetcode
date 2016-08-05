/*******************************************************************************
 *  @File  : majority_element_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 05 Aug 2016 10:55:05 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋
 * times. The algorithm should run in linear time and in O(1) space.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, num2 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == num1)
                count1++;
            if (nums[i] == num2)
                count2++;
        }
        vector<int> result;
        if (count1 > nums.size() / 3)
            result.push_back(num1);
        if (count2 > nums.size() / 3)
            result.push_back(num2);
        if (result.size() == 2 && result[0] == result[1])
            result.pop_back();
        return result;
    }
};

int main()
{
    return 0;
}
