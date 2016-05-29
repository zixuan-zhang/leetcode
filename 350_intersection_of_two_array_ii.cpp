/*******************************************************************************
 *  @File  : 350_intersection_of_two_array_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 29 May 2016 04:39:55 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 * Follow up:
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to num2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    
    /*
     * Regular method.
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> counts;
        vector<int> result;
        for (auto value : nums1)
        {
            if (counts.find(value) != counts.end())
                counts[value]++;
            else
                counts[value] = 1;
        }

        for (auto value : nums2)
        {
            if (counts.find(value) != counts.end() && counts[value] >= 1)
            {
                result.push_back(value);
                counts[value]--;
            }
        }
        return result;
    }

    /*
     * If the given array is already sorted.
     */
    vector<int> intersectForSorted(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        int left = 0;
        int right = 0;
        while (left < nums1.size() && right < nums2.size())
        {
            if (nums1[left] == nums2[right])
            {
                result.push_back(nums1[left]);
                left++;
                right++;
            }
            else if (nums1[left] < nums2[right])
                left++;
            else if (nums1[left] > nums2[right])
                right++;
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
    vector<int> result = s.intersect(nums1, nums2);
    for (auto value : result)
        cout<<value<<" ";
    cout<<endl;
    return 0;
}
