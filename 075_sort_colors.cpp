/*******************************************************************************
 *  @File  : 075_sort_colors.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年01月05日 星期二 21时56分02秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an array with n objects colored red, white or blue, sort them so
 * that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * click to show follow up.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 *
 */

#include <iostream>

using namespace std;


class Solution {
public:
    /*
     * Method: Apparently this is couting sort. I need to come up with another
     *  constant space method
     */
    void sortColors(vector<int>& nums) {
        int colors[3] = {0, 0, 0};
        for (int i = 0; i < nums.size(); ++i)
            colors[nums[i]] ++;
        int index = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < colors[i]; ++j)
            {
                nums[index++] = i;
            }
        }
    }
};

int main()
{
    return 0;
}
