/*******************************************************************************
 *  @File  : 092_reverse_linked_list_II.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 10 Jan 2016 09:47:53 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode* tail = NULL;
        int count = 1;
        ListNode* p = head;
        ListNode* pre = head;
        while (count++ < m)
        {
            pre = p;
            p = p->next;
        }
        tail = p;

        ListNode* cur = tail->next;
        ListNode* next;
        ListNode* newHeader = tail;        

        while (count++ < n)
        {
            next = cur->next;
            cur->next = newHeader;
            newHeader = cur;
            cur = next;
        }
        next = cur->next;
        cur->next = newHeader;
        tail->next = next;

        if (p == head)
            return cur;
        else
        {
            pre->next = cur;
            return head;
        }
};

int main()
{
    return 0;
}
