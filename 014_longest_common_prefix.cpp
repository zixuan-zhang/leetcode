/*******************************************************************************
 *  @File  : 014_longest_common_prefix.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月14日 星期三 21时39分53秒
 ******************************************************************************/

/*
 * Question:
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string prefix = "";
        if (0 == strs.size())
            return prefix;
        int index = 0;
        while (index < strs[0].length())
        {
            char c = strs[0][index];
            for (int i = 1; i < strs.size(); ++i)
            {
                if (index >= strs[i].length())
                    return prefix;
                if (strs[i][index] != c)
                    return prefix;
            }
            index ++;
            prefix += c;
        }
        return prefix;
    }
};

int main()
{
    Solution s;
    vector<string> strs;
    strs.push_back("122");
    strs.push_back("123");
    strs.push_back("133");
    string prefix = s.longestCommonPrefix(strs);
    cout<<prefix<<endl;
    return 0;
}
