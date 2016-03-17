/*******************************************************************************
 *  @File  : 328_odd_even_linked_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月17日 星期四 10时01分42秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 *
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 *
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input. 
 * The first node is considered odd, the second node even and so on ...
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (NULL == head || NULL == head->next)
            return head;

        ListNode* oddHead = head;
        ListNode* oddTail = oddHead;
        ListNode* evenHead = head->next;
        ListNode* evenTail = evenHead;
        ListNode* pointer = evenHead->next;
        
        int number = 0;
        while (pointer)
        {
            if (number % 2 == 0)
            {
                oddTail->next = pointer;
                oddTail = pointer;
            }
            else
            {
                evenTail->next = pointer;
                evenTail = pointer;
            }
            number++;
            pointer = pointer->next;
        }
        oddTail->next = evenHead;
        evenTail->next = NULL;
        return head;
    }
};
