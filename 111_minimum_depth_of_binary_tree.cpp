/*******************************************************************************
 *  @File  : 111_minimum_depth_of_binary_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月21日 星期一 21时12分41秒
 ******************************************************************************/


/*
 * Question:
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (NULL == root)
            return 0;
        if (NULL == root->left && NULL == root->right)
            return 1;
        int left = INT_MAX;
        int right = INT_MAX;
        if (root->left)
            left = minDepth(root->left);
        if (root->right)
            right = minDepth(root->right);
        return left < right ? left+1 : right+1;
    }
};
