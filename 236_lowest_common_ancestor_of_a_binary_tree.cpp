/*******************************************************************************
 *  @File  : 236_lowest_common_ancestor_of_a_binary_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 07 Aug 2016 03:29:33 PM CST
 ******************************************************************************/


#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* exist(TreeNode* node, TreeNode* p, TreeNode* q, bool& pExist, bool& qExist)
    {
        if (NULL == node)
        {
            pExist = false;
            qExist = false;
            return NULL;
        }
        if (node == p && node == q)
        {
            pExist = true;
            qExist = true;
            return node;
        }

        bool pLeftExist;
        bool qLeftExist;
        bool pRightExist;
        bool qRightExist;

        TreeNode* leftResult = exist(node->left, p, q, pLeftExist, qLeftExist);
        if (leftResult)
            return leftResult;
        TreeNode* rightResult = exist(node->right, p, q, pRightExist, qRightExist);
        if (rightResult)
            return rightResult;

        pExist = pLeftExist || pRightExist || node==p;
        qExist = qLeftExist || qRightExist || node==q;
        if (qExist && pExist)
            return node;
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool pExist, qExist;
        return exist(root, p, q, pExist, qExist);
    }
};

int main()
{
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);

    node3->left = node5;
    node3->right = node1;
    node5->left = node6;
    node5->right = node2;
    node2->left = node7;
    node2->right = node4;
    node1->left = node0;
    node1->right = node8;

    Solution s;
    TreeNode* result = s.lowestCommonAncestor(node3, node7, node8);
    cout<<result->val<<endl;

    return 0;
}
