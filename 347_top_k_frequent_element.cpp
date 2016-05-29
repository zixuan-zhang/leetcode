/*******************************************************************************
 *  @File  : 347_top_k_frequent_element.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 29 May 2016 05:07:44 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

struct Element
{
    int value;
    int count;
    Element(int v, int c) : value(v), count(c) {};
};

bool Compare(Element e1, Element e2)
{
    return e1.count > e2.count;
}

struct CompareClass
{
    bool operator() (Element e1, Element e2) { return (e1.count > e2.count);}
};

class Solution
{
public:
    /*
     * Most ordinary method. Just sort it. n*log(n) complecity.
     */
    vector<int> topFrequent(vector<int>& nums, int k)
    {
        vector<int> result;
        unordered_map<int, int> counts;
        for (auto value : nums)
        {
            if (counts.find(value) != counts.end())
                counts[value]++;
            else
                counts[value] = 1;
        }

        vector<Element> elements;
        for (auto element : counts)
            elements.push_back(Element(element.first, element.second));
        sort(elements.begin(), elements.end(), Compare);
        
        for (int i = 0; i < (elements.size() < k ? elements.size() : k); ++i)
            result.push_back(elements[i].value);
        return result;
    }

    /*
     * Heap Method. This actully is n*log(k) complecity. But in leetcode, it
     * is worse than the above one, confused about it.
     */
    vector<int> topFrequentWithHeap(vector<int>& nums, int k)
    {
        vector<int> result;
        unordered_map<int, int> counts;
        for (auto value : nums)
        {
            if (counts.find(value) != counts.end())
                counts[value]++;
            else
                counts[value] = 1;
        }
        //vector<Element> elements;
        //for (auto element : counts)
            //elements.push_back(Element(element.first, element.second));

        priority_queue<Element, vector<Element>, CompareClass> pqueue;
        for (auto element : counts)
        {
            pqueue.push(Element(element.first, element.second));
            if (pqueue.size() > k)
                pqueue.pop();
        }
        while (!pqueue.empty())
        {
            result.push_back(pqueue.top().value);
            pqueue.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    int array[] = {1, 3, 4, 4, 2, 3, 4, 4, 2, 3};
    vector<int> nums;
    for (auto num : array)
        nums.push_back(num);
    Solution s;
    //vector<int> result = s.topFrequent(nums, 1);
    vector<int> result = s.topFrequentWithHeap(nums, 3);
    for (auto value : result)
        cout<<value<<endl;
    return 0;
}
