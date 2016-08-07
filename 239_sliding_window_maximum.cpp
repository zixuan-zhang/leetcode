/*******************************************************************************
 *  @File  : 239_sliding_window_maximum.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 07 Aug 2016 02:47:00 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one position.
 *
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *
 * Window position                Max
 * ---------------               -----
 *  [1  3  -1] -3  5  3  6  7       3
 *   1 [3  -1  -3] 5  3  6  7       3
 *   1  3 [-1  -3  5] 3  6  7       5
 *   1  3  -1 [-3  5  3] 6  7       5
 *   1  3  -1  -3 [5  3  6] 7       6
 *   1  3  -1  -3  5 [3  6  7]      7
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 *
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return vector<int>();
        deque<int> queue;
        vector<int> result(nums.size() - k + 1);
        for (int i = 0; i < k; ++i)
        {
            if (queue.empty())
                queue.push_back(nums[i]);
            else
            {
                while (!queue.empty() && queue.back() < nums[i])
                    queue.pop_back();
                queue.push_back(nums[i]);
            }
        }
        result[0] = queue.front();
        for (int i = k; i < nums.size(); ++i)
        {
            while (!queue.empty() && queue.back() < nums[i])
                queue.pop_back();
            queue.push_back(nums[i]);
            if (queue.front() == nums[i-k])
                queue.pop_front();
            result[i-k+1] = queue.front();
        }

        return result;
    }
};

int main()
{
    int array[] = {1};
    vector<int> nums;
    for (auto num : array)
        nums.push_back(num);

    Solution s;
    vector<int> result = s.maxSlidingWindow(nums, 1);
    for (auto num : result)
        cout<<num<<endl;

    return 0;
}
