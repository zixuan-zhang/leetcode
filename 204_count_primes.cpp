/*******************************************************************************
 *  @File  : 204_count_primes.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 24 Jul 2016 08:55:32 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 */

#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1 || n == 2)
            return 0;
        vector<int> counts(n-1, 1);
        counts[0] = 0;

        for (int i = 2; i * i < n; ++i)
        {
            for (int j = i*i; j < n; j += i)
            {
                counts[j-1] = 0;
            }
        }

        int result = 0;
        for (int i = 0; i < counts.size(); ++i)
            result += counts[i];
        return result;
    }
};

int main()
{
    Solution s;
    int result = s.countPrimes(6);
    cout<<result<<endl;
    return 0;
}
