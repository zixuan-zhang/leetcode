/*******************************************************************************
 *  @File  : 101_symmetric_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 12 Jan 2016 09:56:26 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *     3   3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * 用递归的方式
     */
    bool comp(TreeNode* left, TreeNode* right)
    {
        if (NULL == left && NULL == right)
            return true;
        if (NULL == left || NULL == right)
            return false;
        if (left->val != right->val)
            return false;
        return comp(left->left, right->right) && comp(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (NULL == root)
            return true;
        return comp(root->left, root->right);
    }
};

int main()
{
    return 0;
}
