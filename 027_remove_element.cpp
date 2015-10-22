/*******************************************************************************
 *  @File  : 027_remove_element.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月22日 星期四 10时51分02秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array and a value, remove all instances of that value in place and
 * return the new length. The order of elements can be changed. It doesn't matter
 * what you leave beyond the new length.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        if (0 == nums.size())
            return 0;
        int len = 0;
        int index = 0;
        do
        {
            if (nums[index] != val)
                nums[len++] = nums[index];
        }while (++index < nums.size());
        return len;
    }
};

int main()
{
    vector<int> nums;
    /*
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    */
    
    Solution s;
    int len = s.removeElement(nums, 1);
    for (int i = 0; i < len; ++i)
        cout<<nums[i]<<" ";
    cout<<endl;

    return 0;
}


