/*******************************************************************************
 *  @File  : 048_rotate_image.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Mon 14 Mar 2016 08:48:35 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int> >& matrix)
    {
        if (matrix.size() == 0)
            return;
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = down;

        while (up < down)
        {
            for (int i = 0; i < right-left; ++i)
            {
                int temp = matrix[up][left+i];
                matrix[up][left+i] = matrix[down-i][left];
                matrix[down-i][left] = matrix[down][right-i];
                matrix[down][right-i] = matrix[up+i][right];
                matrix[up+i][right] = temp;
            }
            up++;
            down--;
            left++;
            right--;
        }
    }
};

int main()
{
    int n = 4;
    vector<vector<int> > matrix;
    for (int i = 0; i < n; ++i)
    {
        vector<int> row;
        for (int j = 0; j < n; ++j)
        {
            int num = i*n + j;
            row.push_back(num);
        }
        matrix.push_back(row);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    Solution s;
    s.rotate(matrix);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
