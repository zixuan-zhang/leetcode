/*******************************************************************************
 *  @File  : 139_word_break.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Wed 22 Jun 2016 04:48:27 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 *
 *
 */

#include <iostream>
#include <unordered_set>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int match(string s, int start, unordered_set<string>& wordDict, int minLength, int maxLength, vector<int>& isMatchVec)
    {
        if (isMatchVec[start] != -1)
            return isMatchVec[start];
        int length = minLength;
        while (start + length <= s.length() && length <= maxLength)
        {
            string subString = s.substr(start, length);
            if (wordDict.find(subString) != wordDict.end())
            {
                int subMatch = match(s, start+length, wordDict, minLength, maxLength, isMatchVec);
                if (subMatch == 1)
                {
                    isMatchVec[start] = 1;
                    return 1;
                }
            }
            length++;
        }
        isMatchVec[start] = 0;
        return 0;
    }

    bool wordBreak(string s, unordered_set<string>& wordDict)
    {
        int minLength = INT_MAX;
        int maxLength = INT_MIN;
        for (unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); ++it)
        {
            minLength = min(minLength, (int)(it->length()));
            maxLength = max(maxLength, (int)(it->length()));
        }
        vector<int> isMatchVec(s.length()+1, -1);
        isMatchVec[s.length()] = 1;
        match(s, 0, wordDict, minLength, maxLength, isMatchVec);
        return isMatchVec[0] == 1 ? true : false;
    }
};

int main()
{
    unordered_set<string> wordDict;
    wordDict.insert("a");
    wordDict.insert("aa");
    wordDict.insert("aaa");
    wordDict.insert("aaaa");
    wordDict.insert("aaaaa");
    wordDict.insert("aaaaaa");

    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    Solution solution;
    bool result = solution.wordBreak(s, wordDict);
    cout<<result<<endl;

    return 0;
}
