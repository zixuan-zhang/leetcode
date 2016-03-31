/*******************************************************************************
 *  @File  : 129_sum_root_to_leaf_numbers.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 31 Mar 2016 10:34:53 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 *
 */

class Solution {
public:
    void tranversal(TreeNode* root, int base, int& sum)
    {
        int cur = base * 10 + root->val;
        if (NULL == root->left && NULL == root->right)
            sum += cur;
        if (root->left)
            tranversal(root->left, cur, sum);
        if (root->right)
            tranversal(root->right, cur, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int base = 0;
        if (NULL == root)
            return sum;
        tranversal(root, base, sum);
        return sum;
    }
};
