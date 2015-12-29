/*******************************************************************************
 *  @File  : 066_plus_one.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月29日 星期二 20时51分31秒
 ******************************************************************************/



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int temp;
        for (int i = digits.size()-1; i >= 0; --i)
        {
            temp = digits[i];
            digits[i] = (temp + carry) % 10;
            carry = (temp + carry) / 10;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
