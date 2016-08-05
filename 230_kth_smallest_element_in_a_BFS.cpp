/*******************************************************************************
 *  @File  : 230_kth_smallest_element_in_a_BFS.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 05 Aug 2016 12:10:44 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 *
 *
 */

#include <iostream>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode* root, int k) {
        int visited = 0;
        stack<TreeNode*> elements;
        TreeNode* pointer = root;
        while (pointer)
        {
            elements.push(pointer);
            pointer = pointer->left;
        }
        while (!elements.empty())
        {
            pointer = elements.top();
            elements.pop();
            visited++;
            if (visited == k)
                return pointer->val;
            pointer = pointer->right;
            while (pointer)
            {
                elements.push(pointer);
                pointer = pointer->left;
            }
        }
    }
};

int main()
{
    return 0;
}
