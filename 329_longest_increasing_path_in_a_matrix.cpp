/*******************************************************************************
 *  @File  : 329_longest_increasing_path_in_a_matrix.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月17日 星期四 10时04分32秒
 ******************************************************************************/

/*
 * Question:
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 *
 * Example 1:
 *
 * nums = [
 *   [9,9,4],
 *   [6,6,8],
 *   [2,1,1]
 *   ]
 * Return 4
 * The longest increasing path is [1, 2, 6, 9].
 *
 * Example 2:
 *
 * nums = [
 *   [3,4,5],
 *   [3,2,6],
 *   [2,2,1]
 *   ]
 * Return 4
 * The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 *
 */

class Solution {

public:
    int longestIncreasingPathFromHere(vector<vector<int> >& matrix, int x, int y,
            vector<vector<int> >& result)
    {
        if (result[x][y] != -1)
            return result[x][y];
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int pathNumResult = 0;

        for (int i = -1; i <= 1; i+=2)
        {
            if ( (x+i) >= 0 && (x+i) < rowSize && matrix[x][y] < matrix[x+i][y])
            {
                int pathNum = longestIncreasingPathFromHere(matrix, x+i, y, result);
                if (pathNumResult < pathNum)
                    pathNumResult = pathNum;
            }
        }
        for (int i = -1; i <= 1; i+=2)
        {
            if ( (y+i) >= 0 && (y+i) < colSize && matrix[x][y] < matrix[x][y+i])
            {
                int pathNum = longestIncreasingPathFromHere(matrix, x, y+i, result);
                if (pathNumResult < pathNum)
                    pathNumResult = pathNum;
            }
        }
        result[x][y] = pathNumResult + 1;
        return pathNumResult + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        int X = matrix.size();
        int Y = matrix[0].size();
        int pathNumResult = 0;

        vector<int> row(Y, -1);
        vector<vector<int> > result(X, row);

        for (int i = 0; i < X; ++i)
        {
            for (int j = 0; j < Y; ++j)
            {
                if (-1 == result[i][j])
                {
                    int pathNum = longestIncreasingPathFromHere(matrix, i, j, result);
                    if (pathNumResult < pathNum)
                        pathNumResult = pathNum;
                }
            }
        }
        
        return pathNumResult;
    }
};
