/*******************************************************************************
 *  @File  : 202_happy_number.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 17 Jul 2016 10:18:11 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will stay),
 * or it loops endlessly in a cycle which does not include 1. Those numbers for
 * which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 *
 */

#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> history;
        int temp = 0;
        while (true)
        {
            if (n == 1)
                return true;
            if (history.find(n) != history.end())
                return false;
            history.insert(n);
            temp = 0;
            while (n)
            {
                temp += pow(n % 10, 2);
                n /= 10;
            }
            n = temp;
        }
    }
};

int main()
{
    Solution s;
    bool result = s.isHappy(19);
    cout<<result<<endl;
    return 0;
}
