/*******************************************************************************
 *  @File  : 114_flatte_binary_tree_to_linked_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 26 Jan 2016 09:19:58 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    void transition(TreeNode* node, TreeNode*& head, TreeNode*& tail)
    {
        TreeNode* leftHead = NULL;
        TreeNode* leftTail = NULL;
        TreeNode* rightHead = NULL;
        TreeNode* rightTail = NULL;
        if (NULL == node->left && NULL == node->right)
        {
            head = node;
            tail = node;
        }
        else if(NULL == node->left && NULL != node->right)
        {
            transition(node->right, rightHead, rightTail);
            head = node;
            tail = rightTail;
        }
        else if(NULL != node->left && NULL == node->right)
        {
            transition(node->left, leftHead, leftTail);
            node->left = NULL;
            node->right = leftHead;
            head = node;
            tail = leftTail;
        }
        else
        {
            transition(node->left, leftHead, leftTail);
            transition(node->right, rightHead, rightTail);
            node->left = NULL;
            node->right = leftHead;
            leftTail->right = rightHead;
            head = node;
            tail = rightTail;
        }
    }

    void flatten(TreeNode* root) {
        if (root)
        {
            TreeNode* head = NULL;
            TreeNode* tail = NULL;
            transition(root, head, tail);
        }
    }
};

int main()
{
    return 0;
}
