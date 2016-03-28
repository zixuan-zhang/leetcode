/*******************************************************************************
 *  @File  : 123_best_time_to_buy_and_sell_stock_iii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Mon 28 Mar 2016 09:44:10 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 *
 *
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int end = 0;
        while (end < prices.size())
        {
            int minPrice = prices[end++];
            while (end < prices.size() && minPrice >= prices[end])
                minPrice = prices[end++];
            if (end == prices.size())
                break;
            int subEnd = end;
            while (subEnd < prices.size())
            {
                while (subEnd+1 < prices.size() && prices[subEnd] < prices[subEnd+1])
                    subEnd++;
                int profit1 = (prices[subEnd] - minPrice);
                int subEnd2 = subEnd + 1;
                int profit2 = 0;
                int minPrice2 = INT_MAX;
                while (subEnd2 < prices.size())
                {
                    if (minPrice2 > prices[subEnd2])
                        minPrice2 = prices[subEnd2];
                    profit2 = max(profit2, prices[subEnd2] - minPrice2);
                    subEnd2++;
                }
                maxProfit = max(profit1+profit2, maxProfit);
                // find next subEnd
                int temp = prices[subEnd++];
                while (subEnd < prices.size() && prices[subEnd] < temp)
                    subEnd++;
            }
        }
        return maxProfit;
    }
};

int main()
{
    int array[13] = {3,5,2,7,8,6,3,10,8,20,5,12,3};
    vector<int> prices(13);
    for (int i = 0; i < 13; ++i)
        prices[i] = array[i];
    Solution s;
    int profit = s.maxProfit(prices);
    cout<<profit<<endl;
    return 0;
}
