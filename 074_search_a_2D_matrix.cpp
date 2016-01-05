/*******************************************************************************
 *  @File  : 073_search_a_2D_matrix.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 05 Jan 2016 09:05:27 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 *
 * For example,
 *
 * Consider the following matrix:
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /*
     * Method: 时间复杂度O(m+n)
     * 这种方法还有优化的空间。
     * 1. 比如向左search的时候可以用binary search,时间复杂度减小为O(m+log(n))
     * 2. 在1的基础上，先从右上开始向下search，找到一行i，使得该值小于i行的最右
     *    且大于i-1行的最右值。然后在对i行进行binary search。这个时间时间复杂度
     *    为O(log(m)+log(n))
     *
     */
    bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        int res = false;
        int rowSize = matrix.size();
        if (0 == rowSize)
            return false;
        int colSize = matrix[0].size();

        int up = 0;
        int right = colSize - 1;

        while (up < rowSize && right >= 0)
        {
            if (target == matrix[up][right])
                return true;
            else if (target > matrix[up][right])
            {
                up ++;
            }
            else
                right --;
        }
        return res;
    }
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;

    int r1[] = {1, 3, 5, 7};
    int r2[] = {10, 11, 16, 20};
    int r3[] = {23, 30, 34, 50};

    for (int i = 0; i < 4; ++i)
    {
        row1.push_back(r1[i]);
        row2.push_back(r2[i]);
        row3.push_back(r3[i]);
    }
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    Solution s;
    for (int i = 0; i < 60; ++i)
    {
        cout<<i<<" : "<<s.searchMatrix(matrix, i)<<endl;
    }
    return 0;
}
