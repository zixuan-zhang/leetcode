/*******************************************************************************
 *  @File  : 008_string_to_integer.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月10日 星期六 11时05分00秒
 ******************************************************************************/

/*
 * Question:
 *
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge,
 * please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given
 * input specs). You are responsible to gather all the input requirements up front.
 *
 */

#include <iostream>
#include <climits>

using namespace std;

/*
 * Possible Input Cases
 *  123, -123, 0123, -0123, 111e-3
 * Attention:
 *  1. overflow
 */

class Solution
{
public:
    int myAtoi(string str)
    {
        int negFlag = false;
        int len = str.length();
        if (0 == len)
            return 0; // error & empty case

        int index = 0;
        while (index < len && str[index] == ' ')
            index ++; // strip space character

        if (index >= len)
            return 0; // error & "   " case
            
        int res = 0;
        if ('-' == str[index])
            negFlag = true;
        else if ('+' == str[index])
            negFlag = false; // + signed
        else if (str[index] >= '0' && str[index] <= '9')
            res = str[index] - '0';
        else
            return 0; // error
        for (int i = index+1; i < len; ++i)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                if (!negFlag)
                    if ((INT_MAX - (str[i] - '0')) / 10 >= res)
                        res = res * 10 + str[i] - '0';
                    else
                        return INT_MAX; // if overflow, output MAX
                else if (negFlag)
                    if ( (INT_MIN + str[i] - '0') / -10 >= res)
                        res = res * 10 + str[i] - '0';
                    else
                        return INT_MIN; // if overflow, output MIN
            }
            else
                break;
        }
        if (negFlag)
            return -1 * res;
        else
            return res;
    }
};

int main()
{
    //cout<<INT_MAX<<" "<<INT_MIN<<endl;
    Solution s;
    string str = "2147483648";
    int res = s.myAtoi(str);
    cout<<res<<endl;
    return 0;
}
