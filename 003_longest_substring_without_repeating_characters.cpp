/*******************************************************************************
 *  @File  : 003_longest_substring_without_repeating_characters.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月08日 星期四 21时19分12秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a string, find the length of the longest substring without repeating
 * characters. For example, the longest substring without repeating letters
 * for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest
 * substring is "b", with the length of 1.
 *
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    int has_char(string s, int start, int end, char c)
    {
        for (int i = start; i <= end; ++i)
        {
            if (s[i] == c)
                return i;
        }
        return -1;
    }

    /*
    int lengthOfLongestSubstring(string s)
    {
        if ("" == s)
            return 0;
        int start = 0;
        int end = 0;

        int* len = new int[s.length()];
        len[0] = 1;
        for (int i = 1; i < s.length(); ++i)
        {
            int index = has_char(s, start, end, s[i]);
            if (-1 == index)
            {
                len[i] = len[i-1]  + 1;
            }
            else
            {
                len[i] = i - index;
                start = index + 1;
            }
            end = i;
        }
        int max = len[0];
        for (int i = 1; i < s.length(); ++i)
        {
            if (max < len[i])
                max = len[i];
        }
        return max;
    }
    */

    int lengthOfLongestSubstring(string s)
    {
        map<char, int> char2index;
        if ("" == s)
            return 0;
        int start = 0;
        int end = 0;
        int *len = new int[s.length()];
        len[0] = 1;
        char2index[s[0]] = 0;
        for (int i = 1; i < s.length(); ++i)
        {
            end = i;
            map<char, int>::iterator it = char2index.find(s[i]);
            if (it != char2index.end() && it->second >= start)
            if (
            {
                len[i] = i - it->second;
                start = it->second + 1;
            }
            else
            {
                len[i] = len[i-1] + 1;
            }
            char2index[s[i]] = i;
        }
        int max = len[0];
        for (int i = 1; i < s.length(); ++i)
        {
            if (max < len[i])
                max = len[i];
        }
        return max;
    }
};

int main()
{
    Solution s;
    int max = s.lengthOfLongestSubstring("abba");
    cout<<max<<endl;
    return 0;
}
