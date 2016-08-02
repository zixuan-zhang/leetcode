/*******************************************************************************
 *  @File  : 221_maximal_spuare.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 02 Aug 2016 09:04:51 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int rows = matrix.size();
        if (0 == rows)
            return 0;
        int column = matrix[0].size();
        vector<vector<int> > square;
        for (int i = 0; i < rows; ++i)
            square.push_back(vector<int>(column, 0));

        int result = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                if (matrix[i][j] == '0')
                    square[i][j] = 0;
                else
                {
                    square[i][j] = 1;
                    if ( i-1 >= 0 && matrix[i-1][j] == '1' && j-1 >= 0 && matrix[i][j-1] == '1')
                    {
                        int _min = square[i-1][j-1];
                        _min = min(_min, square[i-1][j]);
                        _min = min(_min, square[i][j-1]);
                        square[i][j] = _min + 1;

                    }
                    result = max(result, square[i][j]);
                }
            }
        }
        return result * result;
    }
};

int main()
{
    return 0;
}
