/*******************************************************************************
 *  @File  : 191_number_of_1_bits.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 16 Jul 2016 04:23:04 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 *
 */

#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (0 != n)
        {
            count++;
            n = (n & (n-1));
        }
        return count;
    }
};

int main()
{
    Solution s;
    int result = s.hammingWeight(16);
    cout<<result<<endl;
    return 0;
}
