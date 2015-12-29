/*******************************************************************************
 *  @File  : 061_rotate_list.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月29日 星期二 20时41分26秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 *
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:

    /*
     * 使用的方法比较简单粗暴。就是将链表向右移一下。然后移k次。
     *
     */
    ListNode* rotateRight(ListNode* head, int k) {
        if (NULL == head || NULL == head->next)
            return head;
        ListNode* p = head;
        int count = 0;
        while (p)
        {
            count += 1;
            p = p->next;
        }
        k = k % count;
        for (int i = 0; i < k; ++i)
        {
            ListNode* p = head->next;
            int pre = head->val;
            int temp;
            while (p)
            {
                temp = p->val;
                p->val = pre;
                pre = temp;
                p = p->next;
            }
            head->val = pre;
        }
        return head;
    }
};

int main()
{
    return 0;
}
