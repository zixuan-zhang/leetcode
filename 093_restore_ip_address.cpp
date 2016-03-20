/*******************************************************************************
 *  @File  : 093_restore_ip_address.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月20日 星期日 21时00分57秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 */


class Solution {
public:
    void generate(int step, string s, int index, vector<string>& com,
            vector<string>& ips)
    {
        if (step == 4 && index == s.length())
        {
            string ip = "";
            for (int i = 0; i < 4; ++i)
            {
                if (i == 3)
                    ip += com[i];
                else
                    ip += (com[i] + '.');
            }
            ips.push_back(ip);
        }
        if (step == 4)
            return;
        int base = 0;
        int begin = index;
        while (index < s.length())
        {
            base = base * 10 + s[index] - '0';
            if (base <= 255)
            {
                index++;
                string temp = s.substr(begin, index-begin);
                com[step] = temp;
                generate(step+1, s, index, com, ips);
                if (base == 0)
                    break;
            }
            else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> com(4);
        vector<string> result;
        generate(0, s, 0, com, result);
        return result;
    }
};

