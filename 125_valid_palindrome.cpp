/*******************************************************************************
 *  @File  : 125_valid_palindrome.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月17日 星期四 09时59分43秒
 ******************************************************************************/


/*
 * Question:
 *
 * Given a string, determine if it is a palindrome, considering only alphanumeric
 * characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to
 * ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 */

#include <algorithm>
class Solution {
public:
    bool isAlpha(char c)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return true;
        else
            return false;
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            while (left < right && !isAlpha(s[left]))
                left++;
            while (left < right && !isAlpha(s[right]))
                right--;
            if (left < right && toupper(s[left]) != toupper(s[right]))
                return false;
            left ++;
            right --;
        }
        return true;
    }
};
