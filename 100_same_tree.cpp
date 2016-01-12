/*******************************************************************************
 *  @File  : 100_same_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 12 Jan 2016 09:13:28 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical
 * and the nodes have the same value.
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
    bool equal(TreeNode* p, TreeNode* q)
    {
        if (NULL == p && NULL == q)
            return true;
        else if (NULL == p || NULL == q)
            return false;
        if (p->val == q->val)
            return equal(p->left, q->left) && equal(p->right, q->right);
        else
            return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return equal(p, q);
    }
};

int main()
{
    return 0;
}
