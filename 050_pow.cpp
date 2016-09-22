/*******************************************************************************
 *  @File  : 050_pow.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 18 Dec 2015 05:54:05 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 *  Implement pow(x, n).
 *
 */

#include <iostream>

using namespace std;


class Solution {
public:
    /*
     * method:
     * 这道题就这么过了，连溢出情况都么有考虑，只稍微做了下加速。
     */
    double myPow(double x, int n) {
        if (0 == n)
            return 1;
        if (0 == x)
            return 0;
        if (1 == x)
            return 1;
        
        if (-1 == x)
        {
            if (n > 0)
                return n % 2 == 0 ? 1 : -1;
            else
            {
                int s = 0 - n;
                return s % 2 == 0 ? 1 : -1;
            }
        }
        
        long double base = 1.0;
        int index = 0;
        bool pos = n > 0 ? true : false;
        int s = pos == true ? n : 0 - n;
    
        while (index < s)
        {
            double b = x;
            for (int i = 1; index + i <= s; i *= 2)
            {
                base *= b;
                if (base == 0)
                    return 0;
                b *= b;
                index += i;
            }
        }
        
        long double res = pos == true ? base : 1 / base;
        return res;
    }

    double method2(double x, int n)
    {
        bool negative = false;
        if (n = 0)
            return 1;
        if (n < 0)
        {
            negative = true;
            n = 0 - n;
        }
        if (n == 1)
            return x;
        double res = method2(x, n/2) * method2(x, n/2);
        if (n & 1)
            res *= x;
        if (negative)
            res = 1 / res;
        return res; 
    }
};

int main()
{
    Solution s;
    double res = s.method2(8.88023, 3);
    cout<<res<<endl;
    return 0;
}
