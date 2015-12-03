/*******************************************************************************
 *  @File  : 043_multiply_strings.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月03日 星期四 08时03分41秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given two numbers represented as strings, return multiplication of the
 * numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string multiply_single_num(string num1, char num2)
    {
        if ('0' == num2 || "0" == num1)
            return "0";
        string empty = "";

        int num = num2 - '0';
        int adder = 0;
        string result = "";
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            int temp1 = num1[i] - '0';
            char remainder = (temp1 * num + adder) % 10 + '0';
            string temp2 = empty + remainder;
            result = temp2 + result;
            adder = (temp1 * num + adder) / 10;
        }
        if (adder)
        {
            char remainder = (adder + '0');
            string temp2 = empty + remainder;
            result = temp2 + result;

        }
        return result;
    }

    string plus(string num1, string num2)
    {
        if ("0" == num1)
            return num2;
        if ("0" == num2)
            return num1;
        string empty = "";
        string result = "";
        int adder = 0;
        int index = 0;
        while (index < num1.size() && index < num2.size())
        {
            int num1index = num1.size() - 1 - index;
            int num2index = num2.size() - 1 - index;

            int digit1 = num1[num1index] - '0';
            int digit2 = num2[num2index] - '0';

            char temp1 = (digit1 + digit2 + adder) % 10 + '0';
            adder = (digit1 + digit2 + adder) / 10;
            string remainder = empty + temp1;
            result = remainder + result;

            index++;
        }
        while (index < num1.size())
        {
            int num1index = num1.size() - 1 - index;
            int digit1 = num1[num1index] - '0';
            char temp3 = (digit1 + adder) % 10 + '0';
            adder = (digit1 + adder) / 10;
            string remainder = empty + temp3;
            result = remainder + result;
            index++;
        }

        while (index < num2.size())
        {
            int num2index = num2.size() - 1 - index;
            int digit = num2[num2index] - '0';
            char temp4 = (digit + adder) % 10 + '0';
            adder = (digit + adder) / 10;
            string remainder = empty + temp4;
            result = remainder + result;
            index++;
        }
        if (adder)
        {
            string temp2 = "1";
            result = temp2 + result;
        }
        return result;
    }

    string multiply(string num1, string num2)
    {
        if ("0" == num2 || "0" == num1)
            return "0";
        string result = "0";
        for (int i = 0; i < num2.size(); ++i)
        {
            int index = num2.size() - 1 - i;
            string subResult = multiply_single_num(num1, num2[index]);
            for (int j = 0; j < i; ++j)
                subResult += '0';
            result = plus(result, subResult);
        }
        return result;
        return "";
    }
};

int main()
{
    Solution s;
    string num1 = "90909090909090909090";
    string num2 = "80808080808080808080";
    //cout<<s.multiply_single_num(num1, num2)<<endl;
    cout<<s.multiply(num1, num2)<<endl;

    return 0;
}
