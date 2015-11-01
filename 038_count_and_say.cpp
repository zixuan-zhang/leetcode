/*******************************************************************************
 *  @File  : 038_count_and_say.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年11月01日 星期日 15时35分03秒
 ******************************************************************************/

/*
 * Question:
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (1 == n)
            return "1";
        if (2 == n)
            return "11";
        string pre = countAndSay(n-1);
        string result;
        char cPre = pre[0];
        int count = 1;
        for (int i = 1; i < pre.size(); ++i)
        {
            if (pre[i] == cPre)
                count++;
            else
            {
                char tmp = count + '0';
                result = result + tmp + cPre;
                cPre = pre[i];
                count = 1;
            }
        }
        char tmp = count + '0';
        result = result + tmp + cPre;
        return result;

    }
};

int main()
{
    Solution s;
    cout<<s.countAndSay(6)<<endl;
    return 0;
}

