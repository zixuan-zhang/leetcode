/*******************************************************************************
 *  @File  : 326_power_of_three.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月20日 星期日 21时05分44秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Follow up:
 * Could you do it without using any loop / recursion?
 *
 */


class Solution {
public:
    bool isPowerOfThree(int n) {
        int count = 0;
        int maxCount = 19;
        int base = 1;
        while (count <= 19)
        {
            if (base == n)
                return true;
            if (base > n)
                return false;
            base *= 3;
            count += 1;
        }
        return false;
    }
};
