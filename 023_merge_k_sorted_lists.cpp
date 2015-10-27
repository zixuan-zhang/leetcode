/*******************************************************************************
 *  @File  : 023_merge_k_sorted_lists.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月27日 星期二 10时38分14秒
 ******************************************************************************/

/*
 * Question:
 *
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (0 == lists.size())
            return NULL;
        vector<int> temp;
        ListNode* pointer = NULL;
        for (int i = 0; i < lists.size(); ++i)
        {
            pointer = lists[i];
            while (pointer)
            {
                temp.push_back(pointer->val);
                pointer = pointer->next;
            }
        }
        if (0 == temp.size())
            return NULL;
        sort(temp.begin(), temp.end());
        ListNode* head = new ListNode(temp[0]);
        pointer = head;
        for (int i = 1; i < temp.size(); ++i)
        {
            ListNode* node = new ListNode(temp[i]);
            pointer->next = node;
            pointer = node;
        }
        return head;
    }
};


int main()
{

    ListNode* head1 = new ListNode(1);
    ListNode* tail  = head1;
    for (int i = 3; i <10; i = i+2)
    {
        ListNode* temp = new ListNode(i);
        tail->next = temp;
        tail = temp;
    }
    ListNode* head2 = NULL;
    ListNode* head2 = new ListNode(2);
    tail = head2;
    for (int i = 4; i < 10; i = i+2)
    {
        ListNode* temp = new ListNode(i);
        tail->next = temp;
        tail = temp;
    }

    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);


    Solution s;
    ListNode* head = s.mergeKLists(lists);
    
    ListNode* pointer = head;
    while (pointer)
    {
        cout<<pointer->val<<" ";
        pointer = pointer->next;
    }
    cout<<endl;

    return 0;
}
