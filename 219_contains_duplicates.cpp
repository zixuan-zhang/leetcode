/*******************************************************************************
 *  @File  : 219_contains_duplicates.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 31 Jul 2016 06:50:25 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * difference between i and j is at most k.
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int> > exist;
        for (int i = 0; i < nums.size(); ++i)
        {
            unordered_map<int, vector<int> >::iterator it = exist.find(nums[i]);
            if (it == exist.end())
                exist[nums[i]] = vector<int>();
            exist[nums[i]].push_back(i);
        }

        for (auto item : exist)
        {
            vector<int> indexes = item.second;
            sort(indexes.begin(), indexes.end());
            for (int i = 1; i < indexes.size(); ++i)
                if (indexes[i] - indexes[i-1] <= k)
                    return true;
        }
        return false;
    }

    bool containsNearbyDuplicate1(vector<int>& nums, int k)
    {
        if (nums.size() == 0)
            return false;
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i >= k)
                window.erase(nums[i-k-1]);
            if (window.count(nums[i]) > 0)
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    return 0;
}
