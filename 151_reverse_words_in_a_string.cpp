/*******************************************************************************
 *  @File  : 151_reverse_words_in_a_string.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 15 May 2016 04:36:20 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int start = 0;
        int end = s.length() - 1;
        while (start < end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        int pointer = 0;
        while (pointer < s.length())
        {
            while (pointer < s.length() && s[pointer++] == ' ') ;
            start = pointer;
            while (pointer < s.length() && s[pointer++] != ' ') ;
            end = pointer-1;
            int ss = start;
            int ee = end;
            while (ss < ee)
            {
                char temp = s[ss];
                s[ss] = s[ee];
                s[ee] = temp;
                ss++;
                ee--;
            }
        }
    }
};

int main()
{
    return 0;
}
