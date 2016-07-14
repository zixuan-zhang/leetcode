/*******************************************************************************
 *  @File  : 190_reverse_bits.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 14 Jul 2016 10:17:55 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
 * return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 */ 

#include <iostream>

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n) {
        int bits[32];
        for (int i = 1; i <= 32; ++i)
        {
            bits[32-i] = (n & 1);
            n = n >> 1;
        }
        int start = 0;
        int end = 31;
        while (start < end)
        {
            int temp = bits[start];
            bits[start] = bits[end];
            bits[end] = temp;
            start++;
            end--;
        }
        uint32_t result = 0;
        for (int i = 0; i < 31; ++i)
        {
            result |= bits[i];
            result = result << 1;
        }
        result |= bits[31];
        return result;
    }

    uint32_t reverseBits1(uint32_t n)
    {
        int m = 0;
        for (int i = 0; i < 32; ++i)
        {
            m <<= 1;
            m |= (n & 1);
            n >>= 1;
        }
        return m;
    }
};

int main()
{
    Solution s;
    uint32_t number = 43261596;
    //uint32_t number = 1;
    uint32_t result = s.reverseBits1(number);
    cout<<result<<endl;
    return 0;
}
