/*******************************************************************************
 *  @File  : 132_palindrom_partiioning_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 22 Sep 2016 11:02:49 AM CST
 ******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class  Solution
{
public:
    int minCut(string s)
    {
        int len = s.length();
        vector<vector<int> > matrix(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i)
            matrix[i][i] = 1;
        vector<int> cuts(len+1);
        for (int i = len; i >= 0; --i)
            cuts[i] = len - i - 1;
        for (int i = len-1; i >= 0; --i)
        {
            for (int j = i; j < len; ++j)
            {
                if (i == j)
                    matrix[i][j] = 1;
                else if (i + 1 == j)
                    matrix[i][j] = (s[i] == s[j]) ? 1 : 0;
                else if (s[i] == s[j] && matrix[i+1][j-1])
                    matrix[i][j] = 1;
                if (matrix[i][j])
                    cuts[i] = min(cuts[i], cuts[j+1] + 1);
            }
        }
        return cuts[0];
    }
};

int main()
{
    Solution s;
    string str = "aabb";
    int res = s.minCut(str);
    cout<<res<<endl;
    return 0;
}
