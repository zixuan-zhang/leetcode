/*******************************************************************************
 *  @File  : 086_partition_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Wed 13 Jan 2016 09:56:54 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of
 * the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 *
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* littleHead = NULL;
        ListNode* littleTail = NULL;
        ListNode* bigHead = NULL;
        ListNode* bigTail = NULL;
        ListNode* pointer = head;
        ListNode* pre = NULL;
        while (pointer)
        {
            if (pointer->val < x)
            {
                if (NULL == littleHead)
                {
                    littleHead = pointer;
                    littleTail = pointer;
                }
                else
                {
                    littleTail->next = pointer;
                    littleTail = pointer;
                }
            }
            else
            {
                if (NULL == bigHead)
                {
                    bigHead = pointer;
                    bigTail = pointer;
                }
                else
                {
                    bigTail->next = pointer;
                    bigTail = pointer;
                }
            }
            pre = pointer;
            pointer = pointer->next;
            pre->next = NULL;
        }
        if (littleTail)
        {
            littleTail->next = bigHead;
            return littleHead;
        }
        else
            return bigHead;
    }
};
int main()
{
    return 0;
}
