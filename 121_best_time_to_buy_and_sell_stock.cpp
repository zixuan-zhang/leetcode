/*******************************************************************************
 *  @File  : 121_best_time_to_buy_and_sell_stock.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月27日 星期日 22时27分08秒
 ******************************************************************************/

/*
 * Question:
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one
 * and sell one share of the stock), design an algorithm to find the maximum profit.
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        vector<int> profits(prices.size(), 0);
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (minPrice > prices[i])
                minPrice = prices[i];
            profits[i] = prices[i] - minPrice;
            maxProfit = max(maxProfit, profits[i]);
        }
        return maxProfit;
    }
};
