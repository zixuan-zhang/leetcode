/*******************************************************************************
 *  @File  : 105_construct_binary_tree_from_preorder_and_inorder_traversal.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 14 Jan 2016 10:12:11 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* build(vector<int>::iterator preBegin, vector<int>::iterator preEnd,
        vector<int>::iterator inBegin, vector<int>::iterator inEnd)
    {
        int rootVal = *preBegin;
        TreeNode* root = new TreeNode(rootVal);
        if (preBegin == preEnd)
            return root;
        vector<int>::iterator mid = find(inBegin, inEnd, rootVal);
        if (mid == inBegin)
        {
            root->right = build(preBegin+1, preEnd, inBegin+1, inEnd);
        }
        else if (mid == inEnd)
        {
            root->left = build(preBegin+1, preEnd, inBegin, inEnd-1);
        }
        else
        {
            int num = mid - inBegin;
            root->left = build(preBegin+1, preBegin+num, inBegin, mid-1);
            root->right = build(preBegin+num+1, preEnd, mid+1, inEnd);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        return build(preorder.begin(), preorder.end()-1, inorder.begin(), inorder.end()-1);
    }
};

int main()
{
    return 0;
}
