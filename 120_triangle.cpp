/*******************************************************************************
 *  @File  : 120_triangle.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月27日 星期日 22时24分45秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 */

class Solution {
public:
    void minPathSum(int step, vector<vector<int> >& triangle, 
        int index, vector<vector<int> >& minSum)
    {
        if (step == triangle.size() - 1)
        {
            minSum[step][index] = triangle[step][index];
            return;
        }
        if (minSum[step+1][index] == INT_MAX)
            minPathSum(step+1, triangle, index, minSum);
        if (minSum[step+1][index+1] == INT_MAX)
            minPathSum(step+1, triangle, index+1, minSum);
        minSum[step][index] = min(minSum[step+1][index], minSum[step+1][index+1]) + triangle[step][index];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)
            return 0;
        vector<vector<int> > minSum;
        for (int i = 0; i < triangle.size(); ++i)
        {
            vector<int> rowSum(triangle[i].size(), INT_MAX);
            minSum.push_back(rowSum);
        }
        minPathSum(0, triangle, 0, minSum);
        return minSum[0][0];
    }
};
