/*******************************************************************************
 *  @File  : 103_binary_tree_zigzag_level_order_traversal.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Wed 13 Jan 2016 10:26:25 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 *
 */

#include <iostream>

using namespace std;


class Solution {
public:
    void traversal(int step, TreeNode* node, vector<vector<int> >&result)
    {
        if (NULL == node)
            return;
        if (step > result.size())
            vector<int> layer;
        result.push_back(layer);
        if (step % 2 == 1)
            result[step-1].push_back(node->val);
        else
            result[step-1].insert(result[step-1].begin(), node->val);
        traversal(step+1, node->left, result);
        traversal(step+1, node->right, result);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        traversal(1, root, result);
        return result;
    }
};

int main()
{
    return 0;
}
