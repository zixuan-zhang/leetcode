/*******************************************************************************
 *  @File  : 338_couting_bits.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Mon 20 Jun 2016 05:34:27 PM CST
 ******************************************************************************/

/*
 * Question:
 * Given a non negative integer number num. For every numbers i in the range
 * 0 ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 *
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 *
 * Hint:
 * You should make use of what you have produced already.
 * Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
 * Or does the odd/even status of the number help you in calculating the number of 1s?
 * 
 */

#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> result;
        result.push_back(0);

        if (0 == nums)
            return result;

        long base = 1;
        int index = 1;
        long temp;
        while (i <= num)
        {
            temp = base * 2;
            while (i <= num && i < temp)
                result.push_back(1 + result[i++ - base]);
        }
        base *= 2;
        return result;
    }
};

int main()
{
    return 0;
}
