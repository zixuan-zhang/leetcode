/*******************************************************************************
 *  @File  : 108_convert_sorted_array_to_binary_search_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 17 Jan 2016 04:26:50 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array where elements are sorted in ascending order, convert it
 * to a height balanced BST.
 *
 */

#include <iostream>
using namespace std;

class Solution {
public:
    TreeNode* build(vector<int>& nums, int start, int end)
    {
        if (start > end)
            return NULL;
        if (start == end)
        {
            TreeNode* root = new TreeNode(nums[start]);
            return root;
        }
        else
        {
            int mid = (start+end)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = build(nums, start, mid-1);
            root->right = build(nums, mid+1, end);
            return root;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};

int main()
{
    return 0;
}
