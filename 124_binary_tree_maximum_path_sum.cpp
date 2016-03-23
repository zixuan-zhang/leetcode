/*******************************************************************************
 *  @File  : 124_binary_tree_maximum_path_sum.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月23日 星期三 08时58分46秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path does not need to go through the root.
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findMax(TreeNode* root, int& subMaxSum, int& maxSum)
    {
        if (NULL == root)
        {
            subMaxSum = INT_MIN;
            return;
        }
        int leftMax, rightMax;
        findMax(root->left, leftMax, maxSum);
        findMax(root->right, rightMax, maxSum);
        
        if (leftMax == INT_MIN && rightMax == INT_MIN)
        {
            maxSum = max(maxSum, root->val);
            subMaxSum = root->val;
        }
        else if (leftMax == INT_MIN)
        {
            maxSum = max(maxSum, rightMax+root->val);
            maxSum = max(maxSum, root->val);
            
            subMaxSum = max(root->val, root->val+rightMax);
        }
        else if (rightMax == INT_MIN)
        {
            maxSum = max(maxSum, leftMax+root->val);
            maxSum = max(maxSum, root->val);
            subMaxSum = max(root->val, root->val+leftMax);
        }
        else
        {
            maxSum = max(maxSum, root->val);
            maxSum = max(maxSum, leftMax+root->val);
            maxSum = max(maxSum, rightMax+root->val);
            maxSum = max(maxSum, leftMax+rightMax+root->val);
            
            subMaxSum = max(root->val, max(leftMax,rightMax)+root->val);
        }
    }

    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        int subMaxSum;
        findMax(root, subMaxSum, maxSum);
        return maxSum;
    }
};
