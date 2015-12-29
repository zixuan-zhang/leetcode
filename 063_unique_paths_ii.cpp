/*******************************************************************************
 *  @File  : 063_unique_paths_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月29日 星期二 20时47分38秒
 ******************************************************************************/

/*
 * Question:
 *
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique
 * paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * Method: 使用动态规划的方法，速度很快
     */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int ** matrix = new int*[m];
        for (int i = 0; i < m; ++i)
            matrix[i] = new int[n];
        
        // initialize
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 0)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
        }
        for (int i = m-1; i >= 0; --i)
        {
            for (int j = n-1; j >= 0; --j)
            {
                if (i == m-1 && j == n-1)
                    continue;
                if (matrix[i][j] != 0)
                {
                    int down, right;
                    if (i == m-1)
                        down = 0;
                    else
                        down = matrix[i+1][j];
                    if (j == n-1)
                        right = 0;
                    else
                        right = matrix[i][j+1];
                    matrix[i][j] = down + right;
                }
            }
        }
        return matrix[0][0];
    }
};

int main()
{
    return 0;
}
