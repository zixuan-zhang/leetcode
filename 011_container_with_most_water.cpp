/*******************************************************************************
 *  @File  : 010_container_with_most_water.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月14日 星期三 16时47分04秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 * of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
 * forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int max = -1;
        for (int i = 0; i < height.size(); ++i)
        {
            for (int j = i + 1; j < height.size(); ++j)
            {
                int area = (j-i) * min(height[i], height[j]);
                if (max < area)
                    max = area;
            }
        }
        return area;
    }

    int maxArea(vector<int>& height)
    {
        int max = -1;
        int left = 0;
        int right = height.size() - 1;
        while (left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            if (max < area)
                max = area;
            if (height[left] < height[right])
                left ++;
            else
                right --;
        }
        return max;
    }
}
int main()
{
    return 0;
}
