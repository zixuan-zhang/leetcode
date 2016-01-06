/*******************************************************************************
 *  @File  : 083_remove_duplicates_from_sorted_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Wed 06 Jan 2016 01:27:17 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tail = head;
        ListNode* next;
        while (tail)
        {
            next = tail->next;
            while (next && next->val == tail->val)
                next = next->next;
            tail->next = next;
            tail = next;
        }
        return head;
    }
};

int main()
{
    return 0;
}
