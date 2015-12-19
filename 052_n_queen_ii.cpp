/*******************************************************************************
 *  @File  : 051_queen.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 18 Dec 2015 06:00:14 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of
 * distinct solutions.
 *
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    void _queen(int step, int n, int& totalCount,
            vector<bool>& row, vector<bool>& col, vector<bool>& add,
            vector<bool>& Y, vector<bool>& X)
    {
        if (step == n)
        {
            totalCount ++;
        }
        for (int i = 0; i < n; ++i)
        {
            bool flag = !row[step] && !col[i] && !add[step+i];
            if (i >= step)
                flag &= !Y[i-step];
            else
                flag &= !X[step-i];
            if (flag)
            {
                row[step] = true;
                col[i] = true;
                add[step+i] = true;
                if (i >= step)
                    Y[i-step] = true;
                else
                    X[step-i] = true;
                _queen(step+1, n, totalCount, row, col, add, Y, X);
               
                row[step] = false;
                col[i] = false;
                add[step+i] = false;
                if (i >= step)
                    Y[i-step] = false;
                else
                    X[step-i] = false;
            }
        }
    }

    /*
     * method:
     *
     * 用递归回溯法来搞这个。最重要的是八皇后的满足条件。
     * 和上一题基本是一样的思路，只需要计数就可以了。
     *
     */
   
    int totalNQueens(int n) {
        vector<bool> row(n, false);
        vector<bool> col(n, false);
        vector<bool> add(2*n+1, false);
        vector<bool> Y(n, false);
        vector<bool> X(n, false);
       
        int totalCount = 0;
        _queen(0, n, totalCount, row, col, add, Y, X);
        return totalCount;
       
    }
};

int main()
{
    Solution s;
    int totalCount = s.totalNQueens(8);

    cout<<totalCount<<endl;

    return 0;
}
