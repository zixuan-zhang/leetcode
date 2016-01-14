/*******************************************************************************
 *  @File  : 104_maximum_depth_of_binary_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 14 Jan 2016 10:09:36 PM CST
 ******************************************************************************/

/*
 * Question:
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    void traversal(int step, TreeNode* node, int& deep)
    {
        if (node)
        {
            if (step > deep)
                deep = step;
            traversal(step+1, node->left, deep);
            traversal(step+1, node->right, deep);
        }
    }
    int maxDepth(TreeNode* root) {
        int deep = 0;
        traversal(1, root, deep);
        return deep;
    }
};

int main()
{
    return 0;
}
