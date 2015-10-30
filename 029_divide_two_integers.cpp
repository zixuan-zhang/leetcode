/*******************************************************************************
 *  @File  : 029_divide_two_integers.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月24日 星期六 22时49分10秒
 ******************************************************************************/

/*
 * Question:
 *
 * Divide two integers without using multiplication, division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 *
 */

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
public:
    int divide(int dividend_p, int divisor_p)
    {
        if (0 == divisor_p)
            return INT_MAX;
        if (0 == dividend_p)
            return 0;
        if (INT_MIN == dividend_p && -1 == divisor_p) // overflow
            return INT_MAX;
        long long dividend = dividend_p;
        long long divisor = divisor_p;
        int factor = (dividend < 0 ? -1 : 1) * (divisor < 0 ? -1 : 1);
        dividend = dividend < 0 ? -dividend : dividend;
        divisor = divisor < 0 ? -divisor : divisor;

        long long res = 0;
        while (dividend >= divisor)
        {
            for (int i = 0; ; ++i)
            {
                if (dividend - (divisor << i) >= 0)
                {
                    dividend -= (divisor << i);
                    res += (1 << i);
                }
                else
                    break;
            }
        }
        return factor * res;
    }
};

int main()
{
    Solution s;
    cout<<s.divide(INT_MIN, -1)<<endl;
    return 0;
    for (int i = INT_MIN; i <= INT_MAX; ++i)
    {
        for (int j = INT_MIN; j <= INT_MAX; ++j)
        {
            cout<<i<<"\t"<<j<<endl;
            int res = s.divide(i, j);
            if (j == 0)
            {
                if (res != INT_MAX)
                    cout<<"elert: "<<i<<" "<<j<<endl;
            }
            else if (res != (i / j))
            {
                cout<<"elert: "<<i<<" "<<j<<"res: "<<res<<"equal is "<<(i / j)<<endl;
                return 0;
            }
        }
    }
    cout<<"congradulations"<<endl;
    return 0;
}
