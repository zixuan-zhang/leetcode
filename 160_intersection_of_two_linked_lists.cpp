/*******************************************************************************
 *  @File  : intersection_of_two_linked_lists.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 07 Jul 2016 09:23:55 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (NULL == headA || NULL == headB)
            return NULL;
        int len1 = 0;
        int len2 = 0;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1)
        {
            len1++;
            p1 = p1->next;
        }
        while (p2)
        {
            len2++;
            p2 = p2->next;
        }
        p1 = headA;
        p2 = headB;
        if (len1 > len2)
        {
            int count = len1 - len2;
            while (count > 0)
            {
                p1 = p1->next;
                count--;
            }
        }
        if (len2 > len1)
        {
            int count = len2 - len1;
            while (count > 0)
            {
                p2 = p2->next;
                count--;
            }
        }

        while (p1 && p2)
        {
            if (p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        return NULL;
    }
};

void test()
{
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* c1 = new ListNode(3);
    ListNode* c2 = new ListNode(4);
    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(7);

    c1->next = c2;
    a2->next = c1;
    a1->next = a2;
    b3->next = c1;
    b2->next = b3;
    b1->next = b2;

    Solution s;
    ListNode* result = s.getIntersectionNode(a1, b1);
    if (result)
        cout<<result->val<<endl;
    else
        cout<<"None"<<endl;
}

int main()
{
    test();
    return 0;
}
