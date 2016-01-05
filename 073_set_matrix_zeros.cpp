/*******************************************************************************
 *  @File  : 073_set_matrix_zeros.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年01月04日 星期一 09时30分19秒
 ******************************************************************************/

/*
 * Question:
 * Given a m x n matrix, if an element is 0, set its entire row and column
 * to 0. Do it in place.
 *
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 *
 */

class Solution {
public:
    /*
     * Method: 这里用的是O(m+n)的space
     */
    void setZeroes(vector<vector<int>>& matrix) {
        int rowCount = matrix.size();
        if (0 == rowCount)
            return;
        int colCount = matrix[0].size();
        set<int> row;
        set<int> col;
        for (int i = 0; i < rowCount; ++i)
        {
            for (int j = 0; j < colCount; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (set<int>::iterator it = row.begin(); it != row.end(); ++it)
        {
            for (int i = 0; i < colCount; ++i)
                matrix[*it][i] = 0;
        }
        for (set<int>::iterator it = col.begin(); it != col.end(); ++it)
        {
            for (int i = 0; i < rowCount; ++i)
                matrix[i][*it] = 0;
        }
    }
};
