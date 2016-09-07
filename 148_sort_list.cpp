/*******************************************************************************
 *  @File  : 148_sort_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Wed 07 Sep 2016 10:50:23 PM CST
 ******************************************************************************/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL){}
};

class Solution {
public:
    ListNode* mergeSort(ListNode* begin, ListNode* end)
    {
        if (begin == end)
        {
            begin->next = NULL;
            return begin;
        }
        
        ListNode* slow = begin;
        ListNode* fast = begin;
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        ListNode* head1 = mergeSort(begin, slow);
        head2 = mergeSort(head2, end);
        ListNode* newHead;
        ListNode* tail;
        if (head1->val < head2->val)
        {
            newHead = head1;
            head1 = head1->next;
        }
        else
        {
            newHead = head2;
            head2 = head2->next;
        }
        tail = newHead;
        while (head1 && head2)
        {
            if (head1->val < head2->val)
            {
                tail->next = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        if (head1)
            tail->next = head1;
        if (head2)
            tail->next = head2;
        return newHead;
    }
        
    ListNode* sortList(ListNode* head) {
        if (NULL == head || NULL == head->next)
            return head;
        ListNode* tail = head;
        while (tail->next)
            tail = tail->next;
        return mergeSort(head, tail);
    }
};

int main()
{
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(1);
    node1->next = node2;
    ListNode* head = node1;

    while (head)
    {
        cout<<head->val<<endl;
        head = head->next;
    }

    Solution s;
    head = s.sortList(node1);

    while (head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }

    return 0;
}

