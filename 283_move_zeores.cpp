/*******************************************************************************
 *  @File  : 183_move_zeroes.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 08 Sep 2016 10:15:15 AM CST
 ******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
                nums[index++] = nums[i];
        }
        for (; index < nums.size(); ++index)
            nums[index] = 0;
    }
};

int main()
{
    int array[] = {0, 1, 0, 3, 12};
    vector<int> nums;
    for (auto num : array)
        nums.push_back(num);

    Solution s;
    s.moveZeroes(nums);
    for (auto num : nums)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}
