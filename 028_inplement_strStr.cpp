/*******************************************************************************
 *  @File  : 028_inplement_strStr.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月22日 星期四 18时37分10秒
 ******************************************************************************/

/*
 * Question:
 *
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if ("" == needle)
            return 0;
        if ("" == haystack)
            return -1;
        int lenHay = haystack.length();
        int lenNeedle = needle.length();
        if (lenHay < lenNeedle)
            return -1;
        for (int i = 0; i < lenHay - lenNeedle + 1; ++i)
        {
            bool flag = true;
            for (int j = 0; j < lenNeedle; ++j)
            {
                if (haystack[i+j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }
};

int main()
{
    string haystack = "";
    string needle = "";
    Solution s;
    cout<<s.strStr(haystack, needle)<<endl;
    return 0;
}
