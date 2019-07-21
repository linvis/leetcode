
#  题目：分个一个字符串，查找子串是否在一个列表里

#  思路：DP解，分割字符串 s[0:i] s[i:j]，以此判断s[0:j]是否能够被分割

class Solution:
    def wordBreak(self, s: str, wordDict):
        hash_table = dict([(word, 1) for word in wordDict])
        if not s:return True
        m = len(s)
        dp = [[0] * (m + 1) for _ in range(m + 1)]
        dp[0][0] = 1

        for i in range(0, len(s) + 1):
            for j in range(i + 1, len(s) + 1):
                if s[i:j] in hash_table:
                    dp[i][j] = 1 and dp[0][i]
                    if dp[i][j]:
                        dp[0][j] = 1
                        
        return dp[0][m]
