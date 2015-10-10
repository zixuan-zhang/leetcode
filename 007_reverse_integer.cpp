/*******************************************************************************
 *  @File  : 007_reverse_integer.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月10日 星期六 09时52分52秒
 ******************************************************************************/

/*
 * Question:
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int max = INT_MAX;
        int res = 0;
        int temp;
        if (x < 0)
            temp = -1 * x;
        else
            temp = x;
        //如果用STL运行速度肯定会变慢
        //vector<int> number;
        int number[10];
        int count = 0;
        while (temp > 0)
        {
            //number.push_back(temp % 10);
            number[count++] = temp % 10;
            temp = temp / 10;
        }
        for (int i = 0; i < count; ++i)
        {
            if ( res > (max - number[i]) / 10)
                return 0;
            res = res * 10 + number[i];
        }
        if (x < 0)
            res = res * -1;
        return res;
    }
};

int main()
{
    int cases[] = { 123, -123, 320, -320, 0, -1, -0, 1534236469};
    Solution s;
    for (int i = 0; i < 8; ++i)
    {
        int res = s.reverse(cases[i]);
        cout<<res<<endl;
    }
    return 0;
}
