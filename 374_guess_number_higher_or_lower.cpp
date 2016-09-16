/*******************************************************************************
 *  @File  : 374_guess_number_higher_or_lower.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 16 Sep 2016 09:21:17 PM CST
 ******************************************************************************/

#include <iostream>

using namespace std;

const int N = 88;
const int T = 100;

int guess(int number)
{
    return number == N ? 0 : (number > N ? 1 : -1);
}

class Solution
{
public:
    int _guessNumber(int begin, int end)
    {
        int mid = (begin + end) / 2;
        int res = guess(mid);
        switch (res)
        {
            case 0:
                return mid;
            case 1:
                return _guessNumber(begin, mid-1);
            default:
                return _guessNumber(mid+1, end);
        }
    }

    int guessNumber(int n)
    {
        //return _guessNumber(1, n);
        int start = 1;
        int end = n;
        int mid;
        while (true)
        {
            mid = (start + end) / 2;
            int res = guess(mid);
            if (res == 0)
                break;
            else if (res == 1)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return mid;
    }
};

int main()
{
    Solution s;
    cout<<s.guessNumber(T);
    return 0;
}
