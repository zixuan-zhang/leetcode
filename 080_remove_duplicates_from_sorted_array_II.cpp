/*******************************************************************************
 *  @File  : 080_remove_duplicates_from_sorted_array_II.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年01月06日 星期三 08时55分42秒
 ******************************************************************************/

/*
 * Question:
 *
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int length = 0;
        int pointer = 2;
        while (pointer < nums.size())
        {
            if (nums[pointer] != nums[pointer-2])
            {
                nums[length++] = nums[pointer-2];
            }
                
            pointer++;
        }
        nums[length++] = nums[pointer-2];
        nums[length++] = nums[pointer-1];
        return length;
    }
};

int main()
{
    return 0;
}
