/*******************************************************************************
 *  @File  : 199_binary_tree_right_side_view.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 16 Jul 2016 05:42:30 PM CST
 ******************************************************************************/

/*
 * Question:
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *
 *    1            <---
 *   /   \
 *  2     3         <---
 *   \     \
 *    5     4       <---
 *
 * You should return [1, 3, 4].
 *
 */

#include <iostream>
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
    void tranverse(TreeNode* root, vector<int>& result, int level)
    {
        if (NULL == root)
            return ;
        if (result.size() == level)
            result.push_back(root->val);
        tranverse(root->right, result, level+1);
        tranverse(root->left, result, level+1);
    }

};


int main()
{
    return 0;
}
