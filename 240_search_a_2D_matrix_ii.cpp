/*******************************************************************************
 *  @File  : 240_search_a_2D_matrix_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 07 Aug 2016 04:08:12 PM CST
 ******************************************************************************/


/*
 * Question:
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 * Given target = 20, return false.
 *
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (0 == rows)
            return false;
        int columns = matrix[0].size();
        
        int rowStart = 0, columnStart = 0, rowEnd = rows-1, columnEnd = columns-1;
        while (rowStart <= rowEnd && columnStart <= columnEnd)
        {
            if (matrix[rowStart][columnEnd] == target)
                return true;
            else if (matrix[rowStart][columnEnd] < target)
                rowStart++;
            else
                columnEnd--;
        }
        return false;
    }
};

int main()
{
    return 0;
}
