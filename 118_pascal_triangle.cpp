/*******************************************************************************
 *  @File  : 118_pascal_triangle.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月23日 星期三 22时35分25秒
 ******************************************************************************/


/*
 * Question:
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 *
 */



class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > result;
        vector<int> row1(1,1);
        vector<int> row2(2,1);
        if (0 == numRows)
            return result;
        if (1 == numRows)
        {
            result.push_back(row1);
            return result;
        }
        result.push_back(row1);
        result.push_back(row2);
        if (2 == numRows)
            return result;
        for (int i = 2; i < numRows; ++i)
        {
            vector<int> row(i+1);
            for (int j = 1; j < i; ++j)
                row[j] = result[i-1][j-1] + result[i-1][j];
            row[0] = 1;
            row[i] = 1;
            result.push_back(row);
        }
    }
};
