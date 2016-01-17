/*******************************************************************************
 *  @File  : 107_binary_tree_level_order_traversal_II.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 17 Jan 2016 04:24:19 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        traversal(1, root, result);
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{
    return 0;
}
