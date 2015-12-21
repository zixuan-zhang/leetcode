/*******************************************************************************
 *  @File  : 264_ugly_number_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月21日 星期一 16时39分27秒
 ******************************************************************************/

/*
 * Question:
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 * Hint:
 *
 * The naive approach is to call isUgly for every number until you reach the
 * nth one. Most numbers are not ugly. Try to focus your effort on generating
 * only the ugly ones.
 *
 */

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isUgly(int number)
    {
        while (true)
        {
            bool flag = true;
            if (number % 2 == 0)
            {
                number /= 2;
                flag = false;
            }
            if (number % 3 == 0)
            {
                number /= 3;
                flag = false;
            }
            if (number % 5 == 0)
            {
                number /= 5;
                flag = false;
            }
            if (flag)
                break;
        }
        if (number == 1)
            return true;
        else
            return false;
    }

    /**
     * This method will cause time limit error
     */
    int nthUglyNumber(int n)
    {
        int cnt = 0;
        int number = 1;
        while (true)
        {
            if (isUgly(number))
            {
                cnt ++;
                if (cnt == n)
                    return number;
            }
            number ++;
        }
    }
};

int main()
{

    Solution s;
    int result = s.nthUglyNumber(10);
    cout<<result<<endl;

    return 0;
}
