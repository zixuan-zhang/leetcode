/*******************************************************************************
 *  @File  : 060_permutaion_sequence.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 15 Mar 2016 08:48:42 AM CST
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void generate(int step, string& base, int begin,  vector<string>& result)
    {
        if (step == base.length())
        {
            result.push_back(base);
            return;
        }
        for (int i = begin; i < base.length(); ++i)
        {
            char temp = base[begin];
            base[begin] = base[i];
            base[i] = temp;
            generate(step+1, base, begin+1, result);
            temp = base[begin];
            base[begin] = base[i];
            base[i] = temp;
        }
    }

    /*
     * Method 1: generate all sequence and select kth
     */
    string getPermutation1(int n, int k)
    {
        vector<string> result;
        string base = "";
        for (int i = 1; i <= n; ++i)
        {
            base += '1' + i - 1;
        }
        generate(0, base, 0, result);
        return result[k-1];
    }

    string getPermutation(int n, int k)
    {
        k -= 1;
        // initialize
        vector<int> nums;
        for (int i = 1; i <= n; ++i)
            nums.push_back(i);
        vector<int> counts(n, 1);
        for (int i = 1; i < n; ++i)
            counts[i] = counts[i-1] * (i+1);

        string res = "";
        for (int i = counts.size()-2; i >= 0; --i)
        {
            //sort(nums.begin(), nums.end());
            int index = k / counts[i];
            res += nums[index] + '0';
            k = k % counts[i];
            nums.erase(nums.begin() + index);
        }
        res += nums[0] + '0';

        return res;
    }
};


int main()
{
    Solution s;
    string str = s.getPermutation(4, 5);
    cout<<str<<endl;
    return 0;
}
