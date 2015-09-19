/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (NULL == l1 && NULL == l2)
            return NULL;
        if (NULL == l1)
            return l2;
        if (NULL == l2)
            return l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* newHeader = NULL;
        ListNode* pointer = newHeader;

        int remainder = 0;
        int number;
        while (p1 && p2)
        {
            number = (p1->val + p2->val + remainder) % 10;
            remainder = (p1->val + p2->val + remainder) / 10;

            if (newHeader == NULL)
            {
                newHeader = new ListNode(number);
                pointer = newHeader;
            }
            else
            {
                ListNode* temp = new ListNode(number);
                pointer->next = temp;
                pointer = pointer->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1)
        {
            number = (p1->val + remainder) % 10;
            remainder = (p1->val + remainder ) / 10;
            ListNode* temp = new ListNode(number);
            pointer->next = temp;
            pointer = pointer->next;
            p1 = p1->next;
        }
        while (p2)
        {
            number = (p2->val + remainder) % 10;
            remainder = (p2->val + remainder) / 10;
            ListNode* temp = new ListNode(number);
            pointer->next = temp;
            pointer = pointer->next;
            p2 = p2->next;
        }

        if (remainder)
        {
            ListNode* temp = new ListNode(1);
            pointer->next = temp;
        }
        return newHeader;
    }
};

ListNode* l1 = NULL;
ListNode* l2 = NULL;

void init(vector<int> num1, vector<int> num2)
{
    ListNode* p1;
    ListNode* p2;
    for (int i = 0; i < num1.size(); ++i)
    {
        if (NULL == l1)
        {
            l1 = new ListNode(num1[i]);
            p1 = l1;
        }
        else
        {
            ListNode* temp = new ListNode(num1[i]);
            p1->next = temp;
            p1 = p1->next;
        }
    }

    for (int i = 0; i < num2.size(); ++i)
    {
        if (NULL == l2)
        {
            l2 = new ListNode(num2[i]);
            p2 = l2;
        }
        else
        {
            ListNode* temp = new ListNode(num2[i]);
            p2->next = temp;
            p2 = p2->next;
        }
    }
};

int main()
{
    vector<int> num1, num2;
    num1.push_back(1);
    num1.push_back(8);
    num2.push_back(0);
    init(num1, num2);

    Solution s;
    ListNode* header = s.addTwoNumbers(l1, l2);
    ListNode* p = header;
    while (p)
    {
        cout<<p->val<<" ";
        p = p->next;
    }

    return 0;
}
