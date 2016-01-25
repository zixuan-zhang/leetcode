/*******************************************************************************
 *  @File  : 112_path_sum.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Mon 25 Jan 2016 09:56:40 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *          11  13  4
 *         /  \      \
 *        7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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



int main()
{
    return 0;
}
