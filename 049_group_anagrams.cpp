/*******************************************************************************
 *  @File  : 049_group_anagrams.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月16日 星期三 08时30分38秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 *
 * [
 *  ["ate", "eat","tea"],
 *  ["nat","tan"],
 *  ["bat"]
 * ]
 * Note:
 *   For the return value, each inner list's elements must follow the lexicographic order.
 *   All inputs will be in lower-case.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 < s2;
}

class Solution
{
public:
    /*
     * Solution:
     *
     * This method cost about 400ms, beats 0.7% submits. What a shame
     */
    vector<vector<string> > groupAnagrams(vector<string>& strs)
    {
        vector<vector<string> > result;
        sort(strs.begin(), strs.end(), cmp);

        vector<string> strsTemp(strs.size());
        for (int i = 0; i < strs.size(); ++i)
        {
            strsTemp[i] = strs[i];
            sort(strsTemp[i].begin(), strsTemp[i].end());
        }

        vector<string> comb;
        int index = 0;
        while (index < strs.size())
        {
            while (index+1 < strs.size() && strsTemp[index] == strsTemp[index+1])
            {
                comb.push_back(strs[index]);
                index ++;
            }
            comb.push_back(strs[index]);
            index ++;

            result.push_back(comb);
            comb.clear();
        }

        for (int i = 0; i < result.size(); ++i)
        {
            sort(result[i].begin(), result[i].end());
        }

        return result;
    }

};

int main()
{
    string _strs[5] = {"eat", "tea", "tan", "ate", "bat"};
    vector<string> strs(5);
    for (int i = 0; i < 5; ++i)
        strs[i] = _strs[i];

    vector<vector<string> > result;
    Solution s;
    result = s.groupAnagrams(strs);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
