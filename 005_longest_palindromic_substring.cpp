/*******************************************************************************
 *  @File  : 004_longest_palindromic_substring.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月09日 星期五 08时58分01秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a string S, find the longest palindromic substring in S. You may assume
 * that the maximum length of S is 1000, and there exists one unique longest
 * palindromic substring.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool is_Palidrome(string str, int start, int end)
    {
        int s = start;
        int e = end;
        while (s < e)
        {
            if (str[s++] != str[e--])
                return false;
        }
        return true;
    }

    /*
    // 这个时间复杂度O(n^3)
    string longestPalindrome(string s) {
        int len = s.length();
        if (len <= 2)
            return s;
        for (int i = len - 1; i >= 1; --i)
        {
            for (int j = 0; j + i < len; j++)
            {
                int flag = true;
                int ss = j;
                int ee = j+i;
                while (ss < ee)
                {
                    if (s[ss++] != s[ee--])
                        flag = false;
                }
                if (flag)
                {
                    string subString = s.substr(j, i+1);
                    return subString;
                }
            }
        }
    }
    */

    // 以字符为中心向外扩张，时间复杂度O(n^2)
    string longestPalindrome(string s)
    {
        if (s.length() < 2)
            return s;
        int maxLength = 1;
        string subString;
        for (int i = 0; i < s.length(); ++i)
        {
            int ss = i - 1;
            int ee = i + 1;
            while ( ss >= 0 && ee < s.length())
            {
                if (s[ss] != s[ee])
                    break;
                ss--;
                ee++;
            }
            if (maxLength < (--ee) - (++ss) + 1)
            {
                subString = s.substr(ss, ee - ss + 1);
                maxLength = ee - ss + 1;
            }

            ss = i;
            ee = i + 1;
            while (ss >= 0 && ee < s.length())
            {
                if (s[ss] != s[ee])
                    break;
                ss--;
                ee++;
            }
            if (maxLength < (--ee) - (++ss) + 1)
            {
                subString = s.substr(ss, ee - ss + 1);
                maxLength = ee - ss + 1;
            }
        }
        return subString;
    }
};

int main()
{
    Solution s;
    string str = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
    string str1 = "abac";
    string str2 = "abb";
    string str3 = "aa";
    string result  = s.longestPalindrome(str3);
    cout<<result<<endl;
    return 0;
}
