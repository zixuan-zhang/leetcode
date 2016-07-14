/*******************************************************************************
 *  @File  : 189_rotate_array.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 14 Jul 2016 06:48:35 PM CST
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        vector<int> temp(len);
        for (int i = 0; i < len; ++i)
            temp[i] = nums[(i+len-k)%len];
        for (int i = 0; i < len; ++i)
            nums[i] = temp[i];
    }

    void rotate1(vector<int>& nums, int k)
    {
        int l = nums.size();
        k = k % l;
        reverse(nums.begin(), nums.begin() + l - k);
        reverse(nums.begin()+l-k, nums.begin()+l);
        reverse(nums.begin(), nums.end());
    }
};

int main()
{

}
