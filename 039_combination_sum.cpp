/*******************************************************************************
 *  @File  : 039_combination_sum.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年11月25日 星期三 08时58分04秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    void _combination(vector<int>& candidates, int target,
            vector<int>& comb, int start, vector<vector<int> >& result)
    {
        for (int i = 0; i < candidates.size(); ++i)
        {
            if (candidates[i] == target)
            {
                comb.push_back(candidates[i]);
                reverse(comb.begin(), comb.end());
                result.push_back(comb);
                for (int j = 0; j < comb.size(); ++j)
                    cout<<comb[j]<<" ";
                cout<<endl;
                comb.pop_back();
            }
            else if (candidates[i] < target)
            {
                comb.push_back(candidates[i]);
                _combination(candidates, target - candidates[i], comb,
                        i, result);
                comb.pop_back();
            }
        }
    }

    vector<vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int> > result;
        vector<int> comb;
        if (candidates.size() < 1)
            return result;
        sort(candidates.begin(), candidates.end());
        reverse(candidates.begin(), candidates.end());
        _combination(candidates, target, comb, 0, result);
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> candidates;
    candidates.push_back(3);
    candidates.push_back(7);
    candidates.push_back(2);

    vector<vector<int> > result = s.combinationSum(candidates, 18);
    
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
