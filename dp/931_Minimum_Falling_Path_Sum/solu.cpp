/*
 * File name: solu.cpp
 */

/*
 * a b c
 * d e f
 * g h i
 * 
 * min(d-h, e-h, f-h)即最小，就一层，不是维特比里的两层
 */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A[0].size();
        vector<int> sum(m, 0);
        
        for (int i = 0; i < A.size(); i++) {
            vector<int> tmp(m, 0);
            for (int j = 0; j < m; j++) {
                int best = sum[j] + A[i][j];
                if (j - 1 >=0) {
                    best = min(best, sum[j - 1] + A[i][j]);
                }
                if (j + 1 < m) {
                    best = min(best, sum[j + 1] + A[i][j]);
                }
                
                tmp[j] = best;
            }
            sum = tmp;
        }
        
        return *min_element(sum.begin(), sum.end());
    }
};
