/*
 *Brute force
 *Time: Max O(n)
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int i;
        if (len == 0) 
            return -1;
        if (len == 1)
            return nums.at(0) == target ? 0 : -1;
        
        if (target < nums.at(0)) {
            for (i = len - 1; i > 0 && nums.at(i - 1) < nums.at(i); i--) {
                if (target == nums.at(i))
                    return i;
            }
            if (target == nums.at(i))
                return i;
            return -1;
        } else {
            for (i = 0; i < (len - 1) && nums.at(i) < nums.at(i + 1); i++) {
                if (target == nums.at(i))
                    return i;
            }
            if (target == nums.at(i))
                return i;
            return -1;
        }
    }
};
