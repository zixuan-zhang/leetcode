/*******************************************************************************
 *  @File  : 122_best_time_to_buy_and_sell_stock_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月27日 星期日 22时27分59秒
 ******************************************************************************/

/*
 * Question:
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock multiple
 * times). However, you may not engage in multiple transactions at the same time
 * (ie, you must sell the stock before you buy again).
 *
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int end = 0;
        while (end < prices.size())
        {
            int minPrice = prices[end++];
            while (end < prices.size() && minPrice > prices[end])
                minPrice = prices[end++];
            if (end == prices.size())
                break;
            while (end+1 < prices.size() && prices[end] < prices[end+1])
                end++;
            maxProfit += (prices[end++] - minPrice);
        }
        return maxProfit;
    }
};
