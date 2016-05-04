/*******************************************************************************
 *  @File  : 147_insertion_sort_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Wed 04 May 2016 07:30:00 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Sort a linked list using insertion sort.
 *
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};

class Solution
{
public:
    ListNode* insertionSortList(ListNode* head)
    {
        if (NULL == head)
            return head;
        ListNode* pointer = head->next;
        ListNode* newHead = head;
        newHead->next = NULL;
        while (pointer)
        {
            ListNode* temp = pointer;
            pointer = pointer->next;
            ListNode* prePointer = newHead;
            ListNode* curPointer = newHead;
            while (curPointer && curPointer->val < temp->val)
            {
                prePointer = curPointer;
                curPointer = curPointer->next;
            }
            if (curPointer == newHead)
            {
                temp->next = newHead;
                newHead = temp;
            }
            else if (curPointer== NULL)
            {
                prePointer->next = temp;
                temp->next = NULL;
            }
            else
            {
                prePointer->next = temp;
                temp->next = curPointer;
            }
        }
        return newHead;
    }
};


int main()
{

    ListNode* tail = NULL;
    ListNode* head = NULL;

    int array[] = {3,1,6,9,5,4,9,7,3,8,10,1,0,3,4,6,11,2};
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
    {
        ListNode* node = new ListNode(array[i]);
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    //ListNode* node1 = new ListNode(3);
    //ListNode* node2 = new ListNode(1);
    //ListNode* node3 = new ListNode(6);
    //ListNode* node4 = new ListNode(9);
    //ListNode* node5 = new ListNode(5);
    //ListNode* node6 = new ListNode(1);

    //node1->next = node2;
    //node2->next = node3;
    //node3->next = node4;
    //node4->next = node5;
    //node5->next = node6;

    Solution s;
    ListNode* newNode = s.insertionSortList(head);
    while (newNode)
    {
        cout<<newNode->val<<" ";
        newNode = newNode->next;
    }
    cout<<endl;

    return 0;
}
