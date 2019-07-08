/*
 * File name: solu.cpp
 */

// max  Sum[i] windows[X] Sum[i + X]
// 10% fast, 100% memory less

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int dp[customers.size()][2];
        int max_sum = 0;
        int m = customers.size();
        
        if (X >= m) {
            return accumulate(customers.begin(), customers.end(), 0); 
        }
        
        for (int i = 0; i < m; i++) {
            if (i <= 0) {
                dp[i][0] = 0 + customers[i] *  (1 - grumpy[i]);  
            } else {
                dp[i][0] = dp[i - 1][0] + customers[i] * (1 - grumpy[i]);  
            }
        }
        
        for (int i = m - 1; i >= 0; i--) {
            if (i >= m - 1) {
                dp[i][1] = 0 + customers[i] * (1 - grumpy[i]);  
            } else {
                dp[i][1] = dp[i + 1][1] + customers[i] * (1 - grumpy[i]);  
            }
        }
        
        for (int i = 0; i <= m - X; i++) {
            int sum = 0;
            int tmp = 0;
            int left = 0, right = 0;
            for (int j = i; j < i + X && j < m; j++) {
                tmp += customers[j];
            }
            
            if (i == 0) {
                left = 0;
                right = dp[i + X][1];
            } else if (i == m - X) {
                left = dp[i - 1][0]; 
                right = 0;
            } else {
                left = dp[i - 1][0]; 
                right = dp[i + X][1];
            }
            
            sum = left + tmp + right; 
            
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        
        return max_sum;
        
    }
};
