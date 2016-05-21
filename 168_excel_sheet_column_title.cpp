/*******************************************************************************
 *  @File  : 168_excel_sheet_column_title.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 21 May 2016 10:27:15 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution
{
public:
    string convertToTitle(int n)
    {
        string res = "";
        while (n > 0)
        {
            res += ('A' + (n-1) % 26);
            n = (n-1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution s;
    string res;
    for (int i = 1; i <= 100; ++i)
    {
        res = s.convertToTitle(i);
        cout<<i<<" : "<<res<<endl;
    }
    return 0;
}
