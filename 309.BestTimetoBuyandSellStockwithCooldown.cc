// 309. Best Time to Buy and Sell Stock with Cooldown
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

#include "define.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rest = 0, hold = rest - prices[0], sold = hold + prices[0];
        //only an action a day (cd = 1)
        //hold => sell or rest, sold => rest, rest => buy or rest
        for(int i = 1; i < prices.size(); ++i)
        {
            int preSold = sold;
            sold = hold + prices[i];            //sold[i] = hold[i-1] + prices[i]
            hold = max(hold, rest - prices[i]); //hold[i] = max(hold[i-1], rest[i-1] - prices[i])
            rest = max(rest, preSold);          //rest[i] = max(rest[i-1], sold[i-1])
        }
        return max(sold, rest);
        // vector<int> profits(prices.size(), 0);
        // return maxProfit(prices, 0, profits);
    }
    int maxProfit(vector<int>& prices, int cur, vector<int>& profits) {
        int buypos = cur;
        int profit{};
        for (int i = cur + 1; i < prices.size(); ++i) {
            if (prices[i] > prices[buypos]) {
                if (i + 2 < profits.size() && profits[i + 2] == 0)
                    profits[i + 2] = maxProfit(prices, i + 2, profits);
                int nextprofit = i + 2 < profits.size() ? profits[i + 2] : 0;
                profit = max(profit, prices[i] - prices[buypos] + nextprofit);
            } else {
                buypos = i;
            }
        }
        return profit;
    }
};
