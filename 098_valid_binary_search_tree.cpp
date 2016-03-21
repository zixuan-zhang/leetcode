/*******************************************************************************
 *  @File  : 098_valid_binary_search_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月21日 星期一 21时08分33秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
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
    bool isValid(TreeNode* root, int& leftVal, int& rightVal)
    {
        if (NULL == root->left && NULL == root->right)
        {
            leftVal = root->val;
            rightVal = root->val;
            return true;
        }
        leftVal = root->val;
        rightVal = root->val;
        int leftLeft, leftRight, rightLeft, rightRight;
        bool leftRes = true;
        bool rightRes = true;
        if (root->left)
        {
            if (root->val <= root->left->val)
                return false;
            else
            {
                leftRes = isValid(root->left, leftLeft, leftRight);
                if (!leftRes)
                    return false;
                if (root->val <= leftRight)
                    return false;
                leftVal = leftLeft;
            }
        }
        if (root->right)
        {
            if (root->val >= root->right->val)
                return false;
            else
            {
                rightRes = isValid(root->right, rightLeft, rightRight);
                if (!rightRes)
                    return false;
                if (root->val >= rightLeft)
                    return false;
                rightVal = rightRight;
            }
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (NULL == root)
            return true;
        int left, right;
        return isValid(root, left, right);
    }
};
