/*******************************************************************************
 *  @File  : 046_permutations.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 10 Dec 2015 08:24:20 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:

    void _permute(vector<int>& nums, int step, vector<vector<int> >&result,
            vector<int>&comb, vector<int>& used)
    {
        if (step == nums.size())
            result.push_back(comb);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i] == 0)
            {
                comb.push_back(nums[i]);
                used[i] = 1;
                _permute(nums, step+1, result, comb, used);
                used[i] = 0;
                comb.pop_back();
            }
        }
    }

    /*
     * Solution:
     *
     * This method will definitely cause duplicated results, but still
     * accepted.
     *
     */
    vector<vector<int> > permute(vector<int>& nums)
    {
        vector<vector<int> >result;
        vector<int> comb;
        vector<int> used(nums.size(), 0);
        _permute(nums, 0, result, comb, used);
        return result;
    }
};

int main()
{
    int _nums[] = {1, 2, 3};
    vector<int> nums(3);
    for (int i = 0; i < 3; ++i)
        nums[i] = _nums[i];
    Solution s;

    vector<vector<int> >result = s.permute(nums);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
