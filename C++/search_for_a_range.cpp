/*
 *Time: O(logn)
 *Brief: Binary Search
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int li = 0;
        int hi = nums.size() - 1;
        int mid = (li + hi) / 2;
        
        if (nums.size() == 0) {
            return {-1, -1};
        }
        
        while (li <= mid) {
            if (li == mid) {
                if (target == nums.at(li)) {
                    int l = li, r = li;
                    while(--l >= 0 && nums.at(l) == target);
                    while(++r <= hi && nums.at(r) == target);
                    return {l + 1, r - 1};
                }else if (target == nums.at(hi)) {
                    int l = hi, r = hi;
                    while(--l >= 0 && nums.at(l) == target);
                    while(++r <= hi && nums.at(r) == target);
                    return {l + 1, r - 1};
                } else {
                    return {-1, -1};
                }
            }

            if (target == nums.at(mid)) {
                int l = mid, r = mid;
                while(--l >= 0 && nums.at(l) == target);
                while(++r <= hi && nums.at(r) == target);
                return {l + 1, r - 1};
            } else if (target < nums.at(mid)) {
                hi = mid;
            } else {
                li = mid;
            }
            mid = (li + hi) / 2;
        }
        return {-1, -1};
    }
};
