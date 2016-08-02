/*******************************************************************************
 *  @File  : 222_count_complete_tree_node.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 02 Aug 2016 09:52:06 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a complete binary tree, count the number of nodes.
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

class Solution
{
public:
    int countNodes(TreeNode* root) {
        if (NULL == root)
            return 0;
        int lCount = 0;
        int rCount = 0;
        for (TreeNode* node = root->left; node != NULL; node = node->left)
            lCount++;
        for (TreeNode* node = root->right; node != NULL; node = node->left)
            rCount++;
        if (lCount > rCount)
            return countNodes(root->left) + (1 << rCount);
        else
            return countNodes(root->right) + (1 << lCount);
    }
};

int main()
{
    return 0;
}
