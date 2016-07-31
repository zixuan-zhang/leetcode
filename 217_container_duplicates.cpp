/*******************************************************************************
 *  @File  : 217_container_duplicates.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 31 Jul 2016 06:30:58 PM CST
 ******************************************************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();  
    }
};
