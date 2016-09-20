/*******************************************************************************
 *  @File  : 337_house_robber_iii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 20 Sep 2016 07:42:50 PM CST
 ******************************************************************************/

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL){}
}

class Solution {
public:
    pair<int, int> maxOfTree(TreeNode* root)
    {
        if (root == NULL)
            return make_pair(0, 0);
        pair<int, int> left = make_pair(0, 0);
        pair<int, int> right = make_pair(0, 0);
        if (root->left)
            left = maxOfTree(root->left);
        if (root->right)
            right = maxOfTree(root->right);
        return make_pair(max(left.first, left.second) + max(right.first, right.second), left.first + right.first + root->val);
    }
    int rob(TreeNode* root) {
        pair<int, int> value = maxOfTree(root);
        return max(value.first, value.second);
    }
};
