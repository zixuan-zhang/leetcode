/*******************************************************************************
 *  @File  : 349_intersection_of_two_arrays.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 29 May 2016 09:34:31 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> valueSet(nums1.begin(), nums1.end());
        vector<int> result;
        for (auto value : nums2)
        {
            if (valueSet.find(value) != valueSet.end())
            {
                valueSet.erase(value);
                result.push_back(value);
            }
        }
        return result;
    }

};

int main()
{
    int array1[] = {1, 2, 2, 1, 3};
    int array2[] = {2, 2, 3};
    vector<int> nums1;
    vector<int> nums2;
    for (auto num : array1)
        nums1.push_back(num);
    for (auto num : array2)
        nums2.push_back(num);

    Solution s;
    vector<int> result = s.intersection(nums1, nums2);
    for (auto value : result)
        cout<<value<<" ";
    cout<<endl;
    return 0;
}
