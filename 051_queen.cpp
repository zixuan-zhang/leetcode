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
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 *
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:

    void _queen(int step, int n, vector<string>& com, vector<vector<string> >& result,
            vector<bool>& row, vector<bool>& col, vector<bool>& add,
            vector<bool>& Y, vector<bool>& X)
    {
        if (step == n)
        {
            result.push_back(com);
            return;
        }
        string* str = new string(n, '.');
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
                (*str)[i] = 'Q';
                com.push_back(*str);
                _queen(step+1, n, com, result, row, col, add, Y, X);
                (*str)[i] = '.';
               
                com.pop_back();
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
     *
     */
   
    vector<vector<string> > solveNQueens(int n) {
        vector<bool> row(n, false);
        vector<bool> col(n, false);
        vector<bool> add(2*n+1, false);
        vector<bool> Y(n, false);
        vector<bool> X(n, false);
       
        vector<vector<string> > result;
        vector<string> com;
        _queen(0, n, com, result, row, col, add, Y, X);
       
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<string> > result = s.solveNQueens(4);

    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout<<result[i][j]<<endl;
        }
        cout<<endl;
    }

    return 0;
}
