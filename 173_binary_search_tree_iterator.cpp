/*******************************************************************************
 *  @File  : 173_binary_search_tree_iterator.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 09 Jul 2016 03:08:56 PM CST
 ******************************************************************************/

/*
 * Question;
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h)
 * memory, where h is the height of the tree.
 *
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

/*
 * BSTIterator will be called like this:
 *  BSTIterator i = BSTIterator(root);
 *  while (i.hasNext())
 *      cout<<i.next();
 *
 */
class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        this->root = root;
        TreeNode* pointer = root;
        while (pointer != NULL)
        {
            s.push(pointer);
            pointer = pointer->left;
        }
    }

    /** @return whether we have a next smallest number **/
    bool hasNext()
    {
        return !s.empty();
    }

    /** @return tehe next smallest number **/
    int next()
    {
        TreeNode* pointer = s.top();
        s.pop();
        int value = pointer->val;
        pointer = pointer->right;
        while (pointer != NULL)
        {
            s.push(pointer);
            pointer = pointer->left;
        }
        return value;
    }

    void show()
    {
        TreeNode* pointer = root;
        while (!s.empty() || NULL != pointer)
        {
            while (pointer != NULL)
            {
                s.push(pointer);
                pointer = pointer->left;
            }

            if (!s.empty())
            {
                pointer = s.top();
                s.pop();
                cout<<pointer->val<<endl;
                pointer = pointer->right;
            }
        }
    }

private:
    TreeNode* root;
    stack<TreeNode*> s;
};

int main()
{
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);

    node5->left = node3;
    node5->right = node6;
    node3->left = node2;
    node3->right = node4;
    node6->right = node7;
    node7->right = node8;

    BSTIterator i(node5);
    while (i.hasNext())
        cout<<i.next()<<endl;

    return 0;
}
