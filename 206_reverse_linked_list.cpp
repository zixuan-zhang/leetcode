/*******************************************************************************
 *  @File  : 206_reverse_linked_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 22 Jul 2016 10:05:54 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Reverse a singly linked list.
 *
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if (NULL == head || NULL == head->next)
            return head;
        ListNode* newHead = head;
        head = head->next;
        newHead->next = NULL;
        while (head)
        {
            ListNode* temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }

};

int main()
{

}

