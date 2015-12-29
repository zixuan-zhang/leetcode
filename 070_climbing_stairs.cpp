/*******************************************************************************
 *  @File  : 070_climbing_stairs.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 29 Dec 2015 09:17:43 PM CST
 ******************************************************************************/

/*
 * Question;
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways
 * can you climb to the top?
 *
 */

#include <iostream>

using namespace std;


class Solution
{
public:
    int climbStairs(int n)
    {
        int* numbers = new int[n+1];
        numbers[1] = 1;
        numbers[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            numbers[i] = numbers[i-1] + numbers[i-2];
        }
        return numbers[n];
    }
};

int main()
{
    Solution s;
    int result = s.climbStairs(6);
    cout<<result<<endl;
    return 0;
}
