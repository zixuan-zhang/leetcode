/*******************************************************************************
 *  @File  : 145_binary_tree_postorder_traversal.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Mon 09 May 2016 03:16:28 PM CST
 ******************************************************************************/


/*
 * Question:
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
    vector<int> postorderTraversal(TreeNode* root)
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
            if (pointer->left)
                s.push(pointer->left);
            if (pointer->right)
                s.push(pointer->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    return 0;
}

