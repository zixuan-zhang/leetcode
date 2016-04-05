/*******************************************************************************
 *  @File  : 133_clone_graph.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 05 Apr 2016 08:46:18 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        unordered_map<int, UndirectedGraphNode*> newNodes;
        queue<UndirectedGraphNode*> openTable;
        if (NULL == node)
            return NULL;
        
        UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
        newNodes[node->label] = head;
        openTable.push(node);
        UndirectedGraphNode* current;
        UndirectedGraphNode* thatNode;
        while (!openTable.empty())
        {
            thatNode = openTable.front();
            openTable.pop();
            
            current = newNodes[thatNode->label];
            UndirectedGraphNode* neighbor = NULL;
            for (int i = 0; i < thatNode->neighbors.size(); ++i)
            {
                if (newNodes.find(thatNode->neighbors[i]->label) == newNodes.end())
                {
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(thatNode->neighbors[i]->label);
                    newNodes[thatNode->neighbors[i]->label] = newNode;
                    openTable.push(thatNode->neighbors[i]);
                }
                neighbor = newNodes.find(thatNode->neighbors[i]->label)->second;
                current->neighbors.push_back(neighbor);
            }
        }
        return head;
    }
};

void printGraph(UndirectedGraphNode* head)
{
    queue<UndirectedGraphNode*> openTable;
    openTable.push(head);
    unordered_set<UndirectedGraphNode*> closeTable;
    closeTable.insert(head);
    while (!openTable.empty())
    {
        UndirectedGraphNode* current = openTable.front();
        openTable.pop();
        cout<<current->label<<" : ";
        for (int i = 0; i < current->neighbors.size(); ++i)
        {
            cout<<current->neighbors[i]->label<<",";
            if (closeTable.find(current->neighbors[i]) == closeTable.end())
            {
                closeTable.insert(current->neighbors[i]);
                openTable.push(current->neighbors[i]);
            }
        }
        cout<<endl;
    }
}


int main()
{
    // construct graph
    UndirectedGraphNode* node0 = new UndirectedGraphNode(0);
    UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* node2 = new UndirectedGraphNode(2);

    node0->neighbors.push_back(node1);
    node0->neighbors.push_back(node2);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node2);

    //printGraph(node0);

    Solution s;
    UndirectedGraphNode* newNode = s.cloneGraph(node0);
    printGraph(newNode);

    return 0;
}
