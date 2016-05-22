/*******************************************************************************
 *  @File  : 171_excel_sheet_column_number.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 22 May 2016 11:21:46 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * For example:
 *
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int res = 0;
        for (int i = 0; i < s.length(); ++i)
            res = res * 26 + s[i] - 'A' + 1;
        return res;
    }
};

int main()
{
    Solution s;
    int res = s.titleToNumber("AB");
    cout<<res<<endl;

    return 0;
}

