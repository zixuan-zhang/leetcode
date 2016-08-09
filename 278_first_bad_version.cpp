/*******************************************************************************
 *  @File  : 278_first_bad_version.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 09 Aug 2016 07:33:30 PM CST
 ******************************************************************************/

#include <iostream>

using namespace std;

bool isBadVersion(int version)
{
    return version >= 1702766719;
    // return version >= 1234567;
}

class Solution {
public:
    int firstBadVersion(int n) {
        long long start = 1;
        long long end = n;
        long long mid = start;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (mid == 1)
            {
                if (isBadVersion(mid))
                    break;
                else
                    start = mid + 1;
            }
            else
            {
                bool pre = isBadVersion(mid-1);
                bool cur = isBadVersion(mid);
                if (!pre && cur)
                    break;
                else if (!pre && !cur)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return mid;
    }
};

int main()
{
    Solution s;
    int result = s.firstBadVersion(2147483647);
    cout<<result<<endl;
    return 0;
}
