/*******************************************************************************
 *  @File  : 201_bitwise_and_of_numbers_range.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 17 Jul 2016 09:57:11 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise
 * AND of all numbers in this range, inclusive.
 *
 * For example, given the range [5, 7], you should return 4.
 *
 */

#include <iostream>

using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int temp = 0x80000000;
        int result = 0;
        for (int i = 0; i < 32; ++i, temp >>= 1)
        {
            if ((m & temp) == (n & temp))
                result |= (m & temp);
            else
                break;
        }

        return result;
    }
};


int main()
{
    Solution s;
    int result = s.rangeBitwiseAnd(0, 2);
    cout<<result<<endl;
    return 0;
}
