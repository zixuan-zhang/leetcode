/*******************************************************************************
 *  @File  : 128_longest_consecutive_sequence.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 05 Apr 2016 10:11:41 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_map<int, int> longestCons;
        for (auto num : nums)
        {
            if (longestCons.find(num) != longestCons.end())
                continue;
            if (longestCons.find(num-1) == longestCons.end() &&
                    longestCons.find(num+1) == longestCons.end())
                longestCons[num] = 1;
            if (longestCons.find(num-1) != longestCons.end() &&
                    longestCons.find(num+1) != longestCons.end())
            {
                longestCons[num] = longestCons[num-1] + longestCons[num+1] + 1;
                longestCons[num+longestCons[num+1]] = longestCons[num];
                longestCons[num-longestCons[num-1]] = longestCons[num];
            }
            else if (longestCons.find(num-1) != longestCons.end())
            {
                longestCons[num] = longestCons[num-1] + 1;
                longestCons[num-longestCons[num-1]] = longestCons[num];
            }
            else if (longestCons.find(num+1) != longestCons.end())
            {
                longestCons[num] = longestCons[num+1] + 1;
                longestCons[num+longestCons[num+1]] = longestCons[num];
            }
        }
        int longest = 0;
        for (unordered_map<int,int>::iterator it = longestCons.begin();
                it != longestCons.end(); ++it)
            longest = max(longest, it->second);
        return longest;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(100);
    nums.push_back(4);
    nums.push_back(200);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);

    Solution s;
    int res = s.longestConsecutive(nums);
    cout<<res<<endl;
    return 0;
}
