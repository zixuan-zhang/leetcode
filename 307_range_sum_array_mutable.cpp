/*******************************************************************************
 *  @File  : 307_range_sum_array_mutable.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 29 Jul 2016 06:20:52 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * The update(i, val) function modifies nums by updating the element at index i to val.
 * Example:
 * Given nums = [1, 3, 5]
 *
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * Note:
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is distributed evenly.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeNode
{
    int start;
    int end;
    int sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;

    SegmentTreeNode(int s, int e) : start(s), end(e), sum(0), left(NULL), right(NULL) {};
};


class NumArray {
public:
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end)
    {
        SegmentTreeNode* node = new SegmentTreeNode(start, end);
        if (start == end)
        {
            node->sum = nums[start];
        }
        else
        {
            int mid = (start + end) / 2;
            SegmentTreeNode* left = buildTree(nums, start, mid);
            SegmentTreeNode* right = buildTree(nums, mid+1, end);
            node->sum = left->sum + right->sum;
            node->left = left;
            node->right = right;
        }
        return node;
    }

    NumArray(vector<int> &nums) {
        if (nums.size() == 0)
            last = -1;
        else
        {
            root = buildTree(nums, 0, nums.size() - 1);
            last = nums.size() - 1;
        }
    }

    void _update(SegmentTreeNode* node, int i, int val)
    {
        if (node->start == i && node->end == i)
        {
            node->sum = val;
        }
        else
        {
            int mid = (node->start + node->end) / 2;
            if (i <= mid)
                _update(node->left, i, val);
            else
                _update(node->right, i, val);
            node->sum = node->left->sum + node->right->sum;
        }
    }

    void update(int i, int val) {
        if (i <= last)
            _update(root, i, val);
    }

    int _sum(SegmentTreeNode* node, int i, int j)
    {
        if (node->start == i && node->end == j)
            return node->sum;
        int mid = (node->start + node->end) / 2;
        if (j <= mid)
            return _sum(node->left, i, j);
        else if (i > mid)
            return _sum(node->right, i, j);
        else
        {
            return _sum(node->left, i, mid) + _sum(node->right, mid+1, j);
        }
    }

    int sumRange(int i, int j) {
        if (i > j)
            return 0;
        if (last == -1)
            return 0;
        if (i < 0)
            i = 0;
        if (j > last)
            j = last;
        
        return _sum(root, i, j);
    }

private:
    SegmentTreeNode* root;
    int last;
};

int main()
{
    int array[] = {1, 3, 5};
    vector<int> nums;
    for (int i = 0; i < sizeof(array)/sizeof(int); ++i)
    {
        nums.push_back(array[i]);
    }

    NumArray numArray(nums);
    cout<<numArray.sumRange(0, 2)<<endl;
    cout<<numArray.sumRange(0, 1)<<endl;
    numArray.update(1, 2);
    cout<<numArray.sumRange(0, 2)<<endl;
    return 0;
}
