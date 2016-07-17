/*******************************************************************************
 *  @File  : remove_linked_list_elements.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 17 Jul 2016 10:34:56 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        if (NULL == head)
            return NULL;
        ListNode* pointer = head;
        while (pointer && pointer->val == val)
            pointer = pointer->next;
        if (pointer == NULL)
            return NULL;
        head = pointer;
        ListNode* pre = head;
        pointer = head->next;
        while (pointer)
        {
            if (pointer->val == val)
            {
                pre->next = pointer->next;
            }
            else
                pre = pointer;
            pointer = pointer->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}
