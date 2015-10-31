/*******************************************************************************
 *  @File  : 031_next_permutation.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : http://www.noathinker.com
 *  @Date  : 2015年10月31日 星期六 09时49分15秒
 ******************************************************************************/

/*
 * Question:
 *
 * Implement next permutation, which rearranges numbers into the lexicographically
 * next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding
 * outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    void permutation(string number, vector<string>& result, string& generate, int deep, bool* used)
    {
        if (deep == number.size())
        {
            vector<string>::iterator it = find(result.begin(), result.end(), generate);
            if (it == result.end())
                result.push_back(generate);
        }
        else
        {
            for (int i = 0; i < number.size(); ++i)
            {
                if (!used[i])
                {
                    generate += number[i];
                    used[i] = true;
                    permutation(number, result, generate, deep+1, used);
                    //generate.pop_back();
                    generate.erase(generate.length()-1, 1);
                    used[i] = false;
                }
            }
        }
    }
    /*
     * This solution is kind of complicated and less efficient
     */
    void nextPermutation(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return ;
        int flag = -1;
        for (int i = nums.size() - 1; i > 0; --i)
        {
            if (nums[i-1] < nums[i])
            {
                flag = i - 1;
                break;
            }
        }
        if (-1 == flag)
        {
            sort(nums.begin(), nums.end());
            return ;
        }
        string number;
        for (int i = flag; i < nums.size(); ++i)
            number += (nums[i] - 0 + '0');
        string temp = number;
        vector<string> result;
        string generate;
        bool* used = new bool[number.length()];
        for (int i = 0; i < number.length(); ++i)
            used[i] = false;
        sort(&number[0], &number[0] + number.length());
        permutation(number, result, generate, 0, used);
        //now we have all possible permutataion
        
        for (int i = 0; i < result.size(); ++i)
        {
            if (temp == result[i])
            {
                temp = result[i+1];
                break;
            }
        }
        for (int i = flag; i < nums.size(); ++i)
        {
            nums[i] = temp[i-flag] - '0';
        }
    }

    /*
     * This solution is good
     */
    void nextPermutation1(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return ;
        int flag = -1;
        for (int i = nums.size() - 1; i > 0; --i)
        {
            if (nums[i-1] < nums[i])
            {
                flag = i - 1;
                break;
            }
        }
        if (-1 == flag) //这个是最大的
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int temp = nums[flag+1];
        int index = flag + 1;
        for (int i = flag + 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[flag]&& nums[i] < temp)
            {
                temp = nums[i];
                index = i;
            }
        }
        nums[index] = nums[flag];
        nums[flag] = temp;
        sort(nums.begin()+flag+1, nums.end());
    }
};

int main()
{
    //string str = "227543221";
    string str = "10";
    vector<int> nums;
    for (int i = 0; i < str.length(); ++i)
        nums.push_back(str[i] - '0');
    Solution s;
    s.nextPermutation1(nums);
    for (int i = 0; i < nums.size(); ++i)
        cout<<nums[i]<<" ";
    cout<<endl;

    return 0;
}
