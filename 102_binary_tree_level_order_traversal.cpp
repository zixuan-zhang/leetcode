/*******************************************************************************
 *  @File  : 102_binary_tree_level_order_traversal.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Wed 13 Jan 2016 10:20:58 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    void traversal(int step, TreeNode* node, vector<vector<int> >& result)
    {
        if (NULL == node)
            return;
        if (step > result.size())
        {
            vector<int> level;
            result.push_back(level);
        }
        result[step-1].push_back(node->val);
        traversal(step+1, node->left, result);
        traversal(step+1, node->right, result);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        traversal(1, root, result);
        return result;
    }
};

int main()
{
    return 0;
}
