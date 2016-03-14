/*******************************************************************************
 *  @File  : 089_gray_code.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 13 Mar 2016 10:21:10 PM CST
 ******************************************************************************/

/*
 * The gray code is a binary numeral system where two successive values
 * differ in only one bit.
 * Given a non-negative integer n representing the total number of bits in
 * the code, print the sequence of gray code. A gray code sequence must begin with 0.
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 *
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence according to the
 * above definition.
 * For now, the judge is able to judge based on one instance of gray code
 * sequence. Sorry about that.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void generate(int step, int& base, vector<int>& result)
    {
        if (step == 0)
        {
            result.push_back(base);
            return;
        }
        generate(step-1, base, result);
        int isOne = (base >> (step - 1)) & 1;
        if (isOne)
        {
            base &= ~(1 <<(step-1));
            generate(step-1, base, result);
        }
        else
        {
            base |= (1<<(step-1));
            generate(step-1, base, result);
        }
    }

    vector<int> grayCode(int n)
    {
        vector<int> result;
        int base = 0;
        generate(n, base, result);
        return result;
    }
};


int main()
{
    Solution s;
    vector<int> result = s.grayCode(2);
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i]<<endl;
    return 0;
}
