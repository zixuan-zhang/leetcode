/*******************************************************************************
 *  @File  : 044_wildcard_matching.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月09日 星期三 08时11分29秒
 ******************************************************************************/

/*
 * Question:
 *
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /*
     * Solution:
     *
     * DP method
     */
    bool isMatch(string s, string p)
    {
        int sLen = s.length() + 1;
        int pLen = p.length() + 1;
        if (sLen == 0 && pLen == 0)
            return true;
        if (sLen != 0 && pLen == 0)
            return false;
        bool **F = new bool*[pLen];
        for (int i = 0; i < pLen; ++i)
            F[i] = new bool[sLen];

        // initialize
        for (int i = 0; i < sLen; ++i)
        {
            if (i == 0)
                F[0][i] = true; // means empty string&pattern is match
            else
                F[0][i] = false;
        }
        for (int j = 1; j < pLen; ++j)
        {
            if (p[j-1] == '*')
                F[j][0] = F[j-1][0];
            else
                F[j][0] = false;
        }

        // main process
        for (int i = 0; i < p.length(); ++i)
        {
            for (int j = 0; j < s.length(); ++j)
            {
                if (p[i] == '?')
                    F[i+1][j+1] = F[i][j];
                else if (p[i] != '*')
                    F[i+1][j+1] = F[i][j] && (p[i] == s[j]);
                else
                {
                    // meet start
                    bool temp = false;
                    for (int m = 0; m <= j+1; ++m)
                        temp |= F[i][m];
                    F[i+1][j+1] = temp;
                }
            }
        }
        
        return F[pLen-1][sLen-1];
    }
};

int main()
{
    //string s = "abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab";
    //string p = "*aabb***aa**a******aa*";
    //string s = "aabbbaaabaaabab";
    //string p = "*aabb*aa*a*aa*";
    //string s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    //string p = "a*******b";
    //string s = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
    //string p = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
    Solution so;
    //s.isMatch("abbc", "a*b**");
    bool result = so.isMatch(s, p);
    cout<<result<<endl;
    return 0;
}
