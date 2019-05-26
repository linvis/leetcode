/*
 * File name: solu.cpp
 */

// 我这个不算是DP，我这是算出slice的长度，然后直接算出slice里的排列组合
// 虽然时间复杂度也是O(N), 但是多了一层循环，还是不如DP

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        
        vector<int> B(A.size(), 0);
        
        for (int i = 0; i < A.size() - 1; i++) {
            B[i] = A[i + 1] - A[i];
        }
        
        int i = 0;
        int sum = 0;
        for (int j = 1; j < B.size(); j++) {
            if (B[i] != B[j] || j == B.size() - 1) {
                int m = j - i + 1;
                if (m >= 3) {
                   sum += (m - 2) * (m - 1) / 2;
                }
                i = j;
                continue;
            } else {
                continue;
            }
        }
        
        return sum;
    }
};


// DP
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(A.size(), 0);
        
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
