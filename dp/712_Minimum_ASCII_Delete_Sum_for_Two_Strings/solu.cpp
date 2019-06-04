/*
 * File name: solu.cpp
 */

/*
 * 这题没做出来
 *
 * 'sea', 'eat'
 * 我的第一想法，是 min(s1[1:] + s2[:], s1[1:] + s2[1:], s1[:] + s2[1:])
 * 这是递归，是能算出来的，但是复杂度特别高
 * 
 * 然后我考虑了几种方案，都不行
 * 这里我陷入一个思维误区，我尝试从0-end的字符串解析方式，不管我怎么做，都会碰到递归
 * 
 * 然后答案是，从end-0反向解析，因为你想啊，F(i + 1, j + 1) = min(F(i, j), F(i + 1, j), F(i, j + 1))
 * 对不对，
 * 
 * 所以这里两条教训，如果发现是递归能解决，就反过来，DP一定要先算0，在算i + 1
 * 2. 二维dp的运用, 如果是倒序，二维dp也是倒序放置
 */

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int dp[s1.size() + 1][s2.size() + 1];
        
        memset(dp, 0, sizeof(dp));
        
        for (int i = s1.size() - 1; i >= 0; i--)
            dp[i][s2.size()] = dp[i + 1][s2.size()] + s1[i];
        
        for (int j = s2.size() - 1; j >= 0; j--)
            dp[s1.size()][j] = dp[s1.size()][j + 1] + s2[j];
        
        for (int i = s1.size() - 1; i >= 0; i--) {
            for (int j = s2.size() - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = min(dp[i+1][j] + s1[i], dp[i][j + 1] + s2[j]);
                }
            }
        }
        return dp[0][0];
    }
};
