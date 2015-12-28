/*******************************************************************************
 *  @File  : 056_merge_intervals.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Mon 28 Dec 2015 02:54:31 PM CST
 ******************************************************************************/

/*
 *
 * Question:
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comp_start(Interval i1, Interval i2)
{
    return i1.start < i2.start;
}


class Solution
{
public:
    /*
     * Method: 其实主要就是在merge前先排了个序。其他的都没啥。
     *          另外，本来打算在原地址进行直接merge的，这个时候
     *          就需要涉及erase.发现如果这样的话会有大量的地址
     *          清理工作，会消耗大量时间，也就是会产生TLE错误。
     *          所以，之后又改成了新申请空间进行
     *
     */
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result;
        if (intervals.size() < 1)
            return result;
        sort(intervals.begin(), intervals.end(), comp_start);

        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start >= result[result.size()-1].start &&
                    intervals[i].start <= result[result.size()-1].end)
            {
                if (intervals[i].end > result[result.size()-1].end)
                    result[result.size()-1].end = intervals[i].end;
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }

};

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 4));
    intervals.push_back(Interval(0, 0));
    //intervals.push_back(Interval(1, 3));
    //intervals.push_back(Interval(15, 18));

    Solution s;
    vector<Interval> result = s.merge(intervals);
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i].start<<","<<result[i].end<<endl;

    return 0;
}
