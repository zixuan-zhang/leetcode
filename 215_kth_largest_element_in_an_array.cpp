/*******************************************************************************
 *  @File  : 215_kth_largest_element_in_an_array.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 30 Jul 2016 10:26:01 PM CST
 ******************************************************************************/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};
