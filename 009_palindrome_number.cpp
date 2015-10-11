/*******************************************************************************
 *  @File  : 009_palindrome_number.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月11日 星期日 15时40分57秒
 ******************************************************************************/

/*
 * Question:
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 */

#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int temp = x;
        int cnt = 0;
        while (temp > 0)
        {
            cnt ++;
            temp = temp / 10;
        }

        for (int i = 0; i < cnt / 2; ++i)
        {
            int index1 = i;
            int index2 = cnt - index1 -1;
            int num1, num2;
            int rem;
            temp = x;
            for (int j = 0; j <= index1; ++j)
            {
                rem = temp % 10;
                temp = temp / 10;
            }
            num1 = rem;
            temp = x;
            for (int j = 0; j <= index2; ++j)
            {
                rem = temp % 10;
                temp = temp / 10;
            }
            num2 = rem;

            if (num1 != num2)
                return false;
        }
        return true;
    }

    bool isPalindrome1(int x)
    {
        int max = INT_MAX;
        if (x < 0)
            return false;
        int temp = x;
        int reverse = 0;
        while (temp)
        {
            if ((max - temp%10) / 10 < reverse) // overflow
                return false;
            reverse = reverse * 10 + temp % 10;
            temp = temp / 10;
        }
        if (reverse == x)
            return true;
        else
            return false;
        
    }

};

int main()
{
    Solution s;
    bool res = s.isPalindrome1(1534236469);
    cout<<res<<endl;
    return 0;
}
