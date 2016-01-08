/*******************************************************************************
 *  @File  : 091_decode_ways.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年01月08日 星期五 17时53分17秒
 ******************************************************************************/

/*
 * Question:
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * 使用动规的方法
     */
    int numDecodings1(string s) {
        int size = s.length();
        if (0 == size)
            return 0;
        if (1 == size)
        {
            if (s[0] - '0' == 0)
                return 0;
            else
                return 1;
        }
        // at least two characters
        int* count = new int[size+1];
        // initialize
        if (s[size-1] != '0')
        {
            count[size] = 1;
            count[size-1] = 1;
        }
        else
        {
            int num1 = s[size-2] - '0';
            int num2 = s[size-1] - '0';
            int num = num1 * 10 + num2;
            if (num > 0 && num <= 26)
            {
                count[size] = 1;
                count[size-1] = 0;
            }
            else
                return 0;
        }
        for (int i = size-2; i >= 0; --i)
        {
            if (s[i] == '0')
                count[i] = 0;
            else
            {
                int count2 = 0;
                int num1 = s[i] - '0';
                int num2 = s[i+1] - '0';
                int num = num1 * 10 + num2;
                if (num >0 && num <= 26)
                    count2 = count[i+2];
                count[i] = count[i+1] + count2;
            }
        }
        return count[0];

    }

    void decode(string s, int index, int& count)
    {
        if (index == s.length())
        {
            count++;
            return;
        }
        if (s[index] == '0')
            return;
        decode(s, index+1, count);
        if (index < s.length()-1)
        {
            int first = s[index] - '0';
            int second = s[index+1] - '0';
            if (first * 10 + second <= 26)
                decode(s, index+2, count);
        }
    }
    /*
     * Method: This method will cause TLE
     */
    int numDecodings(string s) {
        if (0 == s.length())
            return 0;
        int count = 0;
        decode(s, 0, count);
        return count;
    }
};

int main()
{
    return 0;
}
