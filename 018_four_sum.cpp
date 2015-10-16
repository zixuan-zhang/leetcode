/*******************************************************************************
 *  @File  : 018_four_sum.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月16日 星期五 15时22分01秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 * A solution set is:
 *      (-1,  0, 0, 1)
 *      (-2, -1, 1, 2)
 *      (-2,  0, 0, 2)
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    /*
     * This is a O(n^3) solution
     *
     */
    vector<vector<int> > fourSum(vector<int>& nums, int target)
    {
        vector<vector<int> > result;
        vector<int> group(4, 0);
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while (i < nums.size())
        {
            j = i + 1;
            while (j < nums.size())
            {
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    int temp = nums[i] + nums[j] + nums[left] + nums[right];
                    if (temp == target)
                    {
                        group[0] = nums[i];
                        group[1] = nums[j];
                        group[2] = nums[left];
                        group[3] = nums[right];
                        result.push_back(group);
                        while (++left < right && nums[left] == nums[left-1]);
                        while (left < --right && nums[right] == nums[right+1]);
                    }
                    else if (temp < target)
                        while (++left < right && nums[left] == nums[left-1]);
                    else
                        while (left < --right && nums[right] == nums[right+1]);
                }
                while (++j < nums.size() && nums[j] == nums[j-1]);
            }
            while (++i < nums.size() && nums[i] == nums[i-1]);
        }
        return result;
    }

    /*
     * Another solution:
     *  You can save every pair of (a + b, (a, b)) into hash_map
     * Then for any pair (nums[i], nums[j]), check if target-nums[i]-nums[j]
     * exists in hash_map.
     * This is a O(n^2) solution
     *
     */
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);

    vector<vector<int> > result = s.fourSum(nums, 0);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
