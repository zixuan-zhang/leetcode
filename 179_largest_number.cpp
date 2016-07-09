/*******************************************************************************
 *  @File  : 179_largest_number.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 09 Jul 2016 04:38:19 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a list of non negative integers, arrange them such that they form the largest number.
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * Note: The result may be very large, so you need to return a string instead of an integer.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct Compare{
    bool operator() (int a, int b)
    {
        // If a or b equals 0
        vector<int> a_vec;
        vector<int> b_vec;

        if (0 == a)
            return false;
        if (0 == b)
            return true;

        while (a != 0)
        {
            a_vec.push_back(a % 10);
            a /= 10;
        }
        reverse(a_vec.begin(), a_vec.end());

        while (b != 0)
        {
           b_vec.push_back(b % 10);
           b /= 10;
        }
        reverse(b_vec.begin(), b_vec.end());

        for (int i = 0; i < a_vec.size(); ++i)
            b_vec.push_back(a_vec[i]);
        for (int i = 0; i < b_vec.size(); ++i)
            a_vec.push_back(b_vec[i]);

        for (int i = 0; i < a_vec.size(); ++i)
        {
            if (a_vec[i] > b_vec[i])
                return true;
            else if (a_vec[i] < b_vec[i])
                return false;
        }
        return true;
    }
} compare;

class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        if (nums.size() == 0)
            return "";
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0)
            return "0";
        string largest = "";
        for (int i = 0; i < nums.size(); ++i)
            largest += to_string(nums[i]);
        return largest;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    for (int i = 0; i < 1000; ++i)
        nums.push_back(0);
    string largest = s.largestNumber(nums);
    cout<<largest<<endl;
    return 0;
}
