/*******************************************************************************
 *  @File  : 022_generate_parentheses.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月25日 星期日 16时43分02秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    void _generate(int left, int right, string& str, vector<string>& result)
    {
        if (left < 0 || right < left)
            return;
        if (left == 0 && right == 0)
        {
            result.push_back(str);
        }
        else
        {
            if (left > 0)
            {
                str += "(";
                _generate(left-1, right, str, result);
                str.erase(str.length()-1, 1);
            }
            if (right > 0)
            {
                str += ")";
                _generate(left, right-1, str, result);
                str.erase(str.length()-1, 1);
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        if (0 == n)
            return result;
        string str = "";
        _generate(n, n, str, result);
        return result;
    }

    void _method2(int n, int l, int r, vector<string>& result, string comb)
    {
        if (l == n && r == n)
        {
            result.push_back(comb);
            return;
        }
        if (l < n)
            _method2(n, l+1, r, result, comb+"(");
        if (r < l)
            _method2(n, l, r+1, result, comb+")");
    }

    vector<string> method2(int n)
    {
        vector<string> results;
        string comb;
        _method2(n, 0, 0, results, "");
        return results;
    }
};

int main()
{
    Solution s;
    vector<string> result = s.generateParenthesis(4);
    vector<string> result2 = s.method2(4);
    cout<<result.size()<<endl;
    cout<<result2.size()<<endl;
    return 0;
}
