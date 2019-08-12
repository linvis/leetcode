
题目：找零钱， 从零钱coins = [1, 2, 5], amount = 11, 找出一个零钱数目最少的方案

思路：DP, S(N) = min(S[N - j] + 1), j is coin

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not amount: return 0
        if not coins: return -1
        
        dp = [0 for i in range(amount + 1)] 
        
        for i in range(amount + 1):
            if i in coins:
                dp[i] = 1
            else:
                if i < min(coins):continue
                dp[i] = min([dp[i - j] + 1 
                             if i >= j and dp[i - j] != 0 
                             else float("inf") 
                             for j in coins])
                
        if dp[amount] == 0 or dp[amount] == float('inf'):
            return -1
        else:
            return dp[amount]
               

