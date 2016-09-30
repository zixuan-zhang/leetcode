/*******************************************************************************
 *  @File  : 303_range_sum_query.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 30 Sep 2016 02:56:50 PM CST
 ******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct RangeNode
{
    int start;
    int end;
    int sum;
    RangeNode* left;
    RangeNode* right;
    RangeNode(int start, int end, int sum) : start(start), end(end), sum(sum), left(NULL), right(NULL) {}
};

class NumArray
{
public:
    NumArray(vector<int>& nums)
    {
        root = buildRangeTree(nums, 0, nums.size()-1);
    }

    int sumRange(int i, int j)
    {
        if(i <= j)
            return getRange(root, i, j);
    }

private:
    RangeNode* root;
    RangeNode* buildRangeTree(vector<int>& nums, int start, int end)
    {
        RangeNode* node = NULL;
        if (start == end)
        {
            node = new RangeNode(start, end, nums[start]);
        }
        else if (start < end)
        {
            int mid = (start + end) / 2;
            RangeNode* left = buildRangeTree(nums, start, mid);
            RangeNode* right = buildRangeTree(nums, mid+1, end);
            node = new RangeNode(start, end, left->sum+right->sum);
            node->left = left;
            node->right = right;
        }
        return node;
    }

    int getRange(RangeNode* node, int start, int end)
    {
        if (NULL == node)
            return 0;
        if (node->start == start && node->end == end)
            return node->sum;
        int mid = (node->start+ node->end) / 2;
        if (end <= mid)
            return getRange(node->left, start, end);
        else if (start > mid)
            return getRange(node->right, start, end);
        else
            return getRange(node->left, start, mid) + getRange(node->right, mid+1, end);
    }
};

int main()
{
    vector<int> nums({-2, 0, 3, -5, 2, -1});
    NumArray numArray(nums);
    cout<<numArray.sumRange(0, 2);
    cout<<numArray.sumRange(2, 5);
    cout<<numArray.sumRange(0, 5);

    return 0;
}
