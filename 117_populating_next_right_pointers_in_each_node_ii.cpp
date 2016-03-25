/*******************************************************************************
 *  @File  : 117_populating_next_right_pointers_in_each_node_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月25日 星期五 21时44分33秒
 ******************************************************************************/

/*
 * Question:
 *
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 * You may only use constant extra space.
 *
 */

#include <vector>
#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    };

class Solution {
public:
    void collect_left(TreeLinkNode* root, vector<vector<TreeLinkNode*> >& nodes, int step)
    {
        if (step == nodes.size())
        {
            vector<TreeLinkNode*> row;
            nodes.push_back(row);
        }
        nodes[step].push_back(root);
        if (root->right)
            collect_left(root->right, nodes, step+1);
        if (root->left)
            collect_left(root->left, nodes, step+1);
    }
    
    void collect_right(TreeLinkNode* root, vector<vector<TreeLinkNode*> >& nodes, int step)
    {
        if (step == nodes.size())
        {
            vector<TreeLinkNode*> row;
            nodes.push_back(row);
        }
        nodes[step].push_back(root);
        if (root->left)
            collect_right(root->left, nodes, step+1);
        if (root->right)
            collect_right(root->right, nodes, step+1);
    }

    void _connect(TreeLinkNode* root)
    {
        if (NULL == root->left || NULL == root->right)
            return;
        vector<vector<TreeLinkNode*> > leftNodes;
        vector<vector<TreeLinkNode*> > rightNodes;
        collect_left(root->left, leftNodes, 0);
        collect_right(root->right, rightNodes, 0);
        int step = 0;
        while (step < leftNodes.size() && step < rightNodes.size())
        {
            leftNodes[step][0]->next = rightNodes[step][0];
            step++;
        }
    }

    /*
     * Method 1
     */
    void connect(TreeLinkNode *root) {
        if (root)
            _connect(root);
    }

    void connect1(TreeLinkNode *root)
    {
        if (root)
        {
            TreeLinkNode *tempNode = new TreeLinkNode(0);
            TreeLinkNode *currentNode;
            while (root)
            {
                tempNode->next = NULL;
                currentNode = tempNode;
                while (root)
                {
                    if (root->left)
                    {
                        currentNode->next = root->left;
                        currentNode = currentNode->next;
                    }
                    if (root->right)
                    {
                        currentNode->next = root->right;
                        currentNode = currentNode->next;
                    }
                    root = root->next;
                }
                root = tempNode->next;
            }
        }
    }
    
};

int main()
{
    return 0;
}
