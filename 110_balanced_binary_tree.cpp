/*******************************************************************************
 *  @File  : 110_balanced_binary_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月22日 星期二 09时00分54秒
 ******************************************************************************/

/*
 * Question:
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more than 1.
 *
 */

class Solution {
public:
    bool get_path(TreeNode* root, int& _min, int& _max)
    {
        if (NULL == root)
        {
            _min = 0;
            _max = 0;
            return true;
        }
        int leftMin, leftMax;
        int rightMin, rightMax;
        bool left = get_path(root->left, leftMin, leftMax);
        bool right = get_path(root->right, rightMin, rightMax);
        if (!(left && right))
            return false;
        if (max(leftMax,rightMax) - min(leftMax, rightMax) > 1)
            return false;
        _min = max(leftMax, rightMax) + 1;
        _max = max(leftMax, rightMax) + 1;
        return true;
    }

    /*
     * The key of the problem is that the defination of depth.
     * The depth of a tree is the max node number from that node to leaves.
     */
    bool isBalanced(TreeNode* root) {
        int _min, _max;
        bool res =  get_path(root, _min, _max);
        if (!res)
            return false;
        return (_max-_min) > 1 ? false : true;
    }
};
