/*******************************************************************************
 *  @File  : 205_isomorphic_strings.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 24 Jul 2016 08:35:27 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 * Given "foo", "bar", return false.
 * Given "paper", "title", return true.
 *
 */

#include <iostream>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for (int i = 0; i < s.length(); ++i)
        {
            if (m1.find(s[i]) != m1.end() && m1[s[i]] != t[i])
                return false;
            if (m2.find(t[i]) != m2.end() && m2[t[i]] != s[i])
                return false;
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        return true;
    }
};

int main()
{
    return 0;
}
