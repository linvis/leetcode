/*
 * File name: solu.cpp
 */

/*
 * 这题也没做出来，我试图写一个特别复杂的dp，
 * 使用一个二维的dp数组，存储中间变量
 * 
 * 试图算 F(i:j) = max(F(i-1:j), F(i:j)), F(i:j)又要算一堆
 * 
 * 忽视了本题的规则，基于事实问题
 * 对于prices里的每个元素，只有三种情况，买/卖/什么都不做
 * 
 * 买: cash - p，净利
 * 卖：净利 + p, 现金
 * 买卖导致现金变少，或者净利下降，就什么也不做
 *
 * 要分析具体题目里蕴含的规则!!!
 */


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = -prices[0], cash = 0;
        
        for (auto p : prices) {
            cash = max(cash, profit + p - fee);
            profit = max(profit, cash - p);
        }
        
        return cash;
    }
};
