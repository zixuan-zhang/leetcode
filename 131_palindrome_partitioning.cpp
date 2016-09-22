/*******************************************************************************
 *  @File  : 131_palindrome_partitioning.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 22 Sep 2016 10:34:05 AM CST
 ******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string> > partition(string s)
    {
        vector<vector<string> > results;
        vector<string> path;
        dfs(s, 0, results, path);
        return results;
    }

    void dfs(string s, int step, vector<vector<string> >& results,
            vector<string>& path)
    {
        if (step == s.length())
        {
            results.push_back(path);
            return;
        }
        for (int i = step; i < s.length(); ++i)
        {
            if (isPalindrome(s, step, i))
            {
                path.push_back(s.substr(step, i - step + 1));
                dfs(s, i+1, results, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    string str = "aab";
    Solution s;
    vector<vector<string> > results = s.partition(str);
    for (int i = 0; i < results.size(); ++i)
    {
        for (int j = 0; j < results[i].size(); ++j)
            cout<<results[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
