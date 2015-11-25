/*******************************************************************************
 *  @File  : 040_combination_sum_II.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年11月25日 星期三 16时14分38秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void _combination(vector<int>& candidates, int target, int step,
            vector<vector<int> >& result, vector<int>& comb)
    {
        if (0 == target)
        {
            result.push_back(comb);
            return;
        }
        if (step >= candidates.size())
            return;
        if (candidates[step] > target)
            return;


        comb.push_back(candidates[step]);
        _combination(candidates, target-candidates[step], step+1, result, comb);
        comb.pop_back();
        
        while (step+1 < candidates.size() && candidates[step] == candidates[step+1])
            step += 1;
        _combination(candidates, target, step+1, result, comb);
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int> > result;
        vector<int> comb;

        if (candidates.size() < 1)
            return result;
        
        // sort and reverse, speedup computing
        sort(candidates.begin(), candidates.end());
        // reverse(candidates.begin(), candidates.end());
        _combination(candidates, target, 0, result, comb);
        return result;
    }
};

int main()
{
    vector<int> candidates(7);
    // int nums[] = {10, 1, 2, 7, 6, 1, 5};
    int nums[] = {1, 1, 1, 2, 2, 3, 3};
    for (int i = 0; i < 7; ++i)
        candidates[i] = nums[i];

    Solution s;
    vector<vector<int> > result = s.combinationSum2(candidates, 5);

    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
