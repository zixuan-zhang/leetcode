/*******************************************************************************
 *  @File  : 135_candy.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 28 May 2016 04:46:39 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 *
 */

#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        if (ratings.size() == 0)
            return 0;
        int count = 1;
        int current = 1;
        int len = 1;
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i-1])
                current++;
            if (ratings[i] == ratings[i-1])
                current = 1;
            if (ratings[i] < ratings[i-1])
            {
                current--;
                len++;
            }
            count += current;
            if ((i == ratings.size() -1 || ratings[i] <= ratings[i+1]) && len > 1)
            {
                if (current < 1)
                    count += (1 - current) * len;
                else
                    count -= (current - 1) * (len - 1);
                len = 1;
                current = 1;
            }
        }
        return count;
    }
};

int main()
{
    int array[] = {0,1,1,2,3,4,3,2,2,2,1};
    vector<int> nums;
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
        nums.push_back(array[i]);
    Solution s;
    int count = s.candy(nums);
    cout<<count<<endl;
    return 0;
}
