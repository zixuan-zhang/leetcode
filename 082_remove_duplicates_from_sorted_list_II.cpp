/*******************************************************************************
 *  @File  : 082_remove_duplicates_from_sorted_list_II.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Wed 06 Jan 2016 12:10:20 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 *
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};
class Solution {
public:
    ListNode* firstSingleNode(ListNode* head)
    {
        if (NULL == head || NULL == head->next)
            return head;
        ListNode* newHead = head;
        ListNode* next;
        while (newHead)
        {
            next = newHead->next;
            if (NULL == next || newHead->val != next->val)
                return newHead;
            while (next && next->val == newHead->val)
                next = next->next;
            newHead = next;
        }
        
        return newHead;
    }
                
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = firstSingleNode(head);
        if (NULL == newHead)
            return newHead;
        ListNode* tail = newHead;
        ListNode* nextHead;
        ListNode* nextSingle;
        while (tail)
        {
            nextHead = tail->next;
            nextSingle = firstSingleNode(nextHead);
            tail->next = nextSingle;
            tail = nextSingle;
        }
        return newHead;
    }
}; 
int main()
{
    ListNode* n6 = new ListNode(5);
    ListNode* n5 = new ListNode(4, n6);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(3, n3);
    ListNode* n1 = new ListNode(2, n2);
    ListNode* head = new ListNode(1, n1);

    Solution s;
    ListNode* newHead = s.deleteDuplicates(head);
    while (newHead)
    {
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    cout<<endl;

    return 0;
}
