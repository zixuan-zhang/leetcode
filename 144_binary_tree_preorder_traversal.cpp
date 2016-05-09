/*******************************************************************************
 *  @File  : 144_binary_tree_preorder_traversal.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Mon 09 May 2016 03:10:39 PM CST
 ******************************************************************************/

/* 
 * Question:
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> s;
        if (root)
            s.push(root);
        TreeNode* pointer = NULL;
        while (!s.empty())
        {
            pointer = s.top();
            s.pop();
            result.push_back(pointer->val);
            if (pointer->right)
                s.push(pointer->right);
            if (pointer->left)
                s.push(pointer->left);
        }
        return result;
    }

};

int main()
{
    return 0;
}
