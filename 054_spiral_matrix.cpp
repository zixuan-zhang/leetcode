/*******************************************************************************
 *  @File  : 04_spiral_matrix.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 19 Dec 2015 02:28:28 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements
 * of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> result;
        int n_row = matrix.size();
        if (n_row == 0)
            return result;
        int n_col = matrix[0].size();
        int n_layer = (min(n_row, n_col)+ 1) / 2;

        int rowCnt = 0;
        int colCnt = 0;
        for (int index = 0; index < n_layer; ++index)
        {
            // upper row
            for (int i = index; i < n_col - index; ++i)
            {
                result.push_back(matrix[index][i]);
            }
            rowCnt ++;
            // right colomn
            for (int i = index + 1; i < n_row - index; ++i)
            {
                result.push_back(matrix[i][n_col-1-index]);
            }
            colCnt ++;

            // bottom row
            if (rowCnt < n_row)
            {
                for (int i = n_col - 2 - index; i >= index; --i)
                {
                    result.push_back(matrix[n_row-1-index][i]);
                }
                rowCnt ++;
            }
            // left column
            if (colCnt < n_col)
            {
                for (int i = n_row - 2 - index; i >= 1+index; --i)
                {
                    result.push_back(matrix[i][index]);
                }
                colCnt ++;
            }
        }
        return result;

    }
};

int main()
{
    vector<vector<int> > matrix;
    for (int i = 0; i < 5; ++i)
    {
        vector<int> row;
        for (int j = 1; j <= 3; ++j)
        {
            row.push_back(i * 3 + j);
        }
        matrix.push_back(row);
    }

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    //return 0;
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i]<<" ";
    cout<<endl;

    return 0;
}
