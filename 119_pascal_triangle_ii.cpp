/*******************************************************************************
 *  @File  : 119_pascal_triangle_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月27日 星期日 22时26分03秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        vector<vector<int> > comb;
        for (int i = 0; i <= rowIndex; ++i)
        {
            vector<int> row(rowIndex+1);
            comb.push_back(row);
        }
        for (int  i = 0; i <= rowIndex; ++i)
        {
            comb[0][i] = 0;
            comb[i][0] = 1;
        }
        for (int i = 1; i <= rowIndex; ++i)
        {
            for (int j = 1; j <= rowIndex; ++j)
                comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        }
        
        if (rowIndex == 0)
            res[0] = 1;
        else
        {
            res[0] = 1;
            res[rowIndex] = 1;
            for (int i = 1; i <= (rowIndex/2); ++i)
            {
                
                int num = comb[rowIndex][i];
                res[i] = num;
                res[rowIndex-i] = num;
            }
        }
        return res;
    }
};
