/*******************************************************************************
 *  @File  : 059_spiral_matrix_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月29日 星期二 20时39分59秒
 ******************************************************************************/

/*
 * Question:
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *   [ 7, 6, 5 ]
 * ]
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> >matrix(n);
        for (int i = 0; i < n; ++i)
        {
            vector<int> row(n, 0);
            matrix[i] = row;
        }

        int left = 0;
        int right = n-1;
        int up = 0;
        int bottom = n-1;

        int layer = (n+1) / 2;
        int number = 1;
        for (int i = 0; i <= layer; ++i)
        {
            for (int col = left; col <= right; ++col)
                matrix[up][col] = number++;
            up ++;
            for (int row=up; row <= bottom; ++row)
                 matrix[row][right] = number++;
            right --;
            for (int col = right; col >= left; --col)
                matrix[bottom][col] = number++;
            bottom --;
            for (int row=bottom; row >= up; --row)
                matrix[row][left] = number++;
            left ++;
        }
        return matrix;
    }
};

int main()
{
    return 0;
}
