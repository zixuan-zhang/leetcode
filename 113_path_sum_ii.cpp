/*******************************************************************************
 *  @File  : 113_path_sum_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 26 Jan 2016 09:10:09 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *   [5,4,11,2],
 *   [5,8,4,5]
 * ]
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool has(TreeNode* node, int _sum, int sum)
    {
        if (NULL == node->left && NULL == node->right)
            return (_sum + node->val) == sum;
        bool result = false;
        if (node->left)
            result |= has(node->left, _sum+node->val, sum);
        if (node->right)
            result |= has(node->right, _sum+node->val, sum);
        return result;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (NULL == root)
            return false;
        if (NULL == root->left && NULL == root->right)
            return root->val == sum;
        bool result = false;
        if (root->left)
            result |= has(root->left, root->val, sum);
        if (root->right)
            result |= has(root->right, root->val, sum);
        return result;
    }
};

int main()
{
    return 0;
}
