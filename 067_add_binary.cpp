/*******************************************************************************
 *  @File  : 067_add_binary.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月29日 星期二 20时52分11秒
 ******************************************************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        if ("" == a)
            return b;
        if ("" == b)
            return a;
        int aSize = a.length();
        int bSize = b.length();
        string bigger = aSize > bSize ? a : b;
        string smaller = aSize > bSize ? b : a;
        int carry = 0;
        int index = 0;
        for (; index < smaller.length(); ++index)
        {
            int number = (bigger[bigger.length()-1-index]-'0' + smaller[smaller.length()-1-index]-'0' + carry) % 2;
            carry = (bigger[bigger.length()-1-index]-'0' + smaller[smaller.length()-1-index]-'0' + carry) / 2;
            bigger[bigger.length()-1-index] = number + '0';
        }
        if (carry)
        {
            for (; index < bigger.length(); ++index)
            {
                int number = (bigger[bigger.length()-1-index] - '0' + carry) % 2;
                carry = (bigger[bigger.length()-1-index] - '0' + carry) / 2;
                bigger[bigger.length()-1-index] = number + '0';
            } 
            if (carry)
            {
                bigger.insert(bigger.begin(), '1');
            }
        }
        return bigger;
    }
};
