/*******************************************************************************
 *  @File  : 025_reverse_nodes_in_k_group.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月28日 星期三 08时54分26秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return
 * its modified list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is. You may not alter the values in the
 * nodes, only nodes itself may be changed. Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 *
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution
{
public:
    bool hasEnough(ListNode* head, int k)
    {
        int cnt = 0;
        ListNode* pointer = head;
        while (pointer)
        {
            cnt ++;
            pointer = pointer->next;
            if (cnt >= k)
                return true;
        }
        return false;
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (NULL == head || k <= 1)
            return head;
        if (!hasEnough(head, k))
            return head;
        //if list contain only one node
        int step = 1;
        ListNode* tail = head;
        ListNode* pointer = head->next;
        ListNode* groupHead = head;
        ListNode* cur = NULL;
        ListNode* tailTemp = NULL;
        while (pointer)
        {
            cur = pointer;
            pointer = cur->next;
            cur->next = groupHead;
            if (groupHead == head)
                groupHead->next = NULL;
            groupHead = cur;
            step ++;
            if (step == k)
                break;
        }
        head = groupHead;
        if (NULL == pointer) //if ends at this
        {
            tail->next = pointer;
            return head;
        }

        while (pointer)
        {
            if (!hasEnough(pointer, k))
            {
                tail->next = pointer;
                return head;
            }
            groupHead = pointer;
            tailTemp = pointer;
            pointer = groupHead->next;
            step = 1;
            while (pointer)
            {
                cur = pointer;
                pointer = cur->next;
                cur->next = groupHead;
                groupHead = cur;
                step ++;
                if (step == k)
                    break;
            }
            tail->next = groupHead; //till now
            tail = tailTemp;
        }
        tail->next = NULL;

        return head;
    }
};

int main()
{
    ListNode* head1 = new ListNode(1);
    ListNode* tail  = head1;
    for (int i = 2; i <=5; i++)
    {
        ListNode* temp = new ListNode(i);
        tail->next = temp;
        tail = temp;
    }
    Solution s;
    ListNode* newHead = s.reverseKGroup(head1, 3);

    ListNode* pointer = newHead;
    while (pointer)
    {
        cout<<pointer->val<<" ";
        pointer = pointer->next;
    }
    cout<<endl;

    return 0;
}
