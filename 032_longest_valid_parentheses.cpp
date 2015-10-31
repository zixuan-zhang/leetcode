/*******************************************************************************
 *  @File  : 032_longest_valid_parentheses.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月31日 星期六 13时58分24秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has
 * length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring
 * is "()()", which has length = 4.
 *
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    /*
     * 大体思想就是:
     *  遇到'('的时候，把'('字符前的可能的括号对数压入栈，并且此字符的max=1
     *  遇到')'的时候，此字符的max[i] = max[i-1] + stk.top() 然后弹栈
     *
     *  当前面没有'('剩余但是遇到')'字符的时候，那么此时相当于从头开始
     *
     */
    int longestValidParentheses1(string s)
    {
        int len = s.length();
        if (len < 2)
            return 0;
        int* left = new int[len+1];
        int* max = new int[len+1];
        left[0] = 0;
        max[0] = 0;
        stack<int> stk;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '(')
            {
                left[i+1] = left[i] + 1;
                stk.push(max[i]);
                max[i+1] = 0;
            }
            else
            {
                if (left[i] > 0)
                {
                    left[i+1] = left[i] - 1;
                    max[i+1] = max[i] + 1 + stk.top();
                    stk.pop();
                }
                else
                {
                    left[i+1] = 0;
                    max[i+1] = 0;
                    while (!stk.empty())
                        stk.pop();
                }

            }
        }

        int result = max[0];
        for (int i = 1; i < len + 1; ++i)
            if (result < max[i])
                result = max[i];
        return result * 2;
    }
};

int main()
{
    Solution s;
    //string str = ")())()(()()))";
    //string str = ")()(()))()";
    //string str = "))(()((";
    //string str = "()(()";
    string str = ")()(()(())(())()";
    int result = s.longestValidParentheses1(str);
    cout<<result<<endl;
    return 0;
}
