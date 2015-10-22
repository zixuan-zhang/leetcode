/*******************************************************************************
 *  @File  : 024_swap_nodes_in_pairs.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月22日 星期四 18时53分27秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
 *
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL){}
};

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (NULL == head || NULL == head->next) //如果没有节点或只有一个节点
            return head;
        ListNode* pre = head;
        ListNode* first = head;
        ListNode* second = NULL;

        while (first)
        {
            second = first->next;
            if (NULL == second)
                break;
            if (head == first)
            {
                first->next = second->next;
                second->next = first;
                head = second;
            }
            else
            {
                first->next = second->next;
                second->next = first;
                pre->next = second;
            }
            pre = first;
            first = first->next;
        }
        return head;
    }
};

int main()
{
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 1; i <=6; ++i)
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
    head = s.swapPairs(head);

    ListNode* pointer = head;
    while (pointer)
    {
        cout<<pointer->val<<" ";
        pointer = pointer->next;
    }
    return 0;
}
