/*******************************************************************************
 *  @File  : 078_subsets.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年01月05日 星期二 22时01分02秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a set of distinct integers, nums, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        int size = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)pow((double)2, (double)size); ++i)
        {
            vector<int> comb;
            for (int j = 0; j < size; ++j)
            {
                if ( ((i >> j) & 1) == 1)
                    comb.push_back(nums[j]);
            }
            result.push_back(comb);
        }
        return result;
    }
};

int main()
{
    return 0;
}
