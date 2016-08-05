/*******************************************************************************
 *  @File  : 234_palindrome_linked_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 05 Aug 2016 08:34:13 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    bool _isPalidrome(ListNode* node, int step, int count, ListNode* &next)
    {
        if (step == (count+1) / 2)
        {
            if (count % 2 == 0)
            {
                next = node->next;
                if (node->val == next->val)
                {
                    next = next->next;
                    return true;
                }
                else
                    return false;
            }
            else
            {
                next = node->next;
                return true;
            }
        }
        bool subResult = _isPalidrome(node->next, step+1, count, next);
        if (!subResult)
            return false;
        if (node->val != next->val)
            return false;
        next = next->next;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        if (NULL == head || NULL == head->next)
            return true;
        int count = 0;
        ListNode* pointer = head;
        while (pointer)
        {
            count++;
            pointer = pointer->next;
        }
        pointer = NULL;
        return _isPalidrome(head, 1, count, pointer); 
    }

    // Another braliant method.
    bool isPalindrome1(ListNode* head)
    {
        if (NULL == head || NULL == head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (NULL != fast->next && NULL != fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse slow->next
        slow->next = reverse(slow->next);
        slow = slow->next;
        while (slow)
        {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* root)
    {
        if (NULL == root || NULL == root->next)
            return root;
        ListNode* head = root->next;
        ListNode* newHead = head->next;
        head->next = root;
        root->next = NULL;
        while (newHead)
        {
            ListNode* temp = newHead->next;
            newHead->next = head;
            head = newHead;
            newHead = temp;
        }
        return head;
    }
};

int main()
{
    return 0;
}
