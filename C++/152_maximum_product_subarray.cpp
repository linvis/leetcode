
/*
 * O(n2)
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_pro = 0;
        int tmp_pro;
        int count = 0;
        
        if (nums.size() == 1)
            return nums.at(0);
        
        for (int i = 0; i < nums.size(); i++) {
            tmp_pro = 1;
            for (int j = i; j >= 0; j--) {
                tmp_pro *= nums.at(j);
                max_pro = max(max_pro, tmp_pro);
            }
        }
        
        return max_pro;
    }
};
