/*******************************************************************************
 *  @File  : 077_combinations.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年01月05日 星期二 21时59分22秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    void _combinations(int step, int n, int k, int pre, vector<int>& comb,
                       vector<vector<int> >& result, vector<bool>& used)
    {
        if (step == k)
        {
            result.push_back(comb);
            return;
        }
        for (int i = pre+1; i <= n; ++i)
        {
            if (!used[i])
            {
                comb.push_back(i);
                used[i] = true;
                _combinations(step+1, n, k, i, comb, result, used);
                used[i] = false;
                comb.pop_back();
            }
        }
    }   
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> comb;
        vector<bool> used(n+1, false);

        _combinations(0, n, k, 0, comb, result, used);
        return result;
    }
};

int main()
{
    return 0;
}
