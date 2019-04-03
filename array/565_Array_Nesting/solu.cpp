/*
 * File name: solu.cpp
 */

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                continue;
            int tmp = i, tmp_count = 0;
            while (nums[tmp] >= 0) {
                tmp_count++;
                nums[tmp] = -nums[tmp] - 1;
                tmp = -nums[tmp] - 1;
            }
            count = max(count, tmp_count);
        }
        return count;
    }
};
