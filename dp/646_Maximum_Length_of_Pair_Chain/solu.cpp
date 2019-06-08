/*
 * File name: solu.cpp
 */

// 非常沮丧，做不出来

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp(pairs.size(), 1);
        
        sort(pairs.begin(), pairs.end(), [](vector<int>a, vector<int>b){return a[0] < b[0];});
        
        for (int i = 0; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
