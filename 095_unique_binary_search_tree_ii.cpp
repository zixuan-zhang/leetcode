/*******************************************************************************
 *  @File  : 095_unique_binary_search_tree_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月20日 星期日 20时59分29秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generate(vector<int> nums, vector<int>::iterator begin,
            vector<int>::iterator end)
    {
        vector<TreeNode*> result;
        if (begin > end)
        {
            result.push_back(NULL);
            return result;
        }
        if (begin == end)
        {
            result.push_back(new TreeNode(*begin));
            return result;
        }
        for (vector<int>::iterator it = begin; it <= end; ++it)
        {
            vector<TreeNode*> leftVec = generate(nums, begin, it-1);
            vector<TreeNode*> rightVec = generate(nums, it+1, end);
            for (int i = 0; i < leftVec.size(); ++i)
            {
                for (int j = 0; j < rightVec.size(); ++j)
                {
                    TreeNode* root = new TreeNode(*it);
                    root->left = leftVec[i];
                    root->right = rightVec[j];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if (n < 1)
            return result;

        // initialize
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            nums[i] = i+1;
        result = generate(nums, nums.begin(), nums.end()-1);
        return result;
    }
};
