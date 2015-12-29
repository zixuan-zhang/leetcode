/*******************************************************************************
 *  @File  : 064_minimum_path_sum.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月29日 星期二 20时49分46秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * Method: 使用动态规划的方法，而且是在原来的地址上进行操作，时间空间都非常赞
     */
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = m-1; i >= 0; --i)
        {
            for (int j = n-1; j >= 0; --j)
            {
                if (i == m-1 && j == n-1)
                    continue;
                if (i == m-1)
                    grid[i][j] += grid[i][j+1];
                else if (j == n-1)
                    grid[i][j] += grid[i+1][j];
                else
                {
                    grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
                }
            }
        }
        return grid[0][0];
    }
};

int main()
{
    return 0;
}
