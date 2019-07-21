
#  题目：给定一个n，表示二叉树的节点，求有多少种不同的二叉树结构

#  思路：动态规划
#  对于第n个节点来说，它可能的结构有，左子树是n-1, 右子树是0，左子树是n-2，右子树是1...
#  同时，由于对称关系的存在，要乘以2，遍历的终点是，当左子树等于右子树的时候，二叉树对称，不需要乘以2，
#  当左子树小于右子树，结束循环

class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1

        for i in range(1, n + 1):
            
            for j in range(i - 1, 0, -1):
                if j > i - 1 - j:
                    dp[i] += dp[j] * dp[i - 1 - j] * 2
                elif j == i - 1 - j:
                    dp[i] += dp[j] * dp[i - 1 - j]
                else:
                    continue
                    
        return dp[n]
