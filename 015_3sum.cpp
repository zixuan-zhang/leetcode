/*******************************************************************************
 *  @File  : 015_3sum.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月15日 星期四 09时41分38秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},
 *
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 *
 */

#if defined(__GNUC__) 
#if __GNUC__ < 3 && __GNUC__ >= 2 && __GNUC_MINOR__ >= 95 
#include <hash_map> 
#elif __GNUC__ >= 3 
#include <ext/hash_map> 
    using namespace __gnu_cxx; 
#else 
#include <hash_map.h> 
#endif 
#elif defined(__MSVC_VER__) 
#if __MSVC_VER__ >= 7 
#include <hash_map> 
#else 
#error "std::hash_map is not available with this compiler" 
#endif 
#elif defined(__sgi__) 
#include <hash_map> 
#else 
#error "std::hash_map is not available with this compiler" 
#endif 

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
using namespace __gnu_cxx;

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > result; //存放结果 
        hash_map<int, int> num_map; //存放出现的数值
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
            num_map[nums[i]] = i;

        int temp;
        vector<int> group(3, 0);
        int i = 0, j = 1;
        while (i < nums.size())
        {
            j = i + 1;
            while (j < nums.size())
            {
                temp = 0 - nums[i] - nums[j];
                if (num_map.find(temp) != num_map.end() && num_map[temp] > j)
                {
                    group[0] = nums[i];
                    group[1] = nums[j];
                    group[2] = temp;
                    result.push_back(group);
                }
                j = num_map[nums[j]] + 1;
            }
            i = num_map[nums[i]] + 1;
        }
        return result;

    }
};

int main()
{
    Solution s;
    vector<int> S;
    S.push_back(-1);
    S.push_back(0);
    S.push_back(1);
    S.push_back(2);
    S.push_back(-1);
    S.push_back(-4);
    vector<vector<int> > res = s.threeSum(S);
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
