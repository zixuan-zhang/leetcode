/*******************************************************************************
 *  @File  : 216_combination_sum_iii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 31 Jul 2016 06:10:46 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void combination(vector<vector<int> >& result, vector<int>& com,
            int k, int step, int n, int pre)
    {
        if (step == k && n == 0)
        {
            result.push_back(com);
            return;
        }
        if (step == k)
            return;
        for (int i = pre+1; i <= 9; ++i)
        {
            com[step] = i;
            combination(result, com, k, step+1, n-i, i);
        }
    }
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > result;
        if (k <= 0 || n <= 0)
            return result;
        vector<int> com(k);
        combination(result, com, k, 0, n, 0);
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > result = s.combinationSum3(3, 9);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
