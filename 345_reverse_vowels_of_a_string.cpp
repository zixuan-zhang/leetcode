/*******************************************************************************
 *  @File  : 345_reverse_vowels_of_a_string.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 29 May 2016 06:36:18 PM CST
 ******************************************************************************/

/*
 * Question:
 * Write a function that takes a string as input and reverse only the vowels of a string.
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        while (start < end)
        {
            while (start < end && !vowels(s[start]))
                start++;
            while (start < end && !vowels(s[end]))
                end--;
            if (start < end)
            {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }
        }
        return s;
    }

private:
    bool vowels(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }

};

int main()
{
    string str = "leetcode";
    Solution s;
    string result = s.reverseVowels(str);
    cout<<result<<endl;

    return 0;
}
