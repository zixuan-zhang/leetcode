/*******************************************************************************
 *  @File  : 020_valid_parentheses.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月16日 星期五 18时30分48秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']'
 * , determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid
 * but "(]" and "([)]" are not.
 *
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> q;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
                q.push(s[i]);
            else
            {
                if (0 == q.size())
                    return false;
                char c = q.top();
                if ((s[i] == ']' && c == '[') || 
                        (s[i] == ')' && c == '(') ||
                        (s[i] == '}' && c == '{'))
                {
                    q.pop();
                }
                else
                    return false;
            }
        }
        if (0 != q.size())
            return false;
        else
            return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isValid("]")<<endl;
    return 0;
}
