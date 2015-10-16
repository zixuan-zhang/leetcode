/*******************************************************************************
 *  @File  : 021_merge_two_sorted_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月16日 星期五 19时07分15秒
 ******************************************************************************/

/*
 * Question:
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (NULL == l1)
            return l2;
        if (NULL == l2)
            return l1;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        if (l1->val < l2->val)
        {
            head = l1;
            tail = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            tail = l2;
            l2 = l2->next;
        }
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        if (l1)
            tail->next = l1;
        if (l2)
            tail->next = l2;
        return head;
    }
};

int main()
{
    ListNode* head1 = new ListNode(1);
    ListNode* tail  = head1;
    for (int i = 3; i <10; i = i+2)
    {
        ListNode* temp = new ListNode(i);
        tail->next = temp;
        tail = temp;
    }
    ListNode* head2 = new ListNode(2);
    tail = head2;
    for (int i = 4; i < 10; i = i+2)
    {
        ListNode* temp = new ListNode(i);
        tail->next = temp;
        tail = temp;
    }

    ListNode* pointer = head1;
    while (pointer)
    {
        cout<<pointer->val<<" ";
        pointer = pointer->next;
    }
    cout<<endl;

    pointer = head2;
    while (pointer)
    {
        cout<<pointer->val<<" ";
        pointer = pointer->next;
    }
    cout<<endl;

    Solution s;
    pointer = s.mergeTwoLists(head1, head2);
    while (pointer)
    {
        cout<<pointer->val<<" ";
        pointer = pointer->next;
    }
    cout<<endl;

    return 0;
}
