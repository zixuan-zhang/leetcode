/*******************************************************************************
 *  @File  : 057_insert_interval.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月29日 星期二 20时36分54秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
 */

#include <iostream>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    /*
     * Method:
     * 其中抓住关键点，就是找newInterval的start和end各处在什么位置。然后他们的位置
     * 可能有些特殊性。比如被包了，没有被包，然后再处理
     *
     */
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<Interval>::iterator sit;
        vector<Interval>::iterator eit;
        for (sit = intervals.begin(); sit != intervals.end(); ++sit)
        {
            if (sit->end >= newInterval.start)
                break;
        }
        for (eit = intervals.begin(); eit != intervals.end(); ++eit)
        {
            if (eit->end >= newInterval.end)
                break;
        }
        if (sit == intervals.end())
            intervals.push_back(newInterval);
        else
        {
            if (sit->start > newInterval.start)
            {
                if (eit == intervals.end())
                {
                    intervals.erase(sit, intervals.end());
                    intervals.push_back(newInterval);
                }
                else
                {
                    if (eit->start > newInterval.end)
                    {
                        sit = intervals.erase(sit, eit);
                        intervals.insert(sit, newInterval);
                    }
                    else
                    {
                        eit->start = newInterval.start;
                        intervals.erase(sit, eit);
                    }
                }
            }
            else
            {
                if (eit == intervals.end() || eit->start > newInterval.end)
                {
                    sit->end = newInterval.end;
                    intervals.erase(sit+1, eit);
                }
                else
                {
                    eit->start = sit->start;
                    intervals.erase(sit, eit);
                }
            }
        }

        return intervals;
    }
};
