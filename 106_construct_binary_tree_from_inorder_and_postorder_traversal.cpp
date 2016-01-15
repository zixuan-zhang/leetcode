/*******************************************************************************
 *  @File  : 106_construct_binary_tree_from_inorder_and_postorder_traversal.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 15 Jan 2016 09:41:29 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* build(vector<int>::iterator inBegin, vector<int>::iterator inEnd,
        vector<int>::iterator postBegin, vector<int>::iterator postEnd)
    {
        int rootVal = *postEnd;
        TreeNode* root = new TreeNode(rootVal);
        if (postBegin == postEnd)
            return root;
        vector<int>::iterator mid = find(inBegin, inEnd, rootVal);
        if (mid == inBegin)
            root->right = build(inBegin+1, inEnd, postBegin, postEnd-1);
        else if (mid == inEnd)
            root->left = build(inBegin, inEnd-1, postBegin, postEnd-1);
        else
        {
            int num = inEnd - mid;
            root->right = build(mid+1, inEnd, postEnd-num, postEnd-1);
            root->left = build(inBegin, mid-1, postBegin, postEnd-num-1);
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0)
            return NULL;
        return build(inorder.begin(), inorder.end()-1, postorder.begin(), postorder.end()-1);
    }
};

int main()
{
    return 0;
}
