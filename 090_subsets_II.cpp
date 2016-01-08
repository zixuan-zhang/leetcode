/*******************************************************************************
 *  @File  : 090_subsets_II.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年01月08日 星期五 17时50分50秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 *
 */

#include <iostream>

using namespace std;

void _subsets(int step, vector<int>& nums, vector<vector<int> >& result,
                  vector<int>& comb)
    {
        if (step == nums.size())
        {
            result.push_back(comb);
            return;
        }
        int index = 1;
        while (step+index < nums.size() && nums[step+index-1] == nums[step+index])
          index++;
        _subsets(step+index, nums, result, comb);
        comb.push_back(nums[step]);
        _subsets(step+1, nums, result, comb);
        comb.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> comb;
        int size = nums.size();

        sort(nums.begin(), nums.end());
        _subsets(0, nums, result, comb);
        return result;
    }
};

int main()
{
    return 0;
}
