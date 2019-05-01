/*
 *DP problem
 *A(m) = A(n) + k; (0 < k < nums[n])
 *
 *Time: O(n)
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int i = len - 1;
        for ( ; i >= 0; i--) {
            if (nums[i] < len - i - 1) {
                continue;
            } else {
                len = i + 1;
            }
        } 
        if (len == 1) {
            return true;
        } else {
            return false;
        }
    }
};
