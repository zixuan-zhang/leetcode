/*******************************************************************************
 *  @File  : 094_binary_tree_inorder_traversal.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 10 Jan 2016 09:12:30 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2].
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void order(TreeNode* node, vector<int>& result)
    {
        if (NULL == node)
            return;
        order(node->left, result);
        result.push_back(node->val);
        order(node->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        order(root, result);
        return result;
    }
};

int main()
{
    return 0;
}
