/*******************************************************************************
 *  @File  : 041_trapping_rain_water.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年12月01日 星期二 18时46分28秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int result = 0;
        if (height.size() <= 2)
            return result;
        
        int max = 0;
        int start= 0;
        for (int i = 1; i < height.size(); ++i)
        {
            if (height[i] >= height[start])
            {
                for (int j = start; j < i; ++j)
                    max += (height[start] - height[j]);
                start = i; //update start
            }
        }
        if (start < height.size() - 2)
        {
            int end = height.size() - 1;
            for (int i = height.size() - 1; i >= start; --i)
            {
                if (height[i] >= height[end])
                {
                    for (int j = end; j > i; --j)
                        max += (height[end] - height[j]);
                    end = i;
                }
            }
        }
        return max;
        
    }
};

int main()
{
    int numbers[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height(12);
    for (int i = 0; i < 12; ++i)
        height[i] = numbers[i];

    Solution s;
    int result = s.trap(height);
    cout<<result<<endl;
    return 0;
}
