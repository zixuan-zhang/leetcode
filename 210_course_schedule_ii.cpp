/*******************************************************************************
 *  @File  : 210_course_schedule_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 28 Jul 2016 09:59:54 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 * Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 * There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 *
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
 * 4, [[1,0],[2,0],[3,1],[3,2]]
 * There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 *
 */


#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<int> visited;
        stack<int> courses;
        unordered_map<int, unordered_set<int> > pres;
        unordered_map<int, unordered_set<int> > follows;

        // Initialize
        for (int i = 0; i < numCourses; ++i)
        {
            unordered_set<int> requisites;
            pres[i] = requisites;
            unordered_set<int> follow;
            follows[i] = follow;
        }

        for (int i = 0; i < prerequisites.size(); ++i)
        {
            pres[prerequisites[i].first].insert(prerequisites[i].second);
            follows[prerequisites[i].second].insert(prerequisites[i].first);
        }

        // Find items with no requisites
        for (unordered_map<int, unordered_set<int> >::iterator it = pres.begin(); it != pres.end(); ++it)
        {
            if (it->second.size() == 0)
                courses.push(it->first);
        }

        while (!courses.empty())
        {
            int course = courses.top();
            visited.push_back(course);
            courses.pop();
            
            unordered_set<int> follow = follows[course];
            for (auto item = follow.begin(); item != follow.end(); item++)
            {
                pres[*item].erase(course);
                if (pres[*item].size() == 0)
                    courses.push(*item);
            }
        }

        if (visited.size() == numCourses)
            return visited;
        else
            return vector<int>();
    }
};

int main()
{
    Solution s;
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(3, 1));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(2, 0));
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(1, 3));

    vector<int> result = s.findOrder(4, prerequisites);
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i]<<endl;

}
