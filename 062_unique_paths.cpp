/*******************************************************************************
 *  @File  : 062_unique_paths.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月29日 星期二 20时44分41秒
 ******************************************************************************/

/*
 * Question:
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start'
 * in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The
 * robot is trying to reach the bottom-right corner of the grid (marked
 * 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    void walk(int row, int col, int m, int n, int& count)
    {
        if (row == (m-1) && col == (n-1))
        {
            count ++;
            return;
        }
        if (row < m - 1)
            walk(row+1, col, m, n, count);
        if (col < n - 1)
            walk(row, col+1, m, n , count);
    }
    
    /*
     * Method: 这种方法使用递归，但是很容易超时
     */
    int uniquePaths(int m, int n) {
        int count = 0;
        walk(0, 0, m, n, count);
        return count;
    }

    /*
     * 使用动态规划的方法，非常快
     */
    int uniquePaths(int m, int n) {
        int ** matrix = new int*[m];
        for (int i = 0; i < m; ++i)
            matrix[i] = new int[n];
        for (int i = 0; i < m; ++i)
            matrix[i][n-1] = 1;
        for (int i = 0; i < n; ++i)
            matrix[m-1][i] = 1;
        for (int i = m-2; i >= 0; --i)
        {
            for (int j = n-2; j >= 0; --j)
            {
                matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];
            }
        }
        return matrix[0][0];
    }   
};

int main()
{
    return 0;
}
