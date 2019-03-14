/*
 * File name: solu.cpp
 */

这题的一个优化是i = i + 2
这样就可以只遍历一半

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                sum += nums[i];
        }
        
        return sum;
    }
};
