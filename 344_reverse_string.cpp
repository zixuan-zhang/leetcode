/*******************************************************************************
 *  @File  : 344_reverse_string.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 24 Apr 2016 08:32:09 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh".
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseString(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        char temp;
        while (start < end)
        {
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        return s;
    }
};

int main()
{

    string s1 = "123456 789";
    Solution s;
    string r = s.reverseString(s1);
    cout<<s1<<endl;
    cout<<r<<endl;
    return 0;
}
