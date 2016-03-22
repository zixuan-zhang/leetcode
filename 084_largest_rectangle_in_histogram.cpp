/*******************************************************************************
 *  @File  : 084_largest_rectangle_in_histogram.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月22日 星期二 17时02分59秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 */

class Solution {
public:
    int largestArea(vector<int>& heights, int start, int end)
    {
        if (start > end)
            return 0;
        if (start == end)
            return heights[start];
        int minHeight = heights[start];
        int minIndex = start;
        bool sorted = true;
        for (int i = start+1; i <= end; ++i)
        {
            if (heights[i] < heights[i-1])
                sorted = false;
            if (minHeight > heights[i])
            {
                minHeight = heights[i];
                minIndex = i;
            }
        }
        if (sorted)
        {
            int _max = 0;
            for (int i = start; i <= end; i++) {
                _max = max(_max, heights[i] * (end - i + 1));
            }
            return _max;
        }
        int maxArea = (end-start+1) * minHeight;
        int leftIndex = minIndex-1;
        while (start <= leftIndex && heights[leftIndex] == heights[minIndex])
            leftIndex--;
        int rightIndex = minIndex+1;
        while (rightIndex <= end && heights[rightIndex] == heights[minIndex])
            rightIndex++;
        int leftArea = largestArea(heights, start, leftIndex);
        int rightArea = largestArea(heights, rightIndex, end);
        maxArea = max(maxArea, leftArea);
        maxArea = max(maxArea, rightArea);
        return maxArea;
    }

    /*
     * Method1: O(n*logn) complecity
     */
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;
        int area = largestArea(heights, 0, heights.size()-1);
        return area;
    }

    /*
     * Method2: O(n^2) complecity
     */
    int largestRectangleArea1(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;
        int start = 0;
        int end = heights.size()-1;
        int area = INT_MIN;
        while (start <= end)
        {
            int height = heights[start];
            for (int i = start+1; i <= end; ++i)
                height = min(height, heights[i]);
            area = max(area, height*(end-start+1));
            if (start == end)
                break;
            if (heights[start] < heights[end])
                start++;
            else
                end--;
        }
        return area;
    }
};
