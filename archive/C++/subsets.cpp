/*
 * Dynamic algorithm
 * equation: P(n + 1) = P(n) + A(n)
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sum;
        vector<int> empty = {};
        sum.push_back(empty); 
        for (int i = 0; i < nums.size(); i++) {
            int m = sum.size();
            for (int j = 0; j < m; j++) {
                vector<int> tmp = sum[j];
                tmp.push_back(nums[i]);
                sum.push_back(tmp);   
            }
        }
        return sum;
    }
};
