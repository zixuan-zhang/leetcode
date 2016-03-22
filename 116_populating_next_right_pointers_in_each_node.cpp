/*******************************************************************************
 *  @File  : 116_populating_next_right_pointers_in_each_node.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月22日 星期二 20时30分23秒
 ******************************************************************************/

/*
 * Question:
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the
 * same level, and every parent has two children).
 *
 */

#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void construct(TreeLinkNode* root)
    {
        if (NULL == root)
            return;
        construct(root->left);
        construct(root->right);
        TreeLinkNode* left = root->left;
        TreeLinkNode* right = root->right;
        while (left)
        {
            left->next = right;
            left = left->right;
            right = right->left;
        }
    }
    
    void connect(TreeLinkNode *root) {
        if (NULL == root)
            return;
        construct(root);
    }
};

int main()
{
    return 0;
}
