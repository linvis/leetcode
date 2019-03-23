/*
 * File name: solu.cpp
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_n = 0;
        int tmp_n = 0;
        
        for (auto n : nums) {
            if (n) {
                tmp_n++;
            } else {
                tmp_n = 0;
            }
            max_n = max(max_n, tmp_n);
        }
        
        return max_n;
    }
};
