/*******************************************************************************
 *  @File  : 096_unique_binary_search_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月20日 星期日 20时57分57秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 */

class Solution {
public:
    int count(vector<int>& nums, vector<int>::iterator begin, vector<int>::iterator end,
            vector<int>& cnts)
    {
        int result = 0;
        for (vector<int>::iterator it = begin; it <= end; ++it)
        {
            it - 1;
            int left, right;
            if (it-begin <= 1)
                left = 1;
            else if (cnts[it-begin] != -1)
                left = cnts[it-begin];
            else
                left = count(nums, begin, it-1, cnts);

            if (end-it <= 1)
                right = 1;
            else if (cnts[end-it] != -1)
                right = cnts[end-it];
            else
                right = count(nums, it+1, end, cnts);
            result += left * right;
        }
        cnts[end-begin+1] = result;
        return result;
    }
    int numTrees(int n) {
        if (n < 1)
            return 0;
        vector<int> cnts(n+1, -1);
        cnts[0] = 1;
        cnts[1] = 1;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            nums[i] = i;
        int result = count(nums, nums.begin(), nums.end()-1, cnts);
        return result;
    }
};
