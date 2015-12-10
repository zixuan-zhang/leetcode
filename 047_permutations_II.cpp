/*******************************************************************************
 *  @File  : 047_permutations_II.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 10 Dec 2015 08:50:22 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:

    void _permute(vector<int>& nums, int step, vector<vector<int> >&result,
            vector<int>&comb, vector<int>& used)
    {
        if (step == nums.size())
            result.push_back(comb);
        int i = 0;
        while (i < nums.size())
        {
            if (used[i] == 0)
            {
                comb.push_back(nums[i]);
                used[i] = 1;
                _permute(nums, step+1, result, comb, used);
                used[i] = 0;
                comb.pop_back();
                i++;
                while (i < nums.size() && nums[i] == nums[i-1])
                    i++;
            }
            else
                i++;
        }
    }

    /*
     * Solution:
     * This method split duplicated cased by jump to next different number.
     * sorted first of course.
     *  
     */
    vector<vector<int> > permute(vector<int>& nums)
    {
        vector<vector<int> >result;
        vector<int> comb;
        vector<int> used(nums.size(), 0);

        sort(nums.begin(), nums.end());

        _permute(nums, 0, result, comb, used);
        return result;
    }
};

int main()
{
    int _nums[] = {2, 1, 1, 2};
    vector<int> nums(4);
    for (int i = 0; i < 4; ++i)
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
