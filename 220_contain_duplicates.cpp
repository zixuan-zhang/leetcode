/*******************************************************************************
 *  @File  : 220_contain_duplicates.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 31 Jul 2016 09:06:07 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the difference between nums[i] and nums[j]
 * is at most t and the difference between i and j is at most k.
 *
 */

#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;


class Solution
{
public:

    // bucket solution, brilliant
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0 || k < 1 || t < 0)
            return false;
        unordered_map<long ,long> bucket;
        for (int i = 0; i < nums.size(); ++i)
        {
            long newNumber = (long)nums[i] - INT_MIN;
            long bucketId = newNumber / ((long)t + 1);
            if (bucket.count(bucketId) > 0 ||
                    (bucket.count(bucketId-1) > 0 && newNumber - bucket[bucketId-1] <= t) ||
                    (bucket.count(bucketId+1) > 0 && bucket[bucketId+1] - newNumber <= t) )
                return true;
            bucket[bucketId] = newNumber;
            if (bucket.size() > k)
                bucket.erase(((long)nums[i-k]-INT_MIN) / ((long)t+1));
        }
        return false;
    }

};

int main()
{
    return 0;
}
