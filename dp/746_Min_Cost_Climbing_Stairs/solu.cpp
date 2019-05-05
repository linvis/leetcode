/*
 * File name: solu.cpp
 */

/*
 * 这道题，我一直想错了状态转移方程
 * 刚开始试图用  minCost(cost) = minCost(cost[1:])
 * 这是错的，这只是递归，没有动态规划
 * 实际上，这是维特比算法的变形
 * F(n) = min)F(n - 2) + 走2步, F(n - 1) + 走1步)
 * 一个隐形马尔科夫链，F(n)只与前两种状态有关
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sum1 = 0, sum2 = 0;
        
        for (auto c : cost) {
            int sum = min(sum1 + c, sum2 + c);
            sum1 = sum2;
            sum2 = sum;
        }
        
        return min(sum1, sum2);
    }
};
