/*
 * File name: solu.cpp
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (r *c != nums.size() * nums[0].size())
            return nums;
        
        vector<vector<int>> B(r, vector<int>(c));
        
        int old_r = 0;
        int old_c = 0;
        
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j++) {
                B[i][j] = nums[old_r][old_c++];
                if (old_c >= nums[0].size()) {
                    old_r++;
                    old_c = 0;
                }
            }
        }
        
        return B;
    }
};
