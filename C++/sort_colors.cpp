class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> tmp(nums.size(), 1);
        int m = 0, n = nums.size() - 1;
        for (int i =  0 ; i < nums.size(); i++) {
            if (nums[i] == 0)
                tmp[m++] = 0;
            if (nums[i] == 2)
                tmp[n--] = 2;            
        }
        for (int i =  0 ; i < nums.size(); i++)
            nums[i] = tmp[i];
    }
};
