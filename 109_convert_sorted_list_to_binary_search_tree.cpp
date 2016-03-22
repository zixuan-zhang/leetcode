/*******************************************************************************
 *  @File  : 109_convert_sorted_list_to_binary_search_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月22日 星期二 17时01分50秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (NULL == head)
            return NULL;
        int len = 0;
        ListNode* ptr = head;
        while (ptr)
        {
            len++;
            ptr = ptr->next;
        }
        return construct(head, 0, len-1);
    }
    TreeNode* construct(ListNode*& head, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode* left = construct(head, start, mid-1);
        TreeNode* root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = construct(head, mid+1, end);
        return root;
    }
};
