/*******************************************************************************
 *  @File  : 341_flatten_nested_list_iterator.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Mon 20 Jun 2016 03:59:46 PM CST
 ******************************************************************************/

/*
 * Question:
 * Given a nested list of integers, implement an iterator to flatten it.
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 * By calling next repeatedly until hasNext returns false, the order of elements
 * returned by next should be: [1,1,2,1,1].
 * Example 2:
 * Given the list [1,[4,[6]]],
 * By calling next repeatedly until hasNext returns false, the order of
 * elements returned by next should be: [1,4,6].
 */

#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    vector<int> nums;
    int index = 0;
    void loadNums(vector<int>& result, NestedInteger nestedInteger)
    {
        if (nestedInteger.isInteger())
            result.push_back(nestedInteger.getInteger());
        else
        {
            vector<NestedInteger> subNestedInteger = nestedInteger.getList();
            for (int i = 0; i < subNestedInteger.size(); ++i)
            {
                loadNums(result, subNestedInteger[i]);
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        nums.clear();
        index = 0;
        for (int i = 0; i < nestedList.size(); ++i)
            loadNums(nums, nestedList[i]);
    }

    int next() {
        return nums[index++];
    }

    bool hasNext() {
        return index < nums.size();
    }
};

