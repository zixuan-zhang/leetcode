/*******************************************************************************
 *  @File  : 099_recover_binary_search_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月21日 星期一 21时11分32秒
 ******************************************************************************/

/*
 * Question:
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a
 * constant space solution?
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
    void inorder(TreeNode* root, vector<int>& vec)
    {
        if (NULL == root)
            return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }

    void findOne(TreeNode* root, TreeNode* & node, int val)
    {
        if (root->val == val)
        {
            node = root;
            return;
        }
        if (NULL == node && root->left)
            findOne(root->left, node, val);
        if (NULL == node && root->right)
            findOne(root->right, node, val);
    }
    void recoverTree(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);

        int left= 0, right=vec.size()-1;
        while (left+1 < vec.size() && vec[left] < vec[left+1])
            left++;
        while (right-1 >= 0 && vec[right] > vec[right-1])
            right--;
        int leftVal = vec[left];
        int rightVal = vec[right];

        TreeNode* leftNode = NULL;
        TreeNode* rightNode = NULL;
        findOne(root, leftNode, leftVal);
        findOne(root, rightNode, rightVal);

        int temp = leftNode->val;
        leftNode->val = rightNode->val;
        rightNode->val = temp;
    }
};
