/*******************************************************************************
 *  @File  : 242_valid_anagram.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月17日 星期四 09时57分32秒
 ******************************************************************************/

/*
 * Question:
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        int len = s.length();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < len; ++i)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
};
