/*******************************************************************************
 *  @File  : 010_regular_expression_matching.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月11日 星期日 16时11分50秒
 ******************************************************************************/

/*
 * Question:
 *
 * Implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 *
 */

/*
 * Solution:
 *
 * 我这里用的递归的方法，有点慢
 *
 */

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int index_s = 0;
        int index_p = 0;
        int len_s = s.length();
        int len_p = p.length();
        if (0 == len_s && 0 == len_p)
            return true;
        while (index_p < len_p)
        {
            if ('.' == p[index_p])
            {
                if (index_p + 1 == len_p || index_p + 1 < len_p && p[index_p+1] != '*') //说明只用匹配一个字符
                {
                    if (index_s + 1 > len_s)
                        return false;
                    index_s ++;
                    index_p ++;
                }
                else if (index_p + 1 < len_p && p[index_p+1] == '*') //可以匹配任何字符
                {
                    index_p ++; // 现在到了*这个字符
                    if (index_p + 1 == len_p)
                        return true; //这样可以直接返回正确
                    do
                    {
                        //然后需要递归的匹配剩下的字符
                        bool subRes = false;
                        subRes = isMatch(s.substr(index_s, len_s-index_s), p.substr(index_p+1, len_p - index_p));
                        if (subRes)
                            return true;
                        index_s ++;
                    }while(index_s <= len_s);
                    return false; // 没有匹配
                }
            }
            else
            {
                char temp = p[index_p];
                if (index_p + 1 == len_p || index_p + 1 < len_p && p[index_p+1] != '*') //说明只用匹配一个字符
                {
                    if (index_s + 1 > len_s)
                        return false;
                    if (s[index_s++] != p[index_p++])
                        return false;
                }
                else if (index_p + 1 < len_p)
                {
                    //匹配0个或多个字符
                    index_p ++; // 现在指向的是 * 这个字符
                    do
                    {
                        //递归匹配剩下的字符
                        bool subRes = false;
                        subRes = isMatch(s.substr(index_s, len_s - index_s), p.substr(index_p+1, len_p - index_p));
                        if (subRes)
                            return true;
                        index_s ++;
                    }while(s[index_s-1] == temp && index_s <= len_s);
                    return false;
                }
            }
        }

        if (index_p != len_p || index_s != len_s)
            return false;
        else
            return true;
    }
};

int main()
{
    string str[] = {"abcaaaaaabaabcabac", "","ab", "aa", "ab", "a", "aab", "ab", "aaa", "aa", "aa", "", "aa", "a", "aa", "aab", "ab", "aab", "aab", "aab", "aa", ""};
    string pat[] = {".*ab.a.*a*a*.*b*b*", "c*c*", ".*c", "..", ".*..", "ab*", "c*a*b", ".*", "aa", "aa", "a", "", "a*", "aa", "a", "a.b", "a.b.", "*aab", "a*b", "a*bb", ".", ".b*"};
    int res[] = {1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0};
    Solution s;
    for (int i = 0; i < 21; ++i)
    {
        bool res = s.isMatch(str[i], pat[i]);
        cout<<res<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 21; ++i)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
