/*******************************************************************************
 *  @File  : 019_remove_nth_node_from_end_of_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月16日 星期五 16时05分07秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *       After removing the second node from the end, the linked list becomes 1->2->3->5.
 *       Note:
 *       Given n will always be valid.
 *       Try to do this in one pass.
 *
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){};
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (NULL == head || 0 == n)
            return head;
        ListNode* pointer = head;
        ListNode* tail = head;
        ListNode* pre = head;
        int cnt = 0;

        while (pointer != NULL)
        {
            if (cnt >= n)
            {
                pre = tail;
                tail = tail->next;
            }
            pointer = pointer->next;
            cnt ++;
        }
        if (cnt == n)
            return head->next;
        else if (cnt > n)
        {
            pre->next = tail->next;
            delete tail;
        }
        return head;
    }
};

int main()
{
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 1; i <=5; ++i)
    {
        if (NULL == head)
        {
            head = new ListNode(i);
            tail = head;
        }
        else
        {
            ListNode* temp = new ListNode(i);
            tail->next = temp;
            tail = temp;
        }
    }

    Solution s;
    head = s.removeNthFromEnd(head, 7);

    ListNode* pointer = head;
    while (pointer)
    {
        cout<<pointer->val<<" ";
        pointer = pointer->next;
    }

    return 0;
}
