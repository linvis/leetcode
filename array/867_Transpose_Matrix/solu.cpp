/*
 * File name: solu.cpp
 */

// 矩阵转置，A[i][j] = A[j][i]

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> B(A[0].size(), vector<int>(A.size()));
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};
